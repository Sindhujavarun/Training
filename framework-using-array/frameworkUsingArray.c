// create a framework.

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define DATA_FILE_NAME "framework2.dat"

void createRecord();
void displayRecords();
void updateRecord();
void deleteRecord();

FILE *fpFields;
char fieldLine[50][100];
int fieldCount;

void main()
{  
	int option;
	do
	{
	fpFields = fopen("fieldName1.cfg", "r");
	char menuLine[100];
	int counter = 0;
	FILE *fpMenu;
	if(fpMenu == NULL)
	{
	printf("File creation failed\n");
	return;
	}
	system("cls");
	while(fgets(fieldLine[counter], 100, fpFields))
	{
		fieldLine[counter][strlen(fieldLine[counter]) - 1] = '\0';
		counter++;
	}
	fieldCount = counter;
	fpMenu = fopen("menu1.cfg", "r");
	while(fgets(menuLine, 100, fpMenu))
	{
	  printf("%s\n", menuLine);
	}
	printf("\nPlease enter your option: ");
	scanf("%d", &option);
	switch(option)
	{
	  case 1: createRecord();
	  break;
	  case 2: displayRecords();
	  break;
	  case 3: updateRecord();
	  break;
	  case 4: deleteRecord();
	  break;
	  case 5: exit(0);
	  break;
	  default: printf("\nEnter a valid option!!");
	  break;
	  getch();
	}
    fclose(fpMenu);
  }while(option != 5);
fclose(fpFields);
}

void createRecord()
{
  printf("\nNEW ENTRY\n");
  FILE *fpData;
  char fieldValue[20], status[20];
  int counter = 0;
  fpData = fopen(DATA_FILE_NAME, "a");
  if(fpData == NULL)
  {
    printf("\nCan't open file or file doesn't exist. ");
    exit(0);
  }
  strcpy(status, "Activated");
  fwrite(&status, sizeof(status), 1, fpData);
  while(counter < fieldCount)
  {
    printf("Please enter %s: ", fieldLine[counter]);
    scanf("%s", fieldValue);
    fwrite(fieldValue, sizeof(fieldValue), 1, fpData);
    counter++;
  }  
  printf("\nNew details successfully saved. \nEnter a key to continue. ");
  fclose(fpData);
  getch();
}

void displayRecords()
{
  printf("\nALL THE RECORDS\n");
  FILE *fpData;
  char fieldValue[20], status[20], status1[20];
  int counter = 0;
  strcpy(status, "Activated");
  strcpy(status1, "Deactivated");
  fpData = fopen(DATA_FILE_NAME, "r");
  if(fpData == NULL)
  {
    printf("\nCan't open file or file doesn't exist. ");
    exit(0);
  }
  while(fread(fieldValue, sizeof(fieldValue), 1, fpData))
  {
    if(strcmp(fieldValue, status) == 0 || strcmp(fieldValue, status1) == 0)
    {
      printf("status: ");
      printf("%s\n", fieldValue);
    }
    else
    {
      fgets(fieldLine[counter], 100, fpFields);
      printf("%s: %s\n", fieldLine[counter], fieldValue);
      counter++;
      if(counter == fieldCount)
      {
        printf("****************************\n");
        counter = 0;
      }
    }
  }
  printf("\nEnter a key to continue.");
  fclose(fpData);
  getch();
}

void updateRecord()
{
  FILE *fpData;
  char fieldValue[20], tempFieldValue[20];
  fpData = fopen(DATA_FILE_NAME, "r+");
  if(fpData == NULL)
  {
    printf("\nCan't open file or file doesn't exist. ");
    exit(0);
  }
  printf("\nEnter the ID to update the details: ");
  scanf("%s", tempFieldValue);
  while(fread(fieldValue, sizeof(fieldValue), 1, fpData))
  {
    if(strcmp(tempFieldValue, fieldValue) == 0)
    {
      fseek(fpData, 20, SEEK_CUR);
      fread(fieldValue, sizeof(fieldValue), 1, fpData);
      printf("Change %s to: ", fieldValue);
      scanf("%s", fieldValue);
      fseek(fpData, -20, SEEK_CUR);
      fwrite(fieldValue, sizeof(fieldValue), 1, fpData);
      printf("\nDetails successfully updated. \n");
      break;
    }
  }
  printf("\nEnter a key to continue.");
  fclose(fpData);
  getch();
}

void deleteRecord()
{
  FILE *fpData;
  char fieldValue[20], tempDeleteValue[20];
  fpData = fopen(DATA_FILE_NAME, "r+");
  if(fpData == NULL)
  {
    printf("\nCan't open file or file doesn't exist. ");
    exit(0);
  }
  printf("\nEnter the ID to delete the details: ");
  scanf("%s", tempDeleteValue);
  while(fread(fieldValue, sizeof(fieldValue), 1, fpData))
  {
    if(strcmp(tempDeleteValue, fieldValue) == 0)
    {
      fseek(fpData, -40, SEEK_CUR);
      fread(fieldValue, sizeof(fieldValue), 1, fpData);
      printf("Enter the status as Deactivated: ", fieldValue);
      scanf("%s", fieldValue);
      fseek(fpData, -20, SEEK_CUR);
      fwrite(fieldValue, sizeof(fieldValue), 1, fpData);
      printf("\nDetails deactivated successfully. \n");
      break;
    }
  }
  printf("\nEnter a key to continue.");
  fclose(fpData);
  getch();
}