//Date: 29.10.2018
//For test, uncomment the lines with Sleep function! 
#include <time.h>
#include <iostream>
#include "ball.h"

using namespace std;

int main()
{
	srand(time(NULL)); //set time
	std::vector<ball> loto_balls(NUMBERBALLS); //array with all balls for Loto extract, initially is empty
	int number_balls = NUMBERBALLS;
	create_loto_balls(loto_balls, number_balls); //create balls
	
	//set Console text color
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	//show message
	cout << "**************************************************************************\n\n\t\t\t  Extragere Loto 6/49\n\n\n";
	//Sleep(2000);
	cout << "\t\t\tSa incepem! Mult noroc!\n\n\n";
	generate_6_balls(hConsole, loto_balls, number_balls);
	
	cout << "\t\tExtragerea Loto 6/49 s-a sfarsit cu succes!\n\n";
	SetConsoleTextAttribute(hConsole, 10);
	cout << "**************************************************************************\n";
	//Sleep(5000);

	//for (int i = 0; i < number_balls; i++)
	//{
	//	cout << loto_balls[i].value << ' ' << loto_balls[i].status_ball << '\n';
	//}

	return 0;
}