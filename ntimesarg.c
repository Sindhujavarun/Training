// print given name given number of times using command-line arguments.

#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
    int counter;
    if(argc <= 1)
    {
        printf("Enter number of times to repeat the name: \n");
        exit(0);
    }
    printf("Name is: %s\n", (argv[1]));
    printf("count is: %d", atoi(argv[2]));
    for(counter = 0; counter <= atoi(argv[2]); counter++)
    {
        printf("%s\n", argv[1]);
    }
}