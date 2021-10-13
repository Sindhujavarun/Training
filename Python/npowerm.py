# print n to the power of m.

base = int(input("Enter the value of base to find n to the power of m: "))
power = int(input("Enter the value of power to find n to the power of m: "))
counter = power
result = 1
while power != 0:
	result = result * base
	power -= 1
print(base, " to the power of ", counter, " is ", result)