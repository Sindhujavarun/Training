// read 5 marks and print the percentage using array.

#include <stdio.h>
#define COUNT 5
int main()
{
    int marksArray[COUNT], counter, sum = 0, total = 0, countOfStudent;
    float percentage = 0;  
    char names[COUNT][20];
    printf("Enter the name of the student: ");
    scanf("%s", &names);
    printf("Enter marks of %d subjects of %s. \n", COUNT, names);
    for(counter = 0; counter < COUNT; counter++)
    {
        printf("Enter marks of subject %d of %d: ", counter + 1, COUNT);
        scanf("%d", &marksArray[counter]);
        sum = sum + marksArray[counter];
    }
    total = COUNT * 100;
    percentage = (sum / COUNT);
    printf("\nMarks of %d subjects of %s are. ", COUNT, names);
    for(counter = 0; counter < COUNT; counter++)
    {
        printf("\nSubject %d marks: ", counter + 1);
        printf("%d  ", marksArray[counter]);
    }
    printf("\n\nTotal marks scored by %s = %d out of %d", names, sum, total);
    printf("\n\nPercentage Scored by %s = %.2f%%", names, percentage);
    return 0;
}