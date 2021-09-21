// print n marks of n students using pointers.

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int countOfNames, countOfSubjects, ctrNames, ctrSubjects, **ptrMarks;
	char **ptrNames;
	printf("Enter the number of student's marks are to be printed: ");
    scanf("%d", &countOfNames);
	printf("Enter the number of subject's marks to be printed: ");
	scanf("%d", &countOfSubjects);
	ptrNames = malloc(countOfNames * sizeof(char*));
	ptrMarks = malloc(countOfSubjects * sizeof(int*));
	for(ctrNames = 0; ctrNames < countOfNames; ctrNames++)
	{
		ptrNames[ctrNames] = malloc(20);
        printf("\nEnter the name of student %d: ", ctrNames + 1);
        scanf("%s", ptrNames[ctrNames]);
        ptrMarks[ctrNames] = malloc(countOfSubjects * sizeof(int));
        for (ctrSubjects = 0; ctrSubjects < countOfSubjects; ctrSubjects++)
        {
			printf("Enter the mark of subject %d: ", ctrSubjects + 1);
			scanf("%d", &ptrMarks[ctrNames][ctrSubjects]);
        }
	}
	printf("\n\nThe marks of the students are. \n");
	for(ctrNames = 0; ctrNames < countOfNames; ctrNames++)
	{
		printf("\nMarks of %s: \n", ptrNames[ctrNames]);
        for (ctrSubjects = 0; ctrSubjects < countOfSubjects; ctrSubjects++)
        {
			printf("The marks of subject %d: ", ctrSubjects + 1);
			printf("%d \n", ptrMarks[ctrNames][ctrSubjects]);
		}
	}
	return 0;
}
