# Store records using dictionary.

filename = "customer1.dat"
records = { }
fpData = open(filename, "r")
records = fpData.read()
if fpData == None:
	print("File is empty")
else:
	records = eval(records)
def display():
	for key, info in records.items():
		print("\nAccount number:", key)
		for name, balance in info.items():
			print(name + ':', balance)
print("Customer Details.")
option = 1
while(True):
	accountNumber = input("Enter the Account number of the customer: ")
	name = input("enter the customer name: ")
	balance = input("enter the Account balance: ")
	records[accountNumber] = {'Name':name, 'Balance':balance}
	fpdata = open(filename, "w")
	fpdata.write(str(records))
	fpdata.close()
	option = input("Do you want to add new Customer Details? [y/n]: ")
	if(option.upper() == 'N'):
		display()
		break