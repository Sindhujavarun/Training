// show the horoscope of the given sign.

#include <stdio.h>
#include <string.h>
#define FILE_NAME "horoscope.dat"

void main()
{
    FILE *fpHoroscope;
    char sign[20], *horoscope, horoscopeLine[500], url[100];
    printf("Enter your sign to get today's horoscope: ");
    scanf("%s", sign);
	sprintf(url, "curl -X POST \"https://aztro.sameerkumar.website/?sign=%s&day=today\" > %s", sign, FILE_NAME);
    system(url);
    fpHoroscope = fopen(FILE_NAME, "r");
    fgets(horoscopeLine, 500, fpHoroscope);
    horoscopeLine[strlen(horoscopeLine) - 1] = '\0';
    horoscope = strtok(horoscopeLine, ",");
    horoscope = strtok(NULL, " ");
    horoscope = strtok(NULL, "\"");
    printf("Horoscope of the sign %s on %s is: ", sign, horoscope);
    horoscope = strtok(NULL, ":");
    horoscope = strtok(NULL, "\"");
    horoscope = strtok(NULL, "\"");
    printf("%s", horoscope);
    fclose(fpHoroscope);
}