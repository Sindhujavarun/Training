# show the temperature of a given city.

import requests
cityName = input("Enter the name of the city to know the temperature: ")
url = "https://api.openweathermap.org/data/2.5/weather?q=" + cityName + "&appid=7c13cfcd4e9bef72a7befcd048b5b005&units=metric"
response = requests.get(url).json()
print("\nThe temperature of the city", cityName, "is", response['main']['temp'], chr(176) + "c", sep = " ")