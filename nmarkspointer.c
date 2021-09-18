// read and print n marks using pointer

#include <stdio.h>
int main()
{
    int noOfMarks, i;
    printf("Enter the number of subject's marks to be printed: ");
    scanf("%d", &noOfMarks);
    int marksArray[noOfMarks];
    int *ptr = marksArray;
    for (i = 0; i < noOfMarks; i++)
    {
    	printf("Enter marks of subject %d: ", i + 1);
        scanf("%d", (ptr + i));   
    }

    printf("\nThe marks of the student are. \n");
    for (i = 0; i < noOfMarks; i++)
    {
    	printf("The marks of subject %d: ", i + 1);
        printf("%d \n", *(ptr + i));
    }

    return 0;
}