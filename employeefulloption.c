// create new employee details, modify or delete from existing employee details and display all employee details.

#include<stdio.h>
#include <stdlib.h>
#define FILE_NAME "detailsOfEmployee.dat"
void createEmployee();
void showEmployee();
void deleteEmployee();
void updateEmployee();
struct Employee
{
  int employeeId;
  char employeeName[20], department[10];
  float employeeSalary;
  char status;
};

FILE *fpEmployee;

int main()
{
	int option;
	do
	{
		printf("\nEMPLOYEE DETAILS");
		printf("\n-------------------");
		printf("\n1. Create new employee details ");
		printf("\n2. Show all employee details ");
		printf("\n3. Delete a employee details ");
		printf("\n4. Update a employee details ");
		printf("\n5. Exit");
		printf("\n-------------------");
		printf("\nPlease enter your option: ");
		scanf("%d", &option);
		switch(option)
		{
			case 1: createEmployee();
			break;
			case 2: showEmployee();
			break;
			case 3: deleteEmployee();
			break;
			case 4: updateEmployee();
			break;
			case 5: ;
			break;
			default: printf("\nEnter a valid option!!");
			break;
			getch();
		}
	}while(option != 5);
}

void createEmployee()
{
	printf("\nNEW EMPLOYEE DETAILS");
	struct Employee employee;
	char employeeName[10];
	printf("\nEnter Employee ID of the employee: ");
	scanf("%d", &employee.employeeId);
	printf("Enter Name of the employee: ");
	scanf("%s", employee.employeeName);
	printf("Enter Department of the employee: ");
	scanf("%s", employee.department);
	printf("Enter the salary of the employee: ");
	scanf("%f", &employee.employeeSalary);	
	employee.status = 'A';
	fpEmployee = fopen(FILE_NAME, "a");
	if(fpEmployee == NULL)
	{
		printf("\nCan't open file or file doesn't exist. ");
		return;
	}
	fwrite(&employee, sizeof(employee), 1, fpEmployee);
	fclose(fpEmployee);
	printf("\nEmployee details successfully saved. \n");
	printf("Employee ID of the employee: %d\n", employee.employeeId);
	printf("Name of the employee: %s\n", employee.employeeName);
	printf("Department of the employee: %s\n", employee.department);
	printf("Salary of the employee: %.2f\n", employee.employeeSalary);
	getch();
}
void showEmployee()
{
	struct Employee employee;
	char employeeName[10];
	fpEmployee = fopen(FILE_NAME, "r");
	if(fpEmployee == NULL)
	{
		printf("\nCan't open file or file doesn't exist.");
		return;
	}
	while(fread(&employee, sizeof(employee), 1, fpEmployee))
	{
		if(employee.status == 'A')
		{
			printf("\nEmployee ID of the employee: %d\n", employee.employeeId);
			printf("Name of the employee: %s\n", employee.employeeName);
			printf("Department of the employee: %s\n", employee.department);
			printf("Salary of the employee: %.2f\n", employee.employeeSalary);
		}	
	}
	fclose(fpEmployee);
	getch();
}
void deleteEmployee()
{
	struct Employee employee;
	int employee_Id;
	printf("\nEnter the employee ID of the employee to delete the details: ");
	scanf("%d", &employee_Id);	
	fpEmployee = fopen(FILE_NAME, "r+");
	while(fread(&employee, sizeof(employee), 1, fpEmployee))
	{
		if(employee.employeeId == employee_Id)
		{
			fseek(fpEmployee, sizeof(employee) * -1, SEEK_CUR);
			employee.status = 'D';
			fwrite(&employee, sizeof(employee), 1, fpEmployee);
			printf("\nDetails of the employee with employee ID %d is deleted. ", employee_Id);
			break;
		}
	}
	fclose(fpEmployee);
}
void updateEmployee()
{
	struct Employee employee;
	int emp_Id;
	printf("\nEnter the employee ID of the employee to update the details: ");
	scanf("%d", &emp_Id);
	fpEmployee = fopen(FILE_NAME, "r+");
	while(fread(&employee, sizeof(employee), 1, fpEmployee))
	{
		if(employee.employeeId == emp_Id)
		{
			printf("\nEnter new salary of the employee: ");
			scanf("%f", &employee.employeeSalary);
			fseek(fpEmployee, sizeof(employee) * -1, SEEK_CUR);
			fwrite(&employee, sizeof(employee), 1, fpEmployee);
			printf("\nDetails of the employee with employee ID %d is updated. ", emp_Id);
			break;
		}
	}
	fclose(fpEmployee);
}