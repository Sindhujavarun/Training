menuList = ['\tWelcome To SV Bank', '\t------------------', '\t\tMenu', '1. Add new customer.', '2. Display all customer details.', '3. Update customer details.', '4. Delete customer details.', '5. Exit from the Menu.']
fields = ["Account_Number", "Name", "Account_Balance"]

fieldValueList = []
ctrFields = 0
for field in fields:
	field = field.strip()
	if ctrFields == 0:
		keyFieldValue = field
		ctrFields += 1
	else:
		fieldValueList.append(field)