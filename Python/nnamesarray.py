# read and print n names using array

countOfNames = int(input("Enter the number of students's name to be printed: "))
namesArray = []
for counter in range(0, countOfNames):
	names = str(input("Enter the name of the student %d: " %(counter + 1)))
	namesArray.append(names)
print("\nThe names of students are: ", namesArray)