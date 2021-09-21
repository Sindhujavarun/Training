// read and print n names using malloc().

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int counter, countOfNames;
    char **ptrNames;
    printf("Enter the number of names of students to be printed: ");
    scanf("%d", &countOfNames);
    ptrNames = malloc(countOfNames * sizeof(char*));
    for(counter = 0; counter < countOfNames; counter++)
    {
        ptrNames[counter] = malloc(20);
        printf("Enter the name of student %d: ", counter + 1);
        scanf("%s", ptrNames[counter]);
    }
    printf("\nThe name of the students are. \n");
    for(counter = 0; counter < countOfNames; counter++)
    {
        printf("student %d name: ", counter + 1);
        printf("%s\n", ptrNames[counter]);
    }
    return 0;
}
