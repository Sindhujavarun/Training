// read and print n names using pointer

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int countOfNames, counter;
    printf("Enter the number of students's name to be printed: ");
    scanf("%d", &countOfNames);
    char namesArray[countOfNames][20];
    char (*ptrNames)[20] = namesArray;
    for (counter = 0; counter < countOfNames; counter++)
    {
        printf("Enter the name of student %d: ", counter + 1);
        scanf("%s", ptrNames[counter]);   
    }
    printf("\nThe names of the students are. \n");
    for (counter = 0; counter < countOfNames; counter++)
    {
        printf("The student %d name: ", counter + 1);
        printf("%s \n", ptrNames[counter]);
    }
    return 0;
}