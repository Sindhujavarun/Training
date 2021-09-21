// read and print n marks using pointer

#include <stdio.h>
int main()
{
    int countOfMarks, counter;
    printf("Enter the number of subject's marks to be printed: ");
    scanf("%d", &countOfMarks);
    int marksArray[countOfMarks];
    int *ptrMarks = marksArray;
    for (counter = 0; counter < countOfMarks; counter++)
    {
    	printf("Enter marks of subject %d: ", counter + 1);
        scanf("%d", (ptrMarks + counter));   
    }

    printf("\nThe marks of the student are. \n");
    for (counter = 0; counter < countOfMarks; counter++)
    {
    	printf("The marks of subject %d: ", counter + 1);
        printf("%d \n", *(ptrMarks + counter));
    }

    return 0;
}