// Read a name and save it into a file.

#include <stdio.h>
#include <stdlib.h>
int main() 
{
    char name[20];
    FILE *filePtr;
    filePtr = fopen("name.txt", "w");
    if (filePtr == NULL) 
    {
        printf("Error!");
        exit(1);
    }
    printf("Enter a name to save in the file name.txt:\n");
    fgets(name, sizeof(name), stdin);
    fprintf(filePtr, "%s", name);
    fclose(filePtr);
    return 0;
}