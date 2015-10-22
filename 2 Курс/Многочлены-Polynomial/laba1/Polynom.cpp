#include <iostream>
#include <ostream>
#include "Polynom.h"
using namespace std;
using std::ostream;

namespace Program
{
	Polynom::Polynom() {}

	Polynom::~Polynom() {}

	Polynom Polynom::operator++()
	{
		Polynom temp;

		for (int i = degree; i >= 0; i--)
		{
			coefficient[i]++;
			temp.coefficient[i] = coefficient[i];
		}
		return temp;
	}

	Polynom Polynom::operator--()
	{
		Polynom temp;

		for (int i = degree; i >= 0; i--)
		{
			coefficient[i]--;
			temp.coefficient[i] = coefficient[i];
		}
		return temp;
	}

	Polynom Polynom::operator+(Polynom P)
	{
		Polynom result;
		for (int i = degree; i >= 0; i--)
		{
			result.coefficient[i] = coefficient[i] + P.coefficient[i];
			// и одновременная распечатка многочлена
			cout << result.coefficient[i] << "x^" << i;
			if (i != 0)
				cout << " + ";
			else
				cout << " = 0";
		}
		cout << endl << endl;
		return result;
	}

	Polynom Polynom::operator-(Polynom P)
	{
		Polynom result;
		for (int i = degree; i >= 0; i--)
		{
			result.coefficient[i] = coefficient[i] - P.coefficient[i];
			// и одновременная распечатка многочлена
			cout << result.coefficient[i] << "x^" << i;
			if (i != 0)
				cout << " + ";
			else
				cout << " = 0";
		}
		cout << endl << endl;
		return result;
	}

	Polynom Polynom::operator=(Polynom P)
	{
		for (int i = degree; i >= 0; i--)
			coefficient[i] = P.coefficient[i];

		return *this;
	}

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
		if (degree > 2)
		{
			cout << "К сожалению, программа пока не умеет\n считать корни многочленов выше 2 степени.\n";
		}

		if (degree == 2)
		{
			int a = coefficient[2], b = coefficient[1], c = coefficient[0];
			int D = (b*b)-(4*a*c);
			float x1 = (float)(((-b) + D) / (2 * a));
			float x2 = (float)(((-b) - D) / (2 * a));
			Polynom::x1 = x1;
			Polynom::x2 = x2;
			cout << "x1 = " << getX1() << endl;
			cout << "x2 = " << getX2() << endl;
		}

		if (degree == 1)
		{
			float x1 = coefficient[1];
			x1 = (-coefficient[0]) / x1;
			Polynom::x1 = x1;
			cout << "x1 = " << getX1() << endl;
		}
	}

	std::ostream & operator << (std::ostream &stream, Polynom &P)
	{
		stream << "Ваш многочлен:\n\n";
		for (int i = P.getDegree(); i >= 0; i--)
		{
			stream << P.coefficient[i] << "x^" << i;
			if (i != 0)
				stream << " + ";
			else
				stream << " = 0";
		}

		return stream;
	}

	std::istream & operator >> (std::istream &stream, Polynom &P)
	{
		P.setCoefficient();
		return stream;
	}

}