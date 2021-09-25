// create new student details, modify or delete from existing student details and display all student details.

#include<stdio.h>
#include <stdlib.h>
#define FILE_NAME "detailsOfStudent.dat"
void createStudent();
void showStudents();
void deleteStudent();
void updateStudent();
struct Student
{
  int rollNumber;
  char studentName[20];
  float percentage;
  char status;
};

FILE *fpStudent;

int main()
{
	int option;
	do
	{
		printf("\nSTUDENT DETAILS");
		printf("\n-------------------");
		printf("\n1. Create new student details ");
		printf("\n2. Show all student details ");
		printf("\n3. Delete a student details ");
		printf("\n4. Update a student details ");
		printf("\n5. Exit");
		printf("\n-------------------");
		printf("\nPlease enter your option: ");
		scanf("%d", &option);
		switch(option)
		{
			case 1: createStudent();
			break;
			case 2: showStudents();
			break;
			case 3: deleteStudent();
			break;
			case 4: updateStudent();
			break;
			case 5: ;
			break;
			default: printf("\nEnter a valid option!!");
			break;
			getch();
		}
	}while(option != 5);
}

void createStudent()
{
	printf("\nNEW STUDENT DETAILS");
	struct Student student;
	char studentName[10];
	printf("\nEnter Roll Number of the student: ");
	scanf("%d", &student.rollNumber);
	printf("Enter Name of the student: ");
	scanf("%s", student.studentName);
	printf("Enter percentage of the student: ");
	scanf("%f", &student.percentage);	
	student.status = 'A';
	fpStudent = fopen(FILE_NAME, "a");
	if(fpStudent == NULL)
	{
		printf("\nCan't open file or file doesn't exist. ");
		return;
	}
	fwrite(&student, sizeof(student), 1, fpStudent);
	fclose(fpStudent);
	printf("\nStudent details successfully saved. \n");
	printf("Roll Number of the student: %d\n", student.rollNumber);
	printf("Name of the student: %s\n", student.studentName);
	printf("Percentage of the student: %.2f%%\n", student.percentage);
	getch();
}
void showStudents()
{
	struct Student student;
	char studentName[10];
	fpStudent = fopen(FILE_NAME, "r");
	if(fpStudent == NULL)
	{
		printf("\nCan't open file or file doesn't exist.");
		return;
	}
	while(fread(&student, sizeof(student), 1, fpStudent))
	{
		if(student.status == 'A')
		{
			printf("\nRoll number of the student: %d\n", student.rollNumber);
			printf("Name of the student: %s\n", student.studentName);
			printf("Percentage: %.2f%%\n", student.percentage);	
		}	
	}
	fclose(fpStudent);
	getch();
}
void deleteStudent()
{
	struct Student student;
	int roll_Number;
	printf("\nEnter the roll number of the student to delete the details: ");
	scanf("%d", &roll_Number);	
	fpStudent = fopen(FILE_NAME, "r+");
	while(fread(&student, sizeof(student), 1, fpStudent))
	{
		if(student.rollNumber == roll_Number)
		{
			fseek(fpStudent, sizeof(student) * -1, SEEK_CUR);
			student.status = 'D';
			fwrite(&student, sizeof(student), 1, fpStudent);
			printf("\nDetails of the student with roll number %d is deleted. ", roll_Number);
			break;
		}
	}
	fclose(fpStudent);
}
void updateStudent()
{
	struct Student student;
	int roll_number;
	printf("\nEnter the roll number of the student to update the details: ");
	scanf("%d", &roll_number);
	fpStudent = fopen(FILE_NAME, "r+");
	while(fread(&student, sizeof(student), 1, fpStudent))
	{
		if(student.rollNumber == roll_number)
		{
			printf("\nEnter new percentage of the student: ");
			scanf("%f", &student.percentage);
			fseek(fpStudent, sizeof(student) * -1, SEEK_CUR);
			fwrite(&student, sizeof(student), 1, fpStudent);
			printf("\nDetails of the student with roll number %d is updated. ", roll_number);
			break;
		}
	}
	fclose(fpStudent);
}