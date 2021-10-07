// show the meaning and play the audio of pronunciation of a given word.

#include <stdio.h>
#include <string.h>
#define FILE_NAME "meaning.dat"

void main()
{
	FILE *fpmeaning;
	char word[20], *meaning, wordLine[1500], url[100], voice[20];
	printf("Enter a word to get the meaning and pronunciation: ");
	scanf("%s", word);
	sprintf(url, "curl \"https://api.dictionaryapi.dev/api/v2/entries/en/%s\" > %s", word, FILE_NAME);
	system(url);
	fpmeaning = fopen(FILE_NAME, "r");
	fgets(wordLine, 1500, fpmeaning);
	wordLine[strlen(wordLine) - 1] = '\0';
	meaning = strtok(wordLine, "[{");
	meaning = strtok(NULL, ":[{");
	meaning = strtok(NULL, ":");
	meaning = strtok(NULL, "\"");
	sprintf(voice, "vlc -I null --play-and-exit http:%s", meaning);
	system(voice);
	meaning = strtok(NULL, "]");
	meaning = strtok(NULL, "[{");
	meaning = strtok(NULL, "[{");
	meaning = strtok(NULL, ":");
	meaning = strtok(NULL, "\"");
	printf("\nThe meaning of the word %s: \n", word);
	printf("%s is %s", word, meaning);
	fclose(fpmeaning);
}
