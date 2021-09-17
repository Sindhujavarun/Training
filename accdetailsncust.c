//read and print account details of n bank customer using array of structure.

#include <stdio.h>
struct student 
{
    char name[50];
    int accountNo;
    char branch[50];
} s;

int main() 
{
    int i, noOfCustomers;
    printf("Enter account details of customers.\n");
    printf("Enter the number of customer's details to be stored and printed: ");
    scanf("%d", &noOfCustomers);
    for (i = 0; i < noOfCustomers; i++) 
    {
        printf("Enter name of customer %d: ", i + 1);
        scanf("%s", &s.name);
        printf("Enter account number of customer %d: ", i + 1);
        scanf("%d", &s.accountNo);
        printf("Enter the bank branch of customer %d: ", i + 1);
        scanf("%s", &s.branch);
    }
    printf("Displaying Bank account details:\n");
    for (i = 0; i < noOfCustomers; i++) 
    {
        printf("Name of customer %d: ", i + 1);
        printf("%s", s.name);
        printf("\nAccount number of customer %d: ", i + 1);
        printf("%d", s.accountNo);
        printf("\nBank branch of customer %d: ", i + 1);
        printf("%s\n", s.branch);
    }
    return 0;
}