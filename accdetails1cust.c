//read and print account details of 1 bank customer using structure.

#include <stdio.h>
struct customer 
{
    char name[50];
    int accountNo;
    char branch[50];
} s;

int main() 
{
    printf("Enter Bank account details.\n");
    printf("Enter name of the customer: ");
    fgets(s.name, sizeof(s.name), stdin);
    printf("Enter account number of the customer: ");
    scanf("%d", &s.accountNo);
    printf("Enter the bank branch of the customer: ");
    scanf("%s", &s.branch);
    printf("Displaying Bank account details:\n");
    printf("Name of the customer: ");
    printf("%s", s.name);
    printf("Account number of the customer: %d\n", s.accountNo);
    printf("Bank branch of the customer: %s", s.branch);
    return 0;
}