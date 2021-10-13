# read a number and print if it is a prime or not.

import math
numberToCheck = int(input("Enter a number to check if it is prime or not: "))

if numberToCheck > 1:
    for divisor in range(2, int(math.sqrt(numberToCheck)) + 1):
        if (numberToCheck % divisor == 0):
            print(numberToCheck, "is not a Prime Number")
            break
    else:
        print(numberToCheck, "is a Prime number")
else:
    print(numberToCheck, "is not a Prime number")