// Read the file containing names and print all names on the monitor using file.

#include <stdio.h>
int main ()
{
    FILE * fptr;
    int i,noOfNames;
    char name[50];
    char fname[20]="printfile.txt";
    char str1;
    printf("Enter the number of names to be saved in the file printfile.txt: ");
    scanf("%d", &noOfNames);
    printf("\nEnter %d names to be saved in the file printfile.txt: \n", noOfNames);
    fptr = fopen (fname,"w"); 
    for(i = 0; i <= noOfNames; i++)
    {
        fgets(name, sizeof name, stdin);
        fputs(name, fptr);
    }
    fclose (fptr);
    fptr = fopen (fname, "r");  
    printf("\nThe names in the file %s are:\n",fname);
    str1 = fgetc(fptr);
    while (str1 != EOF)
    {
            printf ("%c", str1);
            str1 = fgetc(fptr);
    }
    printf("\n");
    fclose (fptr);
    return 0;
}
