//To print given name given number of times using command line arguments.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{

	char string[10] = "0123456789";
	int countOfRepeatation = 0, counter;
	char *name;
	int countOfName = 0;
	int repeatation = 0;
	// printf("%d", argc);

	for(counter = 1; counter < argc; counter++)
	{
		if((strcspn(argv[counter], string) == strlen(argv[counter])) && countOfName == 0)
		{
			countOfName = 1;
			name = argv[counter];
		}
		else if((strcspn(argv[counter], string) != strlen(argv[counter])) && countOfRepeatation == 0)
		{
			countOfRepeatation = 1;
			repeatation = atoi(argv[counter]);
		} 
		else if(countOfName == 1 && countOfRepeatation ==1)
		{
			break;
		}
		else
		{
			continue;
		}
	}
	if(argc <= 1)
	{
		printf("Enter name and number of times to repeat? \n");
		scanf("%s %d", name, &repeatation);
	}
	else if(countOfName == 1 && countOfRepeatation == 0)
	{
		printf("Enter number of times to repeat: ");
		scanf("%d", &repeatation);
	}
	else if(countOfName == 0 && countOfRepeatation ==1)
	{
		printf("Enter name to be repeat: ");
		scanf("%s", name);
	}
	else
	{

	}
	printf("Name is: %s\n", name);
	printf("count is: %d\n", repeatation);
	for(counter = 0; counter < repeatation; counter++)
	{
		printf("%s\n", name);
	}
	return 0;
}