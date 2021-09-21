// Print all bank customer details from the file created using file, structure and fread().

#include<stdio.h>
#include <stdlib.h>
struct customer
{
    int accountNumber;
    char customerName[20];
    float accountBalance;
};
void main()
{
    struct customer cust;
    FILE *filePtr;
    char customerName[10];
    int counter;
    filePtr = fopen("customerDetails.txt","r");
    if(filePtr == NULL)
    {
        printf("\nCan't open file or file doesn't exist.");
        exit(0);
    }
    fread(&cust, sizeof(cust), 1, filePtr);
    printf("Account number of the customer: %d\n", cust.accountNumber);
    printf("Name of the customer: %s\n", cust.customerName);
    printf("Account balance: %f\n", cust.accountBalance);
    fclose(filePtr);
}