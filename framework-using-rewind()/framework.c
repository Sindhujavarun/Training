// create a framework.

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define DATA_FILE_NAME "framework.dat"

void createRecord();
void displayRecords();
void updateRecord();
void deleteRecord();

FILE *fpFields;

void main()
{  
  fpFields = fopen("fieldName.cfg", "r");
  char menuLine[100];
  int option;
  FILE *fpMenu;
  if(fpMenu == NULL)
  {
    printf("File creation failed\n");
    return;
  }
  do
  {
    system("cls");
    fpMenu = fopen("menu.cfg", "r");
    while(fgets(menuLine, 100, fpMenu))
    {
      menuLine[strlen(menuLine) - 1] = '\0';
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
  char fieldLine[100], fieldValue[20], status[20];
  fpData = fopen(DATA_FILE_NAME, "a");
  if(fpData == NULL)
  {
    printf("\nCan't open file or file doesn't exist. ");
    exit(0);
  }
  strcpy(status, "Activated");
  fwrite(&status, sizeof(status), 1, fpData);
  rewind(fpFields);
  while(fgets(fieldLine, 100, fpFields))
  {
    fieldLine[strlen(fieldLine) - 1] = '\0';
    printf("Please enter %s: ", fieldLine);
    scanf("%s", fieldValue);
    fwrite(fieldValue, sizeof(fieldValue), 1, fpData);
  }  
  printf("\nNew details successfully saved. \nEnter a key to continue. ");
  // printMenu();
  fclose(fpData);
  getch();
}

void displayRecords()
{
  printf("\nALL THE RECORDS\n");
  FILE *fpData;
  char fieldLine[100], fieldValue[20], status[20], status1[20];
  strcpy(status, "Activated");
  strcpy(status1, "Deactivated");
  fpData = fopen(DATA_FILE_NAME, "r");
  if(fpData == NULL)
  {
    printf("\nCan't open file or file doesn't exist. ");
    exit(0);
  }
  rewind(fpFields);
  while(fread(fieldValue, sizeof(fieldValue), 1, fpData))
  {
    if(strcmp(fieldValue, status) == 0 || strcmp(fieldValue, status1) == 0)
    {
      printf("status: ");
      printf("%s\n", fieldValue);
    }
    else
    {
      fgets(fieldLine, 100, fpFields);
      fieldLine[strlen(fieldLine) - 1] = '\0';
      printf("%s: %s\n", fieldLine, fieldValue);
      if(feof(fpFields))
      {
        printf("****************************\n");
        fseek(fpFields, 0, SEEK_SET);
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
  char fieldLine[100], fieldValue[20], tempFieldValue[20];
  fpData = fopen(DATA_FILE_NAME, "r+");
  if(fpData == NULL)
  {
    printf("\nCan't open file or file doesn't exist. ");
    exit(0);
  }
  rewind(fpFields);
  fgets(fieldLine, 20, fpFields);
  fieldLine[strlen(fieldLine) - 1] = '\0';
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
  char fieldLine[100], fieldValue[20], tempDeleteValue[20];
  fpData = fopen(DATA_FILE_NAME, "r+");
  if(fpData == NULL)
  {
    printf("\nCan't open file or file doesn't exist. ");
    exit(0);
  }
  rewind(fpFields);
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