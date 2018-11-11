#pragma once
#include <vector>
#include "ball.h"

class Lotto_Ticket
{
public:
	Lotto_Ticket();
	~Lotto_Ticket();
	//getters
	std::vector<int> Get_first_field() const { return first_field; }
	std::vector<int> Get_second_field() const { return second_field; }
	std::vector<int> Get_third_field() const { return third_field; }
	//setters
	void Set_first_field(std::vector<int> field1) { first_field = field1; }
	void Set_second_field(std::vector<int> field2) { second_field = field2; }
	void Set_third_field(std::vector<int> field3) { third_field = field3; }
private:
	std::vector<int> first_field;
	std::vector<int> second_field;
	std::vector<int> third_field;
	
};

class Lotto_Agency
{
public:
	std::vector<Lotto_Ticket> tickets; //retain all tickets registered in Agency
	std::vector<ball> loto_balls; //all balls possibly to be extracted
	std::vector<int> extracted_balls; //balls extracted
	
	Lotto_Agency();
	~Lotto_Agency();
	std::vector<int> buy_ticket(std::vector<ball>& loto_balls);
	int check_win(std::vector<Lotto_Ticket> _tickets, std::vector<int> _extracted_balls);
private:

};


