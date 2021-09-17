//print the multiplication table of a given number.

#include <stdio.h>
int main() 
{
	int tableNumber, noOfRows, result = 0, counter;
	printf("Enter a number to print it's multiplication table: ");
	scanf("%d", &tableNumber);
	printf("Enter the number of rows needed in the multiplication table: ");
	scanf("%d", &noOfRows);
	for (counter = 1; counter <= noOfRows; counter++) 
	{
		result = tableNumber * counter;
		printf("%d X %d = %d \n", tableNumber, counter, result);
	}
	return 0;
}