// Read a name and save it into a file.

#include <stdio.h>
#include <stdlib.h>
int main() 
{
    char name[1000];
    FILE *fptr;
    fptr = fopen("name.txt", "w");
    if (fptr == NULL) 
    {
        printf("Error!");
        exit(1);
    }
    printf("Enter a name to save in the file name.txt:\n");
    fgets(name, sizeof(name), stdin);
    fprintf(fptr, "%s", name);
    fclose(fptr);
    return 0;
}