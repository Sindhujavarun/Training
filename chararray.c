// Declare a char array and print all characters in it in a loop using %c before scanf(). Do the same after scanf.

#include <stdio.h>
int main()
{
	char name[20];
	int counter;
	printf("Char array values before scanning elements:\n");
	for (counter = 0; counter < sizeof(name); counter++)
	{
		printf("%c \t %d\n", name[counter], name[counter]);
	}
	printf("\nEnter a name: ");
	scanf("%s", &name);
	for(counter = 0; counter < sizeof(name); counter++)
	{
		printf("%c \t %d\n\n", name[counter], name[counter]);
	}
	return 0;
}