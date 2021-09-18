// read and print n marks using array

#include <stdio.h>
int main()
{
    int i, noOfMarks;  
    printf("Enter the number of subject's marks to be printed: ");
    scanf("%d", &noOfMarks);
    int marksArray[noOfMarks]
    for(i = 0; i < noOfMarks; i++)
    {
        printf("Enter the marks of subject %d: ", i + 1);
        scanf("%d", &marksArray[i]);
    }
    printf("\nThe marks of the student are. \n");
    for(i = 0; i < noOfMarks; i++)
    {
        printf("The marks of subject %d: ", i + 1);
        printf("%d \n", marksArray[i]);
    }
    return 0;
}