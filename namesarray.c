// read and print 5 names using array.

#include <stdio.h>
#define COUNT 5
int main()
{
    char namesArray[COUNT][20];
    int counter; 
    printf("Enter the names of %d students. \n", COUNT);
    for(counter = 0; counter < COUNT; counter++)
    {
        printf("Enter the name of student %d: ", counter + 1);
        scanf("%s", namesArray[counter]);
    }
    printf("\nNames of %d student are. ", COUNT);
    for(counter = 0; counter < COUNT; counter++)
    {
        printf("\nStudent %d name: ", counter + 1);
        printf("%s", namesArray[counter]);
    }
    return 0;
}