# CRUD operations in python

fileName = "bankCustomer.dat"
records = {}
fpData = open(fileName, "r")
records = fpData.read()
if fpData == None:
	print("File is empty.")
else:
	records = eval(records)

def create():
	while(1):
		accountNumber = int(input("Enter Account Number of the customer: "))
		customerName = input("Enter Name of the customer: ")
		balance = int(input("Enter Account balance of the customer: "))
		records[accountNumber] = [customerName, balance]
		fpData = open(fileName, "w")
		fpData.write(str(records))
		print("Customer details are successfully saved.")
		fpData.close()
		option = input("Do you want to add new Customer Details? [y/n]: ")
		if (option.upper() == 'N'):
			break

def display():
	print("\tBank Customer Details")
	print("\t" + '-' * len("Bank Customer Details"))
	for record in records:
		print("Account Number:", record)
		print("Name:", records[record][0])
		print("Account Balance:", records[record][1])
		print('------------------------')

def update():
	accountNumber = int(input("Enter the account number of the customer to update the details: "))
	choice = int(input("\n1. Name\n2. Account Balance\nChoose the field you want to update: "))
	for record in records:
		if record == accountNumber:
			if choice == 1:
				records[record][0] = input("Enter new Name: ")
			if choice == 2:
				records[record][1] = int(input("Enter new Account Balance: "))
	fpData = open(fileName, "w")
	fpData.write(str(records))
	print("Details of the customer with account number", accountNumber, "is updated successfully.")
	fpData.close()

def delete():
	accountNumber = int(input("Enter the account number of the customer to delete the details: "))
	del records[accountNumber]
	print("Details of the customer with account number", accountNumber, "is deleted successfully.")
	fpData = open(fileName, "w")
	fpData.write(str(records))
	fpData.close()

def exit():
	print("\nThank you for using our system!")
	quit()

while(1):
	print("\tWelcome To SV Bank.")
	print("\t" + '-' * len("Welcome To SV Bank."))
	print("\n\t\tMenu \n1. Add new customer.\n2. Display all customer details.\n3. Update customer details.\n4. Delete customer details.\n5. Exit from the Menu.")
	choices = [create, display, update, delete, exit]
	choice = int(input("\nEnter your option: "))
	length = len(choices)
	if choice > length:
		print("Invalid option.")
		print("Please Try again!")
	else:
		choices[choice - 1]()
	mainMenu = input("Please press any key to go back to main menu.")