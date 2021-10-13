# print the multiplication table of a given number.

tableNumber = int(input("Enter a number to print it's multiplication table: "))
countOfRows = int(input("Enter the number of rows needed in the multiplication table: "))
counter = 1
while counter <= countOfRows:
    print(tableNumber, "x", counter, "=", tableNumber * counter)
    counter = counter + 1