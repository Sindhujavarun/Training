// read and print 5 marks using array.

#include <stdio.h>
#define COUNT 5
int main()
{
    int marksArray[1000], i;  
    printf("Enter %d marks of the student. \n", COUNT);
    for(i = 0; i < COUNT; i++)
    {
        printf("Enter subject %d of %d marks: ", i + 1, COUNT);
        scanf("%d", &marksArray[i]);
    }
    printf("\nMarks of the %d subjects are. ", COUNT);
    for(i = 0; i < COUNT; i++)
    {
        printf("\nSubject %d marks: ", i + 1);
        printf("%d  ", marksArray[i]);
    }
    return 0;
}