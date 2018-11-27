#pragma once

#include "PhoneContact.h"
#include <string>
#include <vector>

using namespace std;
class PhoneContact;

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();
	vector<PhoneContact> Get_Contacts() const { return contacts; }
	bool AddContact(PhoneContact& new_user);
	int SearchContactByName(string user_name);
	void PrintPhoneNumber(string user_name);
private:
	vector<PhoneContact> contacts;
};

