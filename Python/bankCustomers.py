# CRUD operations in python

fileName = "bankCustomer.dat"
records = {}
fpData = open(fileName, "r")
records = fpData.read()
if fpData == None:
	print("File is empty.")
else:
	records = eval(records)

class bankCustomerDetails:

	def create(self):
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

	def display(self):
		print("\tBank Customer Details")
		print("\t" + '-' * len("Bank Customer Details"))
		for record in records:
			print("Account Number: ", record)
			print("Name: ", records[record][0])
			print("Account Balance: ", records[record][1])
			print('------------------------')

	def update(self):
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

	def delete(self):
		accountNumber = int(input("Enter the account number of the customer to delete the details: "))
		del records[accountNumber]
		print("Details of the customer with account number", accountNumber, "is deleted successfully.")
		fpData = open(fileName, "w")
		fpData.write(str(records))
		fpData.close()

bank_object = bankCustomerDetails()
while(1):
	print("\tWelcome To SV Bank.")
	print("\t" + '-' * len("Welcome To SV Bank."))
	choice = int(input("\n\t\tMenu \n1. Add new customer.\n2. Display all customer details.\n3. Update customer details.\n4. Delete customer details.\n5. Exit from the Menu.\n\nEnter your option from the menu:"))
	if choice == 1:
		bank_object.create()
	elif choice == 2:
		bank_object.display()
	elif choice == 3:
		bank_object.update()
	elif choice == 4:
		bank_object.delete()
	elif choice == 5:
		print("\nThank you for using our banking system!")
		print("Come again!!!\tBye Bye!!!")
		break
	else:
		print("Invalid option.")
		print("Please Try again!")
		mainMenu = input("Please press any key to go back to main menu.")	 