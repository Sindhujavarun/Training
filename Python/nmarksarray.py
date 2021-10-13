# read and print n marks using array

countOfMarks = int(input("Enter the number of subject's marks to be printed: "))
marksArray = []
for counter in range(0, countOfMarks):
	marks = int(input("Enter the marks of subject %d: " %(counter + 1)))
	marksArray.append(marks)
print("\nThe marks of subjects are: ", marksArray)