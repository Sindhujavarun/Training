# Store records using list of lists.

filename = "Customer.dat"
records = []
fpData = open(filename, "r")
records = fpData.read()
if fpData == None:
	print("File is empty")
else:
	records = eval(records)
print("Customer Details.")
option = 1
while(True):
	accountNumber = input("Enter the Account number: ")
	name = input("Enter Name of the Customer: ")
	balance = input("Enter the Account balance: ")
	records.append([accountNumber, name, balance])
	fpdata = open(filename, "w")
	fpdata.write(str(records))
	fpdata.close()
	option = input("Do you want to add new Customer Details? [y/n]: ")
	if(option == 'N' or option == 'n'):
		break
fpdata = open(filename, "r").readlines()
print("\nAdded customer Details are.")
for line in fpdata:
	print(line)