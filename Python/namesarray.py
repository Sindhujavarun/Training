# read and print 5 names using array.

namesArray = []
for counter in range(0, 5):
	names = str(input("Enter the names of 5 students: "))
	namesArray.append(names)
print("\nThe names of 5 students are: ", namesArray)
