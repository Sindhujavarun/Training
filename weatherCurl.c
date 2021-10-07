// show the weather report of a given city using curl.

#include <stdio.h>
#include <string.h>
#define FILE_NAME "weather.dat"

void main()
{
    FILE *fpWeather;
    char cityName[20], *temperature, weather[1000], url[100];
    printf("Enter the name of the city to know the temperature: ");
    scanf("%s", cityName);
	sprintf(url, "curl \"https://api.openweathermap.org/data/2.5/weather?q=%s&appid=7c13cfcd4e9bef72a7befcd048b5b005&units=metric\" > %s", cityName, FILE_NAME);
    system(url);
    fpWeather = fopen(FILE_NAME, "r");
    fgets(weather, 1000, fpWeather);
    weather[strlen(weather) - 1] = '\0';
    temperature = strtok(weather, "]");
    temperature = strtok(NULL, ";{");
    temperature = strtok(NULL, ":");
    temperature = strtok(NULL, ",");
    printf("The temperature of the city %s is %s%cC", cityName, temperature, 248);
    fclose(fpWeather);
}