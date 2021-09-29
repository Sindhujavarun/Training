#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int counter, countOfName = 0, numberToRepeat = 0, repeater = 0;
    char *name, string[10] = "0123456789";
    for(counter = 1; counter < argc; counter++)
    {
        if((strcspn(argv[counter], string) == strlen(argv[counter])) && countOfName == 0)
        {
            countOfName = 1;
            name = argv[counter];
        }
        else if((strcspn(argv[counter], string) != strlen(argv[counter])) && repeater == 0)
        {
            repeater = 1;
            numberToRepeat = atoi(argv[counter]);
        } 
        else
        {
            continue;
        }
    }
    if(argc > 3 || argc < 3)
    {
        printf("Please enter a single number and a single name.");
        printf("\nEnter a name to print: ");
        scanf("%s", name);
        printf("Enter number of times the name needs to be printed: ");
        scanf("%d", &numberToRepeat);
    }
    // else if(argc <= 1)
    // {
    //     printf("Please enter a single number and a single name.");
    //     printf("\nEnter a name to print: ");
    //     scanf("%s", name);
    //     printf("Enter number of times the name need to be printed: ");
    //     scanf("%d", &numberToRepeat);        
    // }
    else if(countOfName == 1 && repeater == 0)
    {
        printf("Enter number of times the name need to be printed: ");
        scanf("%d", &numberToRepeat);
    }
    else if(countOfName == 0 && repeater == 1)
    {
        printf("Enter a name to print: ");
        scanf("%s", name);
    }
    printf("Name is: %s\n", name);
    printf("count is: %d\n", numberToRepeat);
    for(counter = 0; counter < numberToRepeat; counter++)
    {
        printf("%s\n", name);
    }
    return 0;
}