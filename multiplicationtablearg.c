// print multiplication table using command line arguments.

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int counter, number;
	if(argc <= 1)
	{
		printf("you have forgot to type number to calculate multiplicaion table.");
		printf("\nEnter a number to print multiplicaion table: ");
		scanf("%d", &number);
	}
	else
	{
	number = atoi(argv[1]);
	}
	printf("The multiplicaion table of %d: \n", number);
	for(counter = 0; counter < 10; counter++)
	{
		printf("%d X %d = %d \n", number, counter + 1, number * (counter + 1));
	}
	return 0;
}