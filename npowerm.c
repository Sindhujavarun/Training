//print n to the power of m.

#include <stdio.h>
int main() 
{
	int base, power, counter = 0;
	long long result = 1;
	printf("Enter the value of base to find n to the power of m: ");
	scanf("%d", &base);
	printf("Enter the value of power to find n to the power of m: ");
	scanf("%d", &power);
	counter = power;
	while(power != 0)
	{
		result *= base;
		power--;
	}
	printf("%d to the power of %d = %.0lld", base, counter, result);
	return 0;
}