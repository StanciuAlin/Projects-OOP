#pragma once
#include "book.h"
#include <vector>
class Library
{
public:
	//getter
	std::vector<book> Get_library_books() const { return library_books; }
	//setter
	void Set_library_books(std::vector<book> _library_books) { library_books = _library_books; }

	Library();
	~Library();
	void Add_book(book _book);
	int Search_by_title(std::string title);
	int Search_by_publishing(std::string publishing);
	int Search_by_ISBN(Standard_ISBN _ISBN);

private:
	std::vector<book> library_books;
	static int number_books;
};
