#include "Library.h"
int Library::number_books = 0;
Library::Library()
{
	library_books;
}

Library::~Library()
{
}

void Library::Add_book(book _book)
{
	library_books.push_back(_book);
}

int Library::Search_by_title(std::string title)
{
	bool find = false;
	int id_book;
	for (int i = 0; i < library_books.size(); i++)
	{
		if (library_books.at(i).Get_title_book() == title)
		{
			find = true;
			id_book = i;
			break;
		}
	}
	if (!find)
	{
		return -1;
	}
	else
	{
		return id_book;
	}
}

int Library::Search_by_publishing(std::string publishing)
{
	bool find = false;
	int id_book;
	for (int i = 0; i < library_books.size(); i++)
	{
		if (library_books.at(i).Get_publishing_book() == publishing)
		{
			find = true;
			id_book = i;
			break;
		}
	}
	if (!find)
	{
		return -1;
	}
	else
	{
		return id_book;
	}
}

int Library::Search_by_ISBN(Standard_ISBN _ISBN)
{
	bool find = false;
	int id_book;
	for (int i = 0; i < library_books.size(); i++)
	{
		if (library_books.at(i).Get_ISBN_book().get_ISBN() == _ISBN.get_ISBN())
		{
			find = true;
			id_book = i;
			break;
		}
	}
	if (!find)
	{
		return -1;
	}
	else
	{
		return id_book;
	}
}
