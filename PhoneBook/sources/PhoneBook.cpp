#include "PhoneBook.h"
#include "PhoneContact.h"
#include <iostream>
#include <algorithm>

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

bool PhoneBook::AddContact(PhoneContact& new_user)
{
	try
	{
		contacts.push_back(new_user);
	}
	catch (const std::exception& err)
	{
		std::cout << "Error: " << err.what() << '\n';
	}
	return false;
}

int PhoneBook::SearchContactByName(string user_name)
{
	try
	{
		auto it = find_if(contacts.begin(), contacts.end(), [&user_name](const PhoneContact& obj) {return obj.GetName() == user_name; });
		if(it != contacts.end())
		{
			// found element. it is an iterator to the first matching element.
			// if you really need the index, you can also get it:
			auto index = std::distance(contacts.begin(), it);

			return index;
		}
		return -1;
	}
	catch (const std::exception& err)
	{
		cout << "Error: " << err.what() << '\n';
	}
}

void PhoneBook::PrintPhoneNumber(string user_name)
{
	int index = SearchContactByName(user_name);
	if (index > -1)
	{
		std::cout << "Numarul de telefon al utilizatorului " << contacts[index].GetName() << " este " << contacts[index].GetPhoneNumber() << '\n';
	}
	else
	{
		cout << "Numarul cautat nu se gaseste in agenda!";
	}
}
