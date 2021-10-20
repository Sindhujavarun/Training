# framework program using xml

import xml.etree.ElementTree as ET
from mainData import menuList, fields, keyFieldValue, fieldValueList
fileName = "data.xml"

data = ET.parse(fileName)
records = data.getroot()
if ET.parse(fileName) == 0:
	tree = ET.ElementTree()
	records = ET.Element(menuList[0])

def create():
	while(1):
		record = ET.Element('record')
		records.append(record)
		ctrCreate = 0
		while ctrCreate < len(fields):
			s_elem1 = ET.Element(fields[ctrCreate])
			print("Enter", fields[ctrCreate], ":", end = " ")
			s_elem1.text = input()
			record.append(s_elem1)
			ctrCreate += 1
			savedData()
		choice = input("\nDo you want to add new Details? [y/n]: ")
		print("\n")
		if (choice.upper() == 'N'):
			break

def display():
	ctrDisplay = 0
	while(ctrDisplay < len(list(records))):
		ctrValue = 0
		while(ctrValue < len(fields)):
			print(fields[ctrValue] + ":", records[ctrDisplay][ctrValue].text)
			ctrValue += 1
		print("-------------------------")
		ctrDisplay += 1
		print("\n")

def update():
	while(1):
		ctrUpdate = 0
		print("Enter", keyFieldValue, "to update details:", end = "")
		key = input()
		while(ctrUpdate < len(list(records))):
			ctrUpdateValue = 0
			if records[ctrUpdate][0].text == key:
				while(ctrUpdateValue < len(fieldValueList)):
					print(ctrUpdateValue + 1, ":", fieldValueList[ctrUpdateValue])
					ctrUpdateValue += 1
				choice = int(input("Choose the field to update: "))
				print("Enter new", fieldValueList[choice - 1], "to update" + ": ", end = "")
				records[ctrUpdate][choice].text = input()
				savedData()
				print(fieldValueList[choice - 1], "of", keyFieldValue, key, "is successfully updated.")
			ctrUpdate += 1
		choice = input("\nDo you want to update again any Details? [y/n]: ")
		print("\n")
		if (choice.upper() == 'N'):
			break

def delete():
	while(1):
		ctrDelete = 0
		print("Enter", keyFieldValue, "to delete:", end = "")
		key = input()
		while(ctrDelete < len(list(records))):
			if records[ctrDelete][0].text == key:
				del records[ctrDelete]
				savedData()
				print("\nDetails of", keyFieldValue, key, "is successfully deleted.")
			ctrDelete += 1
		choice = input("\nDo you want to delete any other Details? [y/n]: ")
		print("\n")
		if (choice.upper() == 'N'):
			break

def savedData():
	b_xml = ET.tostring(records)
	fData = open(fileName, "wb")
	fData.write(b_xml)

def menu():
	ctrMenu = 0
	while(ctrMenu < len(menuList)):
		menu = menuList[ctrMenu]
		print(menu)
		ctrMenu += 1

def exit():
	print("\nThank you for using our system!")
	quit()

while(1):
	menu()
	options = [create, display, update, delete, exit]
	length = len(options)
	option = int(input("\nEnter your option: "))
	print("\n")
	if option > length:
		print("Invalid option.")
		print("Please Try again!")
	else:
		options[option - 1]()
	mainMenu = input("\nPlease press any key to go back to main menu.")
