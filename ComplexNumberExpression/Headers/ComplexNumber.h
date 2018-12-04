#pragma once
#include <math.h>
#include <vector>


class ComplexNumber
{
	
public:
	double x; //real part of complex number
	double y; //imaginary part of complex number
	
	//ComplexNumber(); //implicit constructor
	~ComplexNumber();

	ComplexNumber(double x1 = 0, double y1 = 0) : x(x1), y(y1) {} //general constructor

	ComplexNumber(const ComplexNumber& z) { x = z.x; y = z.y; } //copy constructor

	ComplexNumber& operator=(const ComplexNumber& z) // copy assignment
	{
		x = z.x;
		y = z.y;
		return *this;
	}

	ComplexNumber operator+(ComplexNumber const &z) { //+ operator
		ComplexNumber res;
		res.x = x + z.x;
		res.y = y + z.y;
		return res;
	}

	ComplexNumber operator-(ComplexNumber const &z) { //- operator
		ComplexNumber res;
		res.x = x - z.x;
		res.y = y - z.y;
		return res;
	}

	ComplexNumber operator*(ComplexNumber const &z) { //- operator
		ComplexNumber res;
		res.x = (x * z.x) - (y * z.y);
		res.y = (x * z.y) + (y * z.x);
		return res;
	}
	ComplexNumber operator/(ComplexNumber const &z) { //- operator
		ComplexNumber res;
		res.x = x / z.x;
		res.y = y / z.y;
		return res;
	}
	double operator~()
	{
		double res;
		res = (x * x) + (y * y);
		return res;
	}
	ComplexNumber operator^(int power)
	{
		/*double res = 1.0;
		for (int i = 0; i < power; i++)
		{
			res *= rho;
		}
		res = res * (cos(phi * power) + sin(phi * power));*/
		ComplexNumber res(1, 0);
		for (int i = 0; i < power; i++)
		{
			res = res * (*this);
		}
		return res;
	}
};

void ReadData(std::vector<ComplexNumber>& exp);
void PrintComplexNumber(ComplexNumber& z);
