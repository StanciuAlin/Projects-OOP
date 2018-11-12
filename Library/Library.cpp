#include "Library.h"
int Library::number_books = 0;
Library::Library()
{
}

Library::~Library()
{
}

void Library::Add_book(book _book)
{
	library_books.push_back(_book); //add in library books
}

int Library::Search_by_title(std::string title)
{ //search in library by title
	bool find = false; //propose that is not exist a book with title "title"
	int num_books = 0; //number of books with title "title"
	for (int i = 0; i < library_books.size(); i++)
	{
		if (library_books.at(i).Get_title_book() == title) //if find the book with title "title"
		{
			find = true; //mark that exist at least one book with title "title"
			num_books++; //increase number of books
			//break;
		}
	}
	if (!find) //if is not exist a book with specified title, then return -1.
	{
		return -1;
	}
	else //return numbers of books found by the above criteria
	{
		return num_books;
	}
}

int Library::Search_by_publishing(std::string publishing)
{ //search in library by publishing with same argument as Search_by_title method
	bool find = false;
	int num_books = 0;
	for (int i = 0; i < library_books.size(); i++)
	{
		if (library_books.at(i).Get_publishing_book() == publishing)
		{
			find = true;
			num_books++;
			//break;
		}
	}
	if (!find)
	{
		return -1;
	}
	else
	{
		return num_books;
	}
}

int Library::Search_by_ISBN(Standard_ISBN _ISBN)
{ //search in library by ISBN with same argument as Search_by_title method
	bool find = false;
	int num_books = 0;
	for (int i = 0; i < library_books.size(); i++)
	{
		if (library_books.at(i).Get_ISBN_book().get_ISBN() == _ISBN.get_ISBN())
		{
			find = true;
			num_books++;
			//break;
		}
	}
	if (!find)
	{
		return 0;
	}
	else
	{
		return num_books;
	}
}

bool Library::check_unicity_ISBN(Standard_ISBN _ISBN)
{ //check unicity for ISBN introduced
	if (Search_by_ISBN(_ISBN) == 0) //uniq value means that the current ISBN do not appear in library book ISBNs, i.e. number of books with specified ISBN must be 0
	{
		return true; //uniq value until then
	}
	return false; //exist at least one ISBN with same value in library book ISBNs
	//return Search_by_ISBN(_ISBN) == 1 ? true : false;
}
