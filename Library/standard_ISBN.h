#pragma once
#include <string>

class Standard_ISBN
{
public:
	
	Standard_ISBN();
	Standard_ISBN(std::string _ISBN);
	Standard_ISBN(std::string id_country, std::string id_edit, std::string id_title);

	~Standard_ISBN();

	std::string get_ISBN() const
	{
		return ISBN;
	}
	bool validate_ISBN(std::string _ISBN);
	void write_ISBN(std::string _ISBN);
private:
	std::string ISBN = "0";
	

};
