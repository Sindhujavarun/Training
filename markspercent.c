// read 5 marks and print the percentage using array.

#include <stdio.h>
#define COUNT 5
#define LENGTH 10
int main()
{
    int marksArray[COUNT], i, sum = 0, total = 0, noOfStudent;
    float percentage = 0;  
    char names[COUNT][LENGTH];
    printf("Enter the name of the student: ");
    scanf("%s", &names);
    printf("Enter marks of %d subjects of %s. \n", COUNT, names);
    for(i = 0; i < COUNT; i++)
    {
        printf("Enter marks of subject %d of %d: ", i + 1, COUNT);
        scanf("%d", &marksArray[i]);
        sum += marksArray[i];
    }
    total = COUNT * 100;
    percentage = (sum / COUNT);
    printf("\nMarks of %d subjects of %s are. ", COUNT, names);
    for(i = 0; i < COUNT; i++)
    {
        printf("\nSubject %d marks: ", i + 1);
        printf("%d  ", marksArray[i]);
    }
    printf("\n\nTotal marks scored by %s = %d out of %d", names, sum, total);
    printf("\n\nPercentage Scored by %s = %.2f%%", names, percentage);
    return 0;
}