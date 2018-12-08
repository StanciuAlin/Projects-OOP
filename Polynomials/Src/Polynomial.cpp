#include "Polynomial.h"
#include "Utils.h"
#include <math.h>

#define max(a, b) (a > b) ? a : b

Polynomial::Polynomial()
{
}

Polynomial::~Polynomial()
{
	coef_Polynomial.resize(coef_Polynomial.size(), 0);
}

double & Polynomial::operator[](const int location) throw(const char *)
{
	// TODO: insert return statement here
	if (location < 0 || location >= this->coef_Polynomial.size()) throw "Invalid array access";
	else return this->coef_Polynomial.at(location);
}

double & Polynomial::operator()(const double x)
{
	// TODO: insert return statement here
	double res = 0.0;
	for (int i = this->coef_Polynomial.size() - 1; i >= 0; i--)
	{
		res = res + this->coef_Polynomial.at(i) * pow(x, i);
	}
	return res;
}

void ReadPolynomialData(Polynomial & P)
{
	double temp;
	std::cout << "Coeficientii polinomului sunt: (in ordinea xn xn-1 xn-2 ... x1 x0) ";
	for (size_t i = 0; i < P.degree + 1; i++)
	{
		std::cin >> temp;
		P.coef_Polynomial[i] = temp;
	}

}

void PrintPolynomial(Polynomial & P)
{
	int temp_degree = P.degree;
	int i;

	std::cout << "Polinomul dorit este:   ";
	std::reverse(P.coef_Polynomial.begin(), P.coef_Polynomial.end());
	for (i = 0; i < P.degree - 1; i++)
	{
		(P.coef_Polynomial[i+1] >= 0) ? (std::cout << P.coef_Polynomial[i] << "*X^" << temp_degree << "+") : (std::cout << P.coef_Polynomial[i] << "*X^" << temp_degree);
		temp_degree--;
	}
	std::cout << P.coef_Polynomial[i++] << "*X";
	(P.coef_Polynomial[i] >= 0 ) ? std::cout << "+" << P.coef_Polynomial[i] : std::cout << P.coef_Polynomial[i];
	std::cout << '\n';
	std::reverse(P.coef_Polynomial.begin(), P.coef_Polynomial.end());

}

Polynomial operator+(const Polynomial & Q, const Polynomial & P)
{
	Polynomial R(max(Q.degree, P.degree));
	int k = 0;
	if (Q.degree > P.degree)
	{
		int P_length = P.degree;
		for (int i = Q.degree; i > 0 && P_length >= 0; i--)
		{
			R.coef_Polynomial[k] = Q.coef_Polynomial[i] + P.coef_Polynomial[P_length];
			k++;
			P_length--;
		}
		for (int i = Q.degree - P.degree - 1; i >= 0; i--)
		{
			R.coef_Polynomial[k] = Q.coef_Polynomial[i];
			k++;
		}
	}
	if (Q.degree == P.degree)
	{
		int P_length = P.degree;
		for (int i = Q.degree; i >= 0 && P_length >= 0; i--)
		{
			R.coef_Polynomial[k] = Q.coef_Polynomial[i] + P.coef_Polynomial[P_length];
			k++;
			P_length--;
		}
	}
	return R;
}