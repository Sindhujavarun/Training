// create a function and call it from main().

#include <stdio.h>
#include <stdlib.h>
int sum(int , int);
int main()
{
    int number1, number2, total;
    printf("Enter first number ");
    scanf("%d", &number1);
    printf("Enter second number ");
    scanf("%d", &number2);
    total = sum(number1, number2);
    printf("The sum of these numbers :%d",total);
    return 0;
}
int sum(int a, int b)
{
    int result = a + b;
    return result;
}