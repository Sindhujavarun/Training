//print tables book.

#include <stdio.h> 
int main()
{
	int column, row, numberOfTables, noOfRows, result = 0;
	printf("Enter a number upto which the multiplication table is to be printed: ");
	scanf("%d", &numberOfTables);
	printf("Enter the number of rows needed in each multiplication table: ");
	scanf("%d", &noOfRows);
	for(column = 1; column <= numberOfTables; column++)
	{
		printf("Multiplication table of %d: \n", column);
		for(row = 1; row <= noOfRows; row++)
		{
			result = column * row;
			printf("%d X %d = %d\n", column, row, result);
		}
	}
	return 0;
}