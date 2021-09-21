// Declare a char pointer and an int pointer and print the addresses they contain before malloc() and after malloc().

#include <stdio.h>
#include <stdlib.h>
void main()
{
   int *ptrMarks;
   char *ptrName;
   printf("The address of ptrName before malloc() is: %u\n", *ptrName);
   printf("The address of ptrMarks before malloc() is: %u\n", *ptrMarks);
   ptrName = malloc(20);
   ptrMarks = malloc(5 * sizeof(int));
   printf("The address of ptrName after malloc() is: %u\n", *ptrName);
   printf("The address of ptrMarks after malloc() is: %u\n", *ptrMarks);
}