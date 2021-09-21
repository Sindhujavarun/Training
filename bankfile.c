// save a bank customer details in a file using structure.

#include<stdio.h>
#include <stdlib.h>
struct customer
{
  int accountNumber;
  char customerName[20];
  float accountBalance;
};
int main()
{
  struct customer cust;
  FILE *filePtr;
  char customerName[10];
  filePtr = fopen("customerDetails.txt","w");
  if(filePtr == NULL)
  {
    printf("\nCan't open file or file doesn't exist.");
    exit(0);
  }
  printf("\nEnter Account Number of the customer: ");
  scanf("%d", &cust.accountNumber);
  fprintf(filePtr, "%d\n", cust.accountNumber);
  printf("Enter Name of the customer: ");
  scanf("%s", &cust.customerName);
  fprintf(filePtr, "%s\n", cust.customerName);
  printf("Enter Account balance of the customer: ");
  scanf("%f", &cust.accountBalance);
  fprintf(filePtr, "%f\n", cust.accountBalance);
  printf("\nCustomer details successfully saved. \n");
  printf("AccountNumber of the customer: %d\n", cust.accountNumber);
  printf("Name of the customer: %s\n", cust.customerName);
  printf("Account balance: %f\n", cust.accountBalance);
  fclose(filePtr);
  return 0;
}