
#pragma once
#include "standard_ISBN.h"
#include <string>

class book
{
public:
	//getter
	std::string Get_title_book() const { return title_book; }
	std::string Get_author_book() const { return author_book; }
	std::string Get_publishing_book() const { return publishing_book; }
	Standard_ISBN Get_ISBN_book() const { return ISBN_book; }
	float Get_price_book() const { return price_book; }
	int Get_year_appearance() const { return year_appearance; }
	//setter
	void Set_title_book(std::string title) { title_book = title; }
	void Set_author_book(std::string autour) { author_book = autour; }
	void Set_publishing_book(std::string publishing) { publishing_book = publishing; }
	void Set_ISBN_book(Standard_ISBN ISBN) { ISBN_book = ISBN; }
	void Set_price_book(float price) { price_book = price; }
	void Set_year_appearance(int year) { year_appearance = year; }
	

	book(std::string title, std::string author, std::string publishing, Standard_ISBN ISBN, int year, float price) : title_book(title), author_book(author), publishing_book(publishing), ISBN_book(ISBN), year_appearance(year), price_book(price) {}
	~book();

private:
	std::string title_book;
	std::string author_book;
	std::string publishing_book;
	Standard_ISBN ISBN_book;
	int year_appearance;
	float price_book;
};