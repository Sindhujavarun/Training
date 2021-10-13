# print tables book.

print('Multiplication table')
startTableNumber = int(input('Enter a number from which the multiplication table is to be printed: '))
endTableNumber = int(input('Enter a number upto which the multiplication table is to be printed: '))
countOfRows = int(input('Enter the number of rows needed in each multiplication table: '))

for tableNumberCtr in range (startTableNumber, endTableNumber+1):
    heading = "Multiplication Table of " + str(tableNumberCtr)
    print("\n" + heading)
    print("-" * len(heading))
    for countOfRowsCtr in range(1, countOfRows+1):
        print('%d * %d = %d\t' %(tableNumberCtr, countOfRowsCtr, tableNumberCtr * countOfRowsCtr))