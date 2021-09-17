//print the series 1, 4, 27,256,... upto n terms.

#include<stdio.h>
#include<math.h>
int main()
{
	int noOfTerms, i;
	long long power;
	printf("Enter no. of terms to be printed in the series 1, 4, 27, 256,...: ");
	scanf("%d", &noOfTerms);
	for(i = 1; i < noOfTerms; i++)
	{
		power = pow(i, i);
		printf("%d, ", power);
	}
	if(i == noOfTerms)
	{
		power = pow(i, i);
		printf("%lld.", power);
	}
	return 0;
}