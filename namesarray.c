// read and print 5 names using array.

#include <stdio.h>
#define COUNT 5
#define LENGTH 10
int main()
{
    char nameArray[LENGTH];
    int i; 
    printf("Enter the names of %d students. \n", COUNT);
    for(i = 0; i < COUNT; i++)
    {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", nameArray);
    }
    printf("\nNames of %d student are. ", COUNT);
    for(i = 0; i < COUNT; i++)
    {
        printf("\nStudent %d name: ", i + 1);
        printf("%s", nameArray);
    }
    return 0;
}