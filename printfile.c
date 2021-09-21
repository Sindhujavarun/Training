// Read the file containing names and print all names on the monitor using file.

#include <stdio.h>
#include <stdlib.h>
int main ()
{
    FILE *fptr;
    int counter, countOfNames;
    char fileName[100], string;
    printf("Enter the filename to open: ");
    scanf("%s", fileName);
    printf("Enter the number of names to be saved in the file printfile.txt: ");
    scanf("%d", &countOfNames);
    char names[countOfNames][20];
    printf("\nEnter %d names to be saved in the file printfile.txt: \n", countOfNames);
    fptr = fopen (fileName, "w"); 
    for(counter = 0; counter < countOfNames; counter++)
    {
        printf("Enter name %d: ", counter + 1);
        scanf("%s", names[counter]);
        fprintf(fptr, "%s\n", names[counter]);
    }
    fclose (fptr);
    fptr = fopen (fileName, "r");  
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
    printf("\nThe names in the file %s are: \n", fileName);
    for(counter = 0; counter < countOfNames; counter++)
    {
    printf("%s\n", names[counter]);
    }
    fclose(fptr);
    return 0;
}
