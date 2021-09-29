// Print 1 to given number without using a second variable.

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int counter;
	if(argc <= 1)
	{
		printf("Enter a number to print the remaining numbers.");
		exit(0);
	}
	for (counter = 0; counter < atoi(argv[1]); counter++)
	{
		printf("%d\n", counter + 1);
	}
	return 0;
}