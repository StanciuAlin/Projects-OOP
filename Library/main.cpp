#include "standard_ISBN.h"
#include "book.h"
#include "Library.h"

#include <iostream>

int main()
{
	//std::string str = "978-54-3253-1";
	//Standard_ISBN *i = new Standard_ISBN("978", "121", "242");
	//std::string str1 = i->get_ISBN();
	//std::cout << str1;
	//if (i->validate_ISBN("978-121-242-x"))
	//{
	//	std::cout << "DAA!";
	//}
	//else
	//{
	//	std::cout << "NUU!";
	//}
	//delete i;
	Library library;

	FILE *input_stream; //input file
	errno_t err = fopen_s(&input_stream, "books.txt", "r");
	//check if input file is open
	if (err == 0)
	{
		printf("The file \"books.txt\" was opened\n");
	}
	else
	{
		printf("The file \"books.txt\" was not opened\n");
	}

	do
	{
		std::cout << "Options:\n 1 - Add a book in library\n 2 - Search a book by title\n 3 - Search a book by publishig\n 4 - Search a book by ISBN\n 5 - Exit";
		int option;
		//fscanf_s(input_stream, "%d", &option);
		//read option
		std::cin >> option;
		std::cin.get();
		switch (option)
		{
		case 1:
		{
			//create a new book
			//create variable for book fields
			std::string title_book;
			std::string author_book;
			std::string publishing_book;
			std::string ISBN_string_book;
			int year_book;
			float price_book;
			
			//read the title of book
			std::getline(std::cin, title_book);
			//read the author of book
			std::getline(std::cin, author_book);
			//read the publishing of book
			std::getline(std::cin, publishing_book);
			//read the ISBN of book
			std::getline(std::cin, ISBN_string_book);
			//read the year of appearance for book
			std::cin >> year_book;
			//read the price of book
			std::cin >> price_book;
			std::cin.get();

			//validate ISBN || check if is correctly formed
			Standard_ISBN *ISBN_book = new Standard_ISBN(ISBN_string_book);
			if (ISBN_book->validate_ISBN(ISBN_string_book)) //validate_ISBN and return true if ISBN is correct build
			{
				if (library.check_unicity_ISBN(ISBN_string_book)) //check for unicity
				{
					std::cout << "Valid ISBN!\n"; //if ISBN is correct build and is uniq, then show a message
					delete ISBN_book;
				}
				else //ISBN incorrect format
				{
					std::cout << "Invalid ISBN! Enter the correct ISBN: \n";
					while (std::getline(std::cin, ISBN_string_book)) //read while ISBN intrduced is correct
					{
						Standard_ISBN *ISBN_book_new = new Standard_ISBN(ISBN_string_book);
						if (ISBN_book->validate_ISBN(ISBN_string_book)) //validate_ISBN return true if ISBN is correct
						{
							if (library.check_unicity_ISBN(ISBN_string_book)) //if ISBN is UNIQUE
							{
								std::cout << "Valid ISBN!";
								break;
							}
						}
						delete ISBN_book_new;
					}
				}
			}
			book new_book(title_book, author_book, publishing_book, ISBN_string_book, year_book, price_book);
			//add book in library
			library.Add_book(new_book);

			break;
		}
		case 2:
		{
			//search a book by title
			std::string title_book;
			std::getline(std::cin, title_book);
			if (library.Search_by_title(title_book) > 0)
			{
				std::cout << "The book is in library at position " << library.Search_by_title(title_book) << '\n';
			}
			else
			{
				std::cout << "The book is not in library. Please enter other title!\n";
			}
			break;
		}
		case 3:
		{
			std::string publishing_book;
			std::getline(std::cin, publishing_book);
			if (library.Search_by_publishing(publishing_book) > 0)
			{
				std::cout << "The book is in library at position " << library.Search_by_publishing(publishing_book) << '\n';
			}
			else
			{
				std::cout << "The book is not in library. Please enter other publishing!\n";
			}
			break;
		}
		case 4:
		{
			
			std::string ISBN_book_string;

			std::getline(std::cin, ISBN_book_string);
			Standard_ISBN ISBN_searched_book(ISBN_book_string);
			

			if (library.Search_by_ISBN(ISBN_searched_book) > 0)
			{
				std::cout << "The book is in library at position " << library.Search_by_ISBN(ISBN_searched_book) << '\n';
			}
			else
			{
				std::cout << "The book is not in library. Please enter other book!\n";
			}
			break;
		}
		case 5:
		{
			exit(0);
		}
		default:
			break;
		}
	} while (1);
	
	return 0;
}