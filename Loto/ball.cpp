#include "ball.h"


ball::ball()
{
	this->status_ball = false; //at beginning, the ball has unextracted status
}

ball::~ball()
{
}

void create_loto_balls(std::vector<ball> &loto_balls)
{

	for (int i = 0; i < NUMBERBALLS; i++)
	{
		//create a new object ball
		ball b;
		//set ball value
		b.value = i + 1;
		//add object to loto balls
		//loto_balls[i] = b;
		loto_balls.push_back(b);
	}
}

std::vector<int> generate_6_balls(std::vector<ball>& loto_balls)
{
	std::vector<ball> copy(loto_balls); //temporary vector to make modifications (erase values)
	std::vector<int> result_balls; //collect all generated balls
	int number_balls = NUMBERBALLS;
	//for (int i = 0; i < BALL_FOR_EXTRACT; i++)
	int i = 0;
	while(result_balls.size() < BALL_FOR_EXTRACT )
	{
		int val = gen(number_balls); //generate a number from all existent Loto balls
		//find the ball with value equals with val
		for (int j = 0; j < number_balls; j++)
		{
			if (copy[j].value == val) { //if the ball is found in balls, then delete it
				//delete the ball and insert in solution vector
				result_balls.push_back(val);
				for (int k = j; k < number_balls - 1; k++)
				{
					copy[k] = copy[k + 1];
				}
				//decrement number of possible ball to extract

				number_balls--;
				break;
			}
		}
	}
	//std::cout << "\n\n\n";
	return result_balls;
}
