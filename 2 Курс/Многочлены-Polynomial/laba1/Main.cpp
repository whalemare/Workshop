#include <iostream>
#include "Polynom.h"
using namespace std;
using Program::Polynom;

int main()
{
	Polynom polynom;

	setlocale(LC_ALL, "Russian");

	int degree; // степень многочлена
	cout << "Введите порядок многочлена: ";
	cin >> degree;
	polynom.setDegree(degree);
	
	cout << "Введите коэффициенты: " << endl;
	polynom.setCoefficient();
	
	system("cls");
	polynom.printPolynom(); // Распечатаем наш  многочлен

	polynom.answering();

	system("pause");
	return 0;
}