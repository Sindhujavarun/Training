// create new customer details, modify or delete from existing user details and display all customer details.

#include<stdio.h>
#include <stdlib.h>
#define FILE_NAME "detailsOfCustomer.dat"
void createCustomer();
void showCustomers();
void deleteCustomer();
void updateCustomer();
struct customer
{
  int accountNumber;
  char customerName[20];
  float accountBalance;
  char status;
};

FILE *fpCustomer;

int main()
{
	int option;
	do
	{
		printf("\nBANK CUSTOMERS");
		printf("\n-------------------");
		printf("\n1. Create new customer details ");
		printf("\n2. Show all customer details ");
		printf("\n3. Delete a customer details ");
		printf("\n4. Update a customer details ");
		printf("\n5. Exit");
		printf("\n-------------------");
		printf("\nPlease enter your option: ");
		scanf("%d", &option);
		switch(option)
		{
			case 1: createCustomer();
			break;
			case 2: showCustomers();
			break;
			case 3: deleteCustomer();
			break;
			case 4: updateCustomer();
			break;
			case 5: ;
			break;
			default: printf("\nEnter a valid option!!");
			break;
			getch();
		}
	}while(option != 5);
}

void createCustomer()
{
	printf("\nNEW CUSTOMER DETAILS");
	struct customer cust;
	char customerName[10];
	printf("\nEnter Account Number of the customer: ");
	scanf("%d", &cust.accountNumber);
	printf("Enter Name of the customer: ");
	scanf("%s", cust.customerName);
	printf("Enter Account balance of the customer: ");
	scanf("%f", &cust.accountBalance);	
	cust.status = 'A';
	fpCustomer = fopen(FILE_NAME, "a");
	if(fpCustomer == NULL)
	{
		printf("\nCan't open file or file doesn't exist. ");
		return;
	}
	fwrite(&cust, sizeof(cust), 1, fpCustomer);
	fclose(fpCustomer);
	printf("\nCustomer details successfully saved. \n");
	printf("AccountNumber of the customer: %d\n", cust.accountNumber);
	printf("Name of the customer: %s\n", cust.customerName);
	printf("Account balance: %.2f\n", cust.accountBalance);
	getch();
}
void showCustomers()
{
	struct customer cust;
	char customerName[10];
	fpCustomer = fopen(FILE_NAME, "r");
	if(fpCustomer == NULL)
	{
		printf("\nCan't open file or file doesn't exist.");
		return;
	}
	while(fread(&cust, sizeof(cust), 1, fpCustomer))
	{
		if(cust.status == 'A')
		{
			printf("\nAccount number of the customer: %d\n", cust.accountNumber);
			printf("Name of the customer: %s\n", cust.customerName);
			printf("Account balance: %.2f\n", cust.accountBalance);
		}	
	}
	fclose(fpCustomer);
	getch();
}
void deleteCustomer()
{
	struct customer cust;
	int accNumber;
	printf("\nEnter the account number of the customer to delete the details: ");
	scanf("%d", &accNumber);	
	fpCustomer = fopen(FILE_NAME, "r+");
	while(fread(&cust, sizeof(cust), 1, fpCustomer))
	{
		if(cust.accountNumber == accNumber)
		{
			fseek(fpCustomer, sizeof(cust) * -1, SEEK_CUR);
			cust.status = 'D';
			fwrite(&cust, sizeof(cust), 1, fpCustomer);
			printf("\nDetails of the customer with account number %d is deleted. ", accNumber);
			break;
		}
	}
	fclose(fpCustomer);
}
void updateCustomer()
{
	struct customer cust;
	int accNumber;
	printf("\nEnter the account number of the customer to update the details: ");
	scanf("%d", &accNumber);
	fpCustomer = fopen(FILE_NAME, "r+");
	while(fread(&cust, sizeof(cust), 1, fpCustomer))
	{
		if(cust.accountNumber == accNumber)
		{
			cust.status = 'A';
			printf("\nEnter new Account balance of the customer: ");
			scanf("%f", &cust.accountBalance);
			fseek(fpCustomer, sizeof(cust) * -1, SEEK_CUR);
			fwrite(&cust, sizeof(cust), 1, fpCustomer);
			printf("\nDetails of the customer with account number %d is updated. ", accNumber);
			break;
		}
	}
	fclose(fpCustomer);
}