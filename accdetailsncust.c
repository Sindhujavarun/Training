//read and print account details of n bank customer using array of structure.

#include <stdio.h>
struct customerDetails 
{
    char customerName[20];
    int accountNumber;
    float accountBalance;
};
int main() 
{
    int counter, countOfCustomers;
    printf("Enter account details of customers.\n");
    printf("Enter the number of customer's details to be stored and printed: ");
    scanf("%d", &countOfCustomers);
    struct customerDetails customer[countOfCustomers];
    for (counter = 0; counter < countOfCustomers; counter++) 
    {
        printf("\nEnter account number of the customer %d: ", counter + 1);
        scanf("%d", &customer[counter].accountNumber);
        printf("Enter name of customer %d: ", counter + 1);
        scanf("%s", customer[counter].customerName);
        printf("Enter the account balance of the customer %d: ", counter + 1);
        scanf("%f", &customer[counter].accountBalance);
    }
    printf("\n\nDisplaying Bank account details:\n");
    for (counter = 0; counter < countOfCustomers; counter++) 
    {
        printf("\nAccount number of the customer %d: ", counter + 1);
        printf("%d\n", customer[counter].accountNumber);
        printf("Name of the customer %d: ", counter + 1);
        printf("%s\n", customer[counter].customerName);
        printf("Account balance of customer %d: ", counter + 1);
        printf("%f\n", customer[counter].accountBalance);
    }
    return 0;
}