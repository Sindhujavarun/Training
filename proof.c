// print balance in the file using fwrite and fprintf.

#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE *fpBalance;
	int balance;
	fpBalance = fopen("balance.dat", "w");
	printf("\nEnter balance: ");
	scanf("%d", &balance);
	fprintf(fpBalance, "%d", balance);
	fwrite(&balance, sizeof(balance), 1, fpBalance);
	fclose(fpBalance);
	return 0;
}