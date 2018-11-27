#include "Test.h"

void TestPhoneBook(PhoneBook& phoneBook)
{
	int option;
	cout << "*******************Agenda telefonica**************************\n\n";
	cout << "Optiuni: \n 1. Adauga un nou contact\n 2.Cauta dupa nume un utilizator din agenda. \n 3.Afisare numar telefon pentru un utilizator dat. \n 4.Iesire.\n\n";
	cout << "Optiunea aleasa este:\n";
	cin >> option;
	do
	{
		switch (option)
		{
		case 1:
		{
			PhoneContact newContact;
			if (!ReadPhoneContactData(newContact))
			{
				throw;
			}
			phoneBook.AddContact(newContact);
			break;
		}
		case 2:
		{
			string searched_name;
			cout << "Numele cautat este: ";
			cin >> searched_name;
			int index = phoneBook.SearchContactByName(searched_name);
			if (index > -1)
			{
				cout << "Nume gasit in agenda!";
			}
			else
			{
				cout << "Numele cautat nu se gaseste in agenda!";
			}
			break;
		}
		case 3:
		{
			string user_name;
			cout << "Numele utilizatorului al carui numar de telefon va fi afisat este: ";
			cin >> user_name;
			phoneBook.PrintPhoneNumber(user_name);
			break;
		}
		case 4:
		{
			break;
		}
		default:
			break;
		}
		cout << "Optiunea aleasa este:\n";
		cin >> option;
	} while (option != 4);

}

