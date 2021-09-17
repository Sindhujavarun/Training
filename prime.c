//read a number and print if it is a prime or not.

#include <stdio.h>
#include <math.h>
int main()
{
    int numberToCheck, divisor, primeStatus = 1;
    printf("Enter a number to check if it is prime or not: ");
	scanf("%d", &numberToCheck);
    for (divisor = 3; divisor <= sqrt(numberToCheck); divisor+2) 
    {
        if (numberToCheck % divisor == 0) 
        {
            primeStatus= 0;
            break;
        }
    }
 
    if (numberToCheck <= 1)
    {
        primeStatus = 0;
    }
    if (primeStatus == 1) {
        printf("%d is a prime number", numberToCheck);
    }
    else {
        printf("%d is not a prime number", numberToCheck);
    }
 
    return 0;
}