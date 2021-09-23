// store new customers and print details of all customer.

#include<stdio.h>
#include <stdlib.h>
#define FILENAME "detailsOfCustomer.dat"
void createCustomer();
void showCustomers();
struct customer
{
  int accountNumber;
  char customerName[20];
  float accountBalance;
};
int main()
{
	int option;
	do
	{
		printf("\nBANK CUSTOMERS");
		printf("\n-------------------");
		printf("\n1. Create new customer details ");
		printf("\n2. Show all customer details ");
		printf("\n3. Exit");
		printf("\n-------------------");
		printf("\nPlease enter your option: ");
		scanf("%d", &option);
		switch(option)
		{
			case 1: createCustomer();
			break;
			case 2: showCustomers();
			break;
			case 3: ;
			break;
			default: printf("\nEnter a valid option!!");
			break;
			getch();
		}
	}while(option != 3);
}
void createCustomer()
{
	printf("\nNEW CUSTOMER DETAILS");
	FILE *fpCustomer;
	struct customer cust;
	char customerName[10];
	printf("\nEnter Account Number of the customer: ");
	scanf("%d", &cust.accountNumber);
	printf("Enter Name of the customer: ");
	scanf("%s", cust.customerName);
	printf("Enter Account balance of the customer: ");
	scanf("%f", &cust.accountBalance);
	fpCustomer = fopen(FILENAME, "a");
	if(fpCustomer == NULL)
	{
		printf("\nCan't open file or file doesn't exist. ");
		exit(0);
	}
	fwrite(&cust, sizeof(cust), 1, fpCustomer);
	fclose(fpCustomer);
	printf("\nCustomer details successfully saved. \n");
	printf("AccountNumber of the customer: %d\n", cust.accountNumber);
	printf("Name of the customer: %s\n", cust.customerName);
	printf("Account balance: %f\n", cust.accountBalance);
	getch();
}
void showCustomers()
{
	struct customer cust;
    FILE *fpCustomer;
    char customerName[10];
    int counter;
    fpCustomer = fopen(FILENAME,"r");
    if(fpCustomer == NULL)
    {
        printf("\nCan't open file or file doesn't exist.");
        exit(0);
    }
    while(fread(&cust, sizeof(cust), 1, fpCustomer))
    {
    	printf("\nAccount number of the customer: %d\n", cust.accountNumber);
    	printf("Name of the customer: %s\n", cust.customerName);
    	printf("Account balance: %f\n", cust.accountBalance);
    }
    fclose(fpCustomer);
    getch();
}