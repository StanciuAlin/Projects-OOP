#include "Utils.h"

bool ReadPhoneContactData(PhoneContact& phoneContact)
{
	try
	{
		cout << "Nume utilizator ";
		cin >> phoneContact.name;
		ENDL;
		cout << "Numar telefon ";
		cin >> phoneContact.phone_number;
		ENDL;
		cout << "Adresa ";
		ENDL;
		PhoneContact::Address userAddress;
		cout << "Orasul ";
		cin >> userAddress.city_address;
		ENDL;
		cout << "Strada ";
		cin >> userAddress.street_address;
		ENDL;
		cout << "Numarul ";
		cin >> userAddress.number_address;
		ENDL;
		return true;
	}
	catch (const std::exception&)
	{
		return false;
	}
}
