#include "Utils.h"
#include "ComplexNumber.h"
#include <iostream>

bool Start()
{
	std::vector<ComplexNumber> input;
	ReadData(input);
	ComplexNumber odd_exp(0,0);
	ComplexNumber even_exp(0,0);

	for (int i = 0; i < input.size(); i++)
	{
		if (i % 2 == 0)
		{
			even_exp = even_exp + input[i].operator^(3);
		}
		if (i % 2 == 1)
		{
			odd_exp = odd_exp + input[i].operator^(4);
		}
	}
	ComplexNumber res;
	
	if (odd_exp.x != 0 && odd_exp.y != 0)
	{
		res = even_exp / odd_exp;
		std::cout << "Rezultatul expresiei este: " << res.x << " + (" << res.y << ")*i\n";
	}
	else
	{
		std::cout << "Divided by 0!\n";
	}

	return false;
}
