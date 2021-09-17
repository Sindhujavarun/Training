//print n to the power of n.

#include <stdio.h>
int main() 
{
	int powerNumber, counter = 0;
	long long result = 1;
	printf("Enter a number to find n to the power of n: ");
	scanf("%d", &powerNumber);
	counter = powerNumber;
	while(counter != 0)
	{
		result *= powerNumber;
		counter--;
	}
	printf("%d to the power of %d = %lld", powerNumber, powerNumber, result);
	return 0;
}