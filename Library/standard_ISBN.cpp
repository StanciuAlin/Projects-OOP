#include "standard_ISBN.h"
#include <iostream>

Standard_ISBN::Standard_ISBN()
{
}

Standard_ISBN::Standard_ISBN(std::string _ISBN)
{ //if transmit whole ISBN as parameter, then set ISBN field
	this->ISBN = _ISBN; //
}

Standard_ISBN::Standard_ISBN(std::string id_country, std::string id_edit, std::string id_title)
{ //if transmit ISBN without control number, then compute this as number formed with all digits from country, publishing and title uniq code modulo 11.
	//if remainder is 10, in ISBN appear x character
	int int_id_country = std::stoi(id_country); //convert strings to numbers
	int int_id_edit = std::stoi(id_edit);
	int int_id_title = std::stoi(id_title);

	int control = (int_id_country + int_id_edit + int_id_title) % 11; //compute control number with formula
	if (control < 10) //if remainder < 10, then push back the digit
	{
		std::string control_string = std::to_string(control);
		ISBN = id_country + "-" + id_edit + "-" + id_title + "-" + control_string;
	}
	else //push back the x character
	{
		std::string control_string = std::to_string(control);
		ISBN = id_country + "-" + id_edit + "-" + id_title + "-" + 'x';
	}
	
}

Standard_ISBN::~Standard_ISBN()
{
}

bool Standard_ISBN::validate_ISBN(std::string _ISBN)
{ //validate if the given ISBN is correctly computed
	long long nr = 0; //number formed with characters
	std::string string_nr; //select all characters which are digits
	int i;
	for (i = 0; i < _ISBN.length() - 1; i++)
	{
		if (_ISBN[i] != '-') //avoid '-' character
		{
			//int ch = (int)_ISBN[i];
			string_nr += _ISBN[i];
		}
		else
		{
			continue;
		}
	}
	nr = std::stoi(string_nr); //convert string to number
	int control;
	if (_ISBN[i] == 'x') //if control number is x
	{
		control = 10;
		if (nr % 11 == control)
		{
			return true;
		}
		return false;
	}
	else //else control number is digit
	{
		control = (int)_ISBN[i] - '0';
		if (nr % 11 == control)
		{
			return true;
		}
		return false;
	}
}

void Standard_ISBN::write_ISBN(std::string _ISBN)
{ //show the ISBN value
	std::cout << "Codul ISBN este: " << _ISBN << "\n";
}
//I have tried to implement overloading for == operator
//bool operator==(const Standard_ISBN& _ISBN1, const Standard_ISBN& _ISBN2)
//{
//	return _ISBN1.get_ISBN() == _ISBN2.get_ISBN();
//}