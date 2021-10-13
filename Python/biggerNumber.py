# read 2 numbers and print which one is bigger.

number1 = int(input("Enter the first number:"))
number2 = int(input("Enter the second number: "))
if(number1 > number2):
    print(number1, "is greatest.")
elif(number2 > number1):
    print(number2, "is greatest.")
else:
    print(number1, "and", number2, "are equal.")