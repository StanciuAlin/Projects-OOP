#include "standard_ISBN.h"
#include <iostream>

Standard_ISBN::Standard_ISBN()
{
}

Standard_ISBN::Standard_ISBN(std::string _ISBN)
{
	this->ISBN = _ISBN;
}

Standard_ISBN::Standard_ISBN(std::string id_country, std::string id_edit, std::string id_title)
{
	int int_id_country = std::stoi(id_country);
	int int_id_edit = std::stoi(id_edit);
	int int_id_title = std::stoi(id_title);

	int control = (int_id_country + int_id_edit + int_id_title) % 11;
	if (control < 10)
	{
		std::string control_string = std::to_string(control);
		ISBN = id_country + "-" + id_edit + "-" + id_title + "-" + control_string;
	}
	else
	{
		std::string control_string = std::to_string(control);
		ISBN = id_country + "-" + id_edit + "-" + id_title + "-" + 'x';
	}
	
}

Standard_ISBN::~Standard_ISBN()
{
}

bool Standard_ISBN::validate_ISBN(std::string _ISBN)
{
	long long nr = 0;
	std::string string_nr;
	int i;
	for (i = 0; i < _ISBN.length() - 1; i++)
	{
		if (_ISBN[i] != '-')
		{
			//int ch = (int)_ISBN[i];
			string_nr += _ISBN[i];
		}
		else
		{
			continue;
		}
	}
	nr = std::stoi(string_nr);
	int control;
	if (_ISBN[i] == 'x')
	{
		control = 10;
		if (nr % 11 == control)
		{
			return true;
		}
		return false;
	}
	else
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
{
	std::cout << "Codul ISBN este: " << _ISBN << "\n";
}
bool operator==(const Standard_ISBN& _ISBN1, const Standard_ISBN& _ISBN2)
{
	return _ISBN1.get_ISBN() == _ISBN2.get_ISBN();
}