#include "ComplexNumber.h"
#include <iostream>


ComplexNumber::~ComplexNumber()
{
}

void ReadData(std::vector<ComplexNumber>& exp)
{
	int n;
	std::cout << "Numarul de coeficienti este: ";
	std::cin >> n;
	ComplexNumber z;
	for (int i = 0; i < n; i++)
	{
		std::cout << "Perechea de numere (real, imaginar) este: ";
		std::cin >> z.x >> z.y;
		exp.push_back(z);
	}
}

void PrintComplexNumber(ComplexNumber& z)
{
	std::cout << "Numarul complex este: " << z.x << " + " << z.y << "*i\n";
}
