// read and print n marks using array

#include <stdio.h>
int main()
{
    int counter, countOfMarks;  
    printf("Enter the number of subject's marks to be printed: ");
    scanf("%d", &countOfMarks);
    int marksArray[countOfMarks];
    for(counter = 0; counter < countOfMarks; counter++)
    {
        printf("Enter the marks of subject %d: ", counter + 1);
        scanf("%d", &marksArray[counter]);
    }
    printf("\nThe marks of the student are. \n");
    for(counter = 0; counter < countOfMarks; counter++)
    {
        printf("The marks of subject %d: ", counter + 1);
        printf("%d \n", marksArray[counter]);
    }
    return 0;
}