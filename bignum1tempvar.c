// read 2 numbers and print which one is bigger using 1 temporary variable

#include<stdio.h>
int main()
{
	int number1, number2, temp = 0;
	printf("Enter the first number: ");
	scanf("%d", &number1);
	printf("Enter the second number: ");
	scanf("%d", &number2);	
	if (number1 == number2)
	{
		printf("%d is equal to %d.", number2, number1);
	}
	else
	{
		if(number1 > number2)
		{	
			temp = number2;
			number2 = number1;
			number1 = temp;
		}
			printf("%d is bigger than %d.", number2, number1);
	}
	return 0;
}