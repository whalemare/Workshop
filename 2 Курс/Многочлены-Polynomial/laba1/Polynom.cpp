#include <iostream>
#include "Polynom.h"
using namespace std;

namespace Program
{
	Polynom::Polynom() {}

	Polynom::~Polynom() {}

	void Polynom::setDegree(int degree)
	{
		if (degree == 0) {
			cout << "Степень указана неверно" << endl;
			exit;
		}
		else
			Polynom::degree = degree;
	}

	void Polynom::setCoefficient()
	{
		for (int i = degree; i >= 0; i--) // запросим все коэффициенты на ввод
		{
			cout << "x^" << i << " >> ";
			cin >> coefficient[i];
			cout << endl;
		}
	}

	void Polynom::printPolynom()
	{
		for (int i = degree; i >= 0; i--)
		{
			if (coefficient[i] != 0)
				cout << coefficient[i] << "x^" << i - 1 << "+";
		}
	}

	int Polynom::getDegree()
	{
		return Polynom::degree;
	}
}