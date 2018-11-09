#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include <Windows.h>


#define NUMBERBALLS 49
#define BALL_FOR_EXTRACT 6

class ball
{
public:
	int value;
	int status_ball;
	enum status
	{
		extracted,
		unextracted
	};
	
	ball();
	~ball();


private:
	
};

void create_loto_balls(std::vector<ball> &loto_balls, int number_balls);
void generate_6_balls(HANDLE hConsole, std::vector<ball> &loto_balls, int& number_balls);
inline int gen(int dom_max) { return rand() % dom_max + 1; }
