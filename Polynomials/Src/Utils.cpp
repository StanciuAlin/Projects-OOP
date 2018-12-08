#include "Utils.h"
#include "Polynomial.h"
#include <iostream>
#define max(a, b) (a > b) ? a : b

bool StartProgram()
{
	int degree1, degree2;
	std::cout << "Gradul primului polinom este: ";
	std::cin >> degree1;
	std::cout << "Gradul celui de al doilea polinom este: ";
	std::cin >> degree2;
	Polynomial P(degree1);
	ReadPolynomialData(P);
	Polynomial Q(degree2);
	ReadPolynomialData(Q);
	Polynomial R(max(degree1, degree2));
	//+ operator demo
	if (degree1 >= degree2)
	{
		R = P + Q;
	}
	else
	{
		R = Q + P;
	}
	//() operator demo
	std::cout << "R(2) = " << R(2) << '\n';
	//[] operator demo
	std::cout << "R[1] = " << R[1] << '\n';
	//R.operator=(P + Q);
	PrintPolynomial(R);
	return false;
}


