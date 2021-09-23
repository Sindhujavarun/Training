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
    FILE *fpCustomer;
    char customerName[10];
    fpCustomer = fopen("customerDetails.txt","r");
    if(fpCustomer == NULL)
    {
        printf("\nCan't open file or file doesn't exist.");
        exit(0);
    }
    fread(&cust, sizeof(cust), 1, fpCustomer);
    printf("Account number of the customer: %d\n", cust.accountNumber);
    printf("Name of the customer: %s\n", cust.customerName);
    printf("Account balance: %f\n", cust.accountBalance);
    fclose(fpCustomer);
}