#include "Lotto_Agency.h"
#include "ball.h"

#include <algorithm>

Lotto_Agency::Lotto_Agency()
{
}

Lotto_Agency::~Lotto_Agency()
{
}

std::vector<int> Lotto_Agency::buy_ticket(std::vector<ball>& loto_balls)
{
	std::vector<int> field;
	field = generate_6_balls(loto_balls);
	return field;
}

int Lotto_Agency::check_win(std::vector<Lotto_Ticket> _tickets, std::vector<int> _extracted_balls)
{
	int number_winners = 0;
	int winner = 0;
	
	for (int i = 0; i < _tickets.size(); i++)
	{
		//std::sort(_tickets[i].Get_first_field().begin(), _tickets[i].Get_first_field().end());
		bool ok_field1 = true;
		for (int k = 0; k < _extracted_balls.size(); k++) //search for every extracted ball in every field
		{
			bool find = false;
			for (int t = 0; t < _tickets[i].Get_first_field().size(); t++) //go through all field
			{
				if (_extracted_balls[k] == _tickets[i].Get_first_field().at(t)) //if a ball extracted is identified in field, mark the fact is found
				{
					find = true;
					break;
				}
			}
			if (!find) //if the ball is not in extracted balls, then give up to searh in this field
			{
				ok_field1 = false;
				break;
			}
			else //if the ball exist in extracted balls, then go on
			{
				continue;
			}
			/*if (!std::binary_search(_tickets[i].Get_first_field().begin(), _tickets[i].Get_first_field().end(), _extracted_balls[k]))
			{
				ok1 = false;
				break;
			}*/
		}

		bool ok_field2 = true;
		for (int k = 0; k < _extracted_balls.size(); k++)
		{
			bool find = false;
			for (int t = 0; t < _tickets[i].Get_second_field().size(); t++)
			{
				if (_extracted_balls[k] == _tickets[i].Get_second_field().at(t))
				{
					find = true;
					break;
				}
			}
			if (!find)
			{
				ok_field2 = false;
				break;
			}
			else
			{
				continue;
			}
			
		}

		bool ok_field3 = true;
		for (int k = 0; k < _extracted_balls.size(); k++)
		{
			bool find = false;
			for (int t = 0; t < _tickets[i].Get_third_field().size(); t++)
			{
				if (_extracted_balls[k] == _tickets[i].Get_third_field().at(t))
				{
					find = true;
					break;
				}
			}
			if (!find)
			{
				ok_field3 = false;
				break;
			}
			else
			{
				continue;
			}
		}
		//if one of the ticket's field contains all extracted balls,
		//then increase number of winners and retain the last winner
		if (ok_field1 || ok_field2 || ok_field3)  
		{
			number_winners++;
			winner = i;
		}
	}
	return winner;
}

Lotto_Ticket::Lotto_Ticket()
{
	first_field = { 0 };
	second_field = { 0 };
	third_field = { 0 };
}

Lotto_Ticket::~Lotto_Ticket()
{
}
