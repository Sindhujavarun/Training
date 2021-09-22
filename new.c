#include<stdio.h>
#include <stdlib.h>
int main()
{
  FILE *filePtr;
  int number;
  filePtr = fopen("new.txt","w");
  if(filePtr == NULL)
  {
    printf("\nCan't open file or file doesn't exist.");
    exit(0);
  }
  printf("\nEnter Number: ");
  scanf("%d", &number);
  fwrite(&number, sizeof(number), 1, filePtr);
  fclose(filePtr);
  return 0;
}