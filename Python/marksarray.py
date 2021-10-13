# read and print 5 marks using array.

marksArray = []
for counter in range(0, 5):
	marks = int(input("Enter the marks of 5 subjects: "))
	marksArray.append(marks)
print("\nMarks of 5 subjects are: ", marksArray)
