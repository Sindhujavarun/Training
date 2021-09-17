// read and print n marks using pointer

#include<stdio.h>
#define COUNT 1000
int main()
{
	int marks[COUNT], i, *p = &marks[0], noOfMarks;
	printf("Enter the number of marks of the student to be entered: ");
    scanf("%d", &noOfMarks);
    for(i = 0; i < noOfMarks; i++)
    {
    	printf("Enter the marks of %d student: ", i + 1);
        scanf("%d", marks[i]);
    }
    printf("\nMarks of the student are: ");
	for(i = 0; i < noOfMarks; i++)
	{
		printf("%d ",*(p + i));
	}
return 0;
}