#create a framework program suitable for various domains

dataFileName = "framework.dat"
fieldFileName = "fieldNames.cfg"
menuFileName = "menu.cfg"
data = {}
fieldValues = []
menuLine = open(menuFileName, "r")
menu = menuLine.read()
fData = open(dataFileName, "r").read()
if fData == None:
	print("File is empty.")
else:
	data = eval(fData)
fieldLine = open(fieldFileName, "r")
fields  = fieldLine.readlines()
fieldValueList = []
ctrFields = 0
for field in fields:
	field = field.strip()
	if ctrFields == 0:
		keyFieldValue = field
		ctrFields += 1
	else:
		fieldValueList.append(field)

def savedData():
	fData = open(dataFileName, "w")
	fData.write(str(data))
	fData.close()

def create():
	while(True):
		ctrFields = 0
		tempFieldValue = []
		print("\n")
		for field in fields:
			field =  field.strip()
			if ctrFields == 0:
				print("Enter " + field + ": ", end = "")
				key = input()
				ctrFields += 1
			else:
				print("Enter " + field + ": ", end = "")
				fieldValue = input()
				tempFieldValue.append(fieldValue) 
		fieldValues = tempFieldValue[:]
		data[key] =  fieldValues
		savedData()
		print("Details are successfully saved.")
		choice = input("\nDo you want to add new Customer Details? [y/n]: ")
		if (choice.upper() == 'N'):
			break

def display():
	for record in data:
		ctrValue = 0
		ctrFields = 0
		print("\n")
		for field in fields:
			if ctrFields == 0:
				field = field.strip()
				print(field + ": " + record)
				ctrFields += 1
			else:
				field = field.strip()
				print(field + ": " + data[record][ctrValue])
				ctrValue += 1
		print("------------------")

def update():
	print("Enter the", keyFieldValue, "to update details: ", end = "")
	key = input()
	ctrUpdate = 1
	for fieldName in fieldValueList:
		print(ctrUpdate, ",", fieldName)
		ctrUpdate += 1
	option = int(input("Enter your option: "))
	for record in data:
		if record == key:
			print("Enter new", fieldValueList[option - 1], ": ", end = "")
			data[record][option - 1] = input()
			savedData()
			print("Details of the customer with account number", keyFieldValue, "'", key, "' is successfully updated.")

def delete():
	print("Enter", keyFieldValue, "to delete: ", end = "")
	key = input()
	if key in data:
		del data[key]
		savedData()
		print("Details of the customer with account number", keyFieldValue, key, "are successfully deleted.")

def exit():
	print("\nThank you for using our system!")
	quit()

while(1):
	print(menu)
	options = [create, display, update, delete, exit]
	length = len(options)
	option = int(input("\nEnter your option: "))
	if option > length:
		print("Invalid option.")
		print("Please Try again!")
	else:
		options[option - 1]()
	mainMenu = input("Please press any key to go back to main menu.")
