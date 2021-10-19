# show the meaning and play the audio of pronunciation of a given word.

import requests
import subprocess
word = input("Enter a word to get the meaning and pronunciation: ")
url = "https://api.dictionaryapi.dev/api/v2/entries/en/" + word
response = requests.get(url).json()
audio = 'vlc -I null --play-and-exit http:' + response[0]['phonetics'][0]['audio']
subprocess.run(audio)
print("\nThe meaning of the word" + word + ": \n")
print(word, "is", response[0]['meanings'][0]['definitions'][0]['definition'])