//Date: 29.10.2018
//For test, uncomment the lines with Sleep function! 
#include <time.h>
#include <iostream>
#include "ball.h"
#include "Lotto_Agency.h"



using namespace std;

int main()
{
	srand(time(NULL)); //set time
	Lotto_Agency agency; //array with all balls for Loto extract, initially is empty
	/*int number_balls = NUMBERBALLS;*/
	
	create_loto_balls(agency.loto_balls); //create balls
	
	do
	{
		int option;
		cout << "Options:\n 1 - Buy a new ticket.\n 2 - Start extraction.\n 3 - Exit\n";
		cin >> option;
		switch (option)
		{
		case 1:
		{
			//buy a ticket and register to agency
			Lotto_Ticket ticket_new;
			//set value for 3 fields from tickets
			ticket_new.Set_first_field(generate_6_balls(agency.loto_balls));
			ticket_new.Set_second_field(generate_6_balls(agency.loto_balls));
			ticket_new.Set_third_field(generate_6_balls(agency.loto_balls));
			//add new ticket in Agency list
			agency.tickets.push_back(ticket_new);
			break;
		}
		case 2:
		{
			//show message
			cout << "**************************************************************************\n\n\t\t\t  Extragere Loto 6/49\n\n\n";
			Sleep(2000);
			cout << "\t\t\tSa incepem! Mult noroc!\n\n\n";
			//create extracted balls vector
			agency.extracted_balls = generate_6_balls(agency.loto_balls);
			//show the extracted balls
			for (int i = 0; i < agency.extracted_balls.size(); i++)
			{
				std::cout << "\t\t     S-a extras bila cu numarul: " << agency.extracted_balls[i] << '\n';
				Sleep(1000);
			}
			cout << "\t\tExtragerea Loto 6/49 s-a sfarsit cu succes!\n\n";
			cout << "**************************************************************************\n";
			int id_winner = agency.check_win(agency.tickets, agency.extracted_balls);
			if (id_winner)
			{
				cout << "\t\tWIN!!!!! Ticket with number " << id_winner << "! Congratulations!\nfield1\n";
				char _option2;
				cout << "If you want to view the winning ticket please type y else type n\n";
				cin >> _option2;
				switch (_option2)
				{
				case 'y':
				{
					//print the winning ticket if it exist
					cout << "Numbers from first field are: \n";
					for (int i = 0; i < BALL_FOR_EXTRACT; i++)
					{
						cout << agency.tickets[id_winner].Get_first_field().at(i) << ' ';
					}
					cout << "Numbers from second field are:\n";
					for (int i = 0; i < BALL_FOR_EXTRACT; i++)
					{
						cout << agency.tickets[id_winner].Get_second_field().at(i) << ' ';
					}
					cout << "Numbers from third field are:\n";
					for (int i = 0; i < BALL_FOR_EXTRACT; i++)
					{
						cout << agency.tickets[id_winner].Get_third_field().at(i) << ' ';
					}
					break;
				}
				case 'n':
				{
					cout << "Thank you for participating!\n";
				}
				default:
				{
					exit(0);
				}
				}
			}
			else
			{
				cout << "There is not winner! :(\n";
				//exit(0);
			}
			break;
		}
		case 3:
		{
			exit(0);
		}
		default:
			break;
		}
	} while (1);
	return 0;
}