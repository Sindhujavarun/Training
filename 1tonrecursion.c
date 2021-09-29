// Print 1 to given number without using a second variable.


#include <stdio.h>
void printNumber(int N);
int main()
{
    int N;
    printf("Enter the limit to print the numbers: ");
    scanf("%d", &N);
    printNumber(N);
    return 0;
}
void printNumber(int N)
{
    if(N >= 1)
    {
        printNumber(N - 1);
        printf("%d \n", N);
    }
}