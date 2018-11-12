#include "standard_ISBN.h"
#include "book.h"
#include "Library.h"


#include <iostream>

int main()
{
	//std::string str = "978-54-3253-1";
	Standard_ISBN *i = new Standard_ISBN("978", "121", "242");
	std::string str1 = i->get_ISBN();
	std::cout << str1;
	if (i->validate_ISBN("978-121-242-x"))
	{
		std::cout << "DAA!";
	}
	else
	{
		std::cout << "NUU!";
	}
	delete i;
	return 0;

}