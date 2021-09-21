//Read and print n marks using malloc().

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int countOfMarks, counter, *ptrMarks, sum = 0;
    printf("Enter the number of subject's marks to be printed: ");
    scanf("%d", &countOfMarks);
    ptrMarks = (int *) malloc(countOfMarks * sizeof(int));
    if(ptrMarks == NULL)
    {
        printf("\nError! Memory not allocated\n");
        return 0;
    }
    for(counter = 0; counter < countOfMarks; counter++)
    {
        printf("\nEnter marks of subject %d: ", counter + 1);
        scanf("%d", ptrMarks + counter);    
        sum = sum + *(ptrMarks + counter);
    }
    printf("\n\nThe marks of the student are. ");
    for(counter = 0; counter < countOfMarks; counter++)
    {
        printf("\nThe marks of subject %d: ", counter + 1);
        printf("%d", *(ptrMarks + counter));
    }
    free(ptrMarks);
    return 0;
}