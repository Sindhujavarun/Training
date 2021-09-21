//Print sum of all command-line arguments.

#include <stdio.h>
int main(int argc, char *argv[])
{
	int argument1, argument2, sum = 0, counter;
	for(counter = 1; counter < argc; counter++)
	{
		printf("arg[%2d]: %d\n", counter, atoi(argv[counter]));
		sum = sum + atoi(argv[counter]);
	}
	printf("SUM of all values: %d\n", sum);
	return 0;
}