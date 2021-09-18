//Read and print n marks using malloc().

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int noOfMarks, i, *ptr, sum = 0;
    printf("Enter the number of subject's marks to be printed: ");
    scanf("%d", &noOfMarks);
    ptr = (int *) malloc(noOfMarks * sizeof(int));
    if(ptr == NULL)
    {
        printf("\nError! Memory not allocated\n");
        return 0;
    }
    for(i = 0; i < noOfMarks; i++)
    {
        printf("\nEnter marks of subject %d: ", i + 1);
        scanf("%d", ptr + i);    
        sum = sum + *(ptr + i);
    }
    printf("\n\nThe marks of the student are. ");
    for(i = 0; i < noOfMarks; i++)
    {
        printf("\nThe marks of subject %d: ", i + 1);
        printf("%d", *(ptr + i));
    }
    free(ptr);
    return 0;
}