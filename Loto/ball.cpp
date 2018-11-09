#include "ball.h"


ball::ball()
{
	this->status_ball = ball::status::unextracted; //at beginning, the ball has unextracted status
}

ball::~ball()
{
}

void create_loto_balls(std::vector<ball> &loto_balls, int number_balls)
{

	for (int i = 0; i < number_balls; i++)
	{
		/*loto_balls[i].value = i;
		loto_balls[i].status_ball = ball::status::extracted;*/

		//create a new object ball
		ball b;
		//set ball value
		b.value = i + 1;

		//add object to loto balls
		loto_balls[i] = b;
	}
}

void generate_6_balls(HANDLE hConsole, std::vector<ball>& loto_balls, int& number_balls)
{
	int k_console = 5; //iterator for console color
	for (int i = 0; i < BALL_FOR_EXTRACT; i++)
	{
		int val = gen(number_balls); //generate a number from all existent Loto balls
		
		//Sleep(2000);
		SetConsoleTextAttribute(hConsole, k_console); //set color for text in Console
		//find the ball with value equals with val
		for (int j = 0; j < number_balls; j++)
		{
			if (loto_balls[j].value == val) { //if the ball is found in balls, then delete it
				//delete the ball
				std::cout << "\t\t     S-a extras bila cu numarul: " << loto_balls[j].value << '\n';
				for (int k = j; k < number_balls - 1; k++)
				{
					loto_balls[k] = loto_balls[k + 1];
				}
				//decrement number of possible ball to extract
				number_balls--;
				break;
			}
		}
		k_console++; //chage the color for next ball
	}
	std::cout << "\n\n\n";
}
