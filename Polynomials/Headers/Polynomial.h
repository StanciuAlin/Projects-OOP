#pragma once
#include <vector>
#include <iostream>


class Polynomial
{
	int degree;
	std::vector<double> coef_Polynomial;

public:
	Polynomial();
	Polynomial(int degree) {
		this->degree = degree; 
		for (size_t i = 0; i < degree + 1; i++)
		{
			this->coef_Polynomial.push_back(0);
		}
	}
	~Polynomial();
	friend void ReadPolynomialData(Polynomial & P);
	friend void PrintPolynomial(Polynomial & P);

	Polynomial& operator=(const Polynomial& z) // copy assignment
	{
		if (this == &z)
		{
			return *this;
		}
		if (this->degree == z.degree)
		{
			for (int i = 0; i < degree + 1; i++)
			{
				this->coef_Polynomial[i] = z.coef_Polynomial[i];
			}
			return *this;
		}
		
	}

	friend Polynomial operator+(const Polynomial & Q, const Polynomial & P);
	double & operator[](const int location) throw (const char *);
	double & operator()(const double x);
};

void ReadPolynomialData(Polynomial & P);
void PrintPolynomial(Polynomial & P);