# read and print n marks of n students.

students = {}
marks = []
countOfNames = int(input("Enter the number of student's marks are to be printed: "))
countOfMarks = int(input("Enter the number of subject's marks to be printed: "))
for ctrNames in range(countOfNames):
	name = input("\nEnter name of Student %d: " %(ctrNames + 1))
	for ctrMarks in range(countOfMarks):
		marks.append(int(input("Enter Mark of subject %d: " %(ctrMarks + 1))))
	students[name] = marks
	marks = []
print("\nMarks of stuents are: ", students)