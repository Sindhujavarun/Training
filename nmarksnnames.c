// read and print n marks of n students.

#include <stdio.h>
int main() 
{
	int ctrNames, ctrMarks, countOfNames, countOfMarks;
	printf("Enter the number of student's marks are to be printed: ");
    scanf("%d", &countOfNames);
    printf("Enter the number of subject's marks to be printed: ");
    scanf("%d", &countOfMarks);
    char names[countOfNames][20];
    int marks[countOfMarks];
	for(ctrNames = 0; ctrNames < countOfNames; ctrNames++)
	{ 
		printf("\nEnter name of Student %d:", ctrNames + 1);
		scanf("%s", names[ctrNames]);
		for (ctrMarks = 0; ctrMarks < countOfMarks; ctrMarks++)
        {
			printf("Enter Mark of subject %d:", ctrMarks + 1);
			scanf("%d", &marks[ctrMarks]);
		}
	}
	for(ctrNames = 0; ctrNames < countOfNames; ctrNames++)
	{
		printf("\nMarks of %s\n", names[ctrNames]);
		for (ctrMarks = 0; ctrMarks < countOfMarks; ctrMarks++)
		{
			printf("Marks of subject %d: %d\n", ctrMarks + 1, marks[ctrMarks]);
		}
	}
	return 0;
}