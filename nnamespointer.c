// read and print n names using pointer

#include <stdio.h>
#define LENGTH 10
int main() 
{
    int i, noOfNames;
    char *name[LENGTH];
    printf("Enter the number of student's names to be printed: ");
    scanf("%d", &noOfNames);
    printf("Enter the names of %d student: ", noOfNames);
    for (i = 0; i < noOfNames; i++)
    {
        scanf("%d", name);
    }
    printf("You entered: \n");
    for (i = 0; i < noOfNames; i++)
    {
        printf("%d\n", *(name + i));
    }
    return 0;
}