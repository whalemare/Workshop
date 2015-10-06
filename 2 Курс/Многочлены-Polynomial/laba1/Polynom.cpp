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
			cout << "Решением вашего уравнения является: " << degree << " = " << degree << endl;
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
		cout << "Ваш многочлен: \n\n";
		for (int i = degree; i >= 0; i--)
		{
			if (coefficient[i] != 0)
				if (i == 1)
					cout << coefficient[i] << "x";
				else
					if (i == 0)
						cout << coefficient[i];
					else
						cout << coefficient[i] << "x^" << i;
			if (i != 0)
				cout << " + ";
			else
				cout << " = 0";
		}
		cout << endl << endl;
	}

	int Polynom::getDegree()
	{
		return Polynom::degree;
	}

	float Polynom::getX1()
	{
		return Polynom::x1;
	}

	float Polynom::getX2()
	{
		return Polynom::x2;
	}

	void Polynom::answering() // решает уравнение
	{
		if (degree == 2)
		{
			int a = coefficient[2], b = coefficient[1], c = coefficient[0];
			int D = (b*b)-(4*a*c);
			float x1 = (float)(((b - 2 * b) + D) / (2 * a));
			float x2 = (float)(((b - 2 * b) - D) / (2 * a));
			Polynom::x1 = x1;
			Polynom::x2 = x2;
		}
	}
}