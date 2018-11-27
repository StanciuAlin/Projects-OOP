#pragma once

#include <string>
#include "Utils.h"
#include "PhoneContact.h"

class PhoneContact
{
public:
	struct Address
	{
		friend class PhoneBook;
		std::string city_address;
		std::string street_address;
		int number_address;
		Address();
		//Address(std::string city, std::string street, int number) : city_address(city), street_address(street), number_address(number) {};
		~Address();
	};
	~PhoneContact();
	//PhoneContact(std::string user_name, std::string user_phone_number, std::string city, std::string street, int number) : name(user_name), phone_number(user_phone_number), address(city, street, number) {};
	std::string GetName() const { return name; }
	std::string GetPhoneNumber() const { return phone_number; }
	friend bool ReadPhoneContactData(PhoneContact& phoneContact);
private:
	std::string name;
	std::string phone_number;
	
	Address address;
};