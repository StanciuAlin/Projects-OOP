#include <iostream>
#include "User.h"


User::~User()
{
}

void User::Read_data_user()
{
	std:: cout << "\nNume utilizator: ";
	std::cin >> this->name;
	std::cout << "\nParola:";
	std::cin >> this->password;
}
