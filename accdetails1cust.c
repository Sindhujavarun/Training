//read and print account details of 1 bank customer using structure.

#include <stdio.h>
struct customer 
{
    char customerName[50];
    int accountNumber, accountBalance;
};
struct customer cust;
int main() 
{
    printf("Enter Bank account details.\n");
    printf("\n\nEnter account number of the customer: ");
    scanf("%d", &cust.accountNumber);
    printf("\nEnter name of the customer: ");
    scanf("%s", &cust.customerName);
    printf("\nEnter Account balance of the customer: ");
    scanf("%d", &cust.accountBalance);
    printf("\n\nDisplaying Bank account details:\n");
    printf("\nAccount number of the customer: %d\n", cust.accountNumber);
    printf("\nName of the customer: ");
    printf("%s\n", cust.customerName);
    printf("\nAccount balance of the customer: %d", cust.accountBalance);
    return 0;
}