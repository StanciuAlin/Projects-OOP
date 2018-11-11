#pragma once
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
	bool status_ball; //1 - extracted and 0 - unextracted
	
	ball();
	~ball();


private:
	
};
//construct all balls with value in range [1, 49]
void create_loto_balls(std::vector<ball> &loto_balls);
//generate randomly 6 balls
std::vector<int> generate_6_balls(std::vector<ball>& loto_balls);
//generate randomly value in range [1,dom_max]
inline int gen(int dom_max) { return rand() % dom_max + 1; }
