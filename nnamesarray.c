// read and print n marks using array

#include <stdio.h>
int main()
{
    int i, countOfNames;  
    printf("Enter the number of students's name to be printed: ");
    scanf("%d", &countOfNames);
    char namesArray[countOfNames];
    for(i = 0; i < countOfNames; i++)
    {
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", &namesArray[i]);
    }
    printf("\nThe names of the students are. \n");
    for(i = 0; i < countOfNames; i++)
    {
        printf("The student %d name: ", i + 1);
        printf("%s \n", namesArray[i]);
    }
    return 0;
}