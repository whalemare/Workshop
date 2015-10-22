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
	cin >> polynom;

	bool flag = true;
	while (flag == true) // цикл будет выполняться, пока мы не изменим значение flag на false
	{
		cout << "Вы работаете с данным многочленом:\n";
		cout << polynom; // Распечатаем наш  многочлен
		cout << endl << "Выберите необходимое действие:\n";
		cout << "1. Увеличить все коэффициенты многочлена на 1\n";
		cout << "2. Уменьшить все коэффициенты многочлена на 1\n";
		cout << "3. Сложить коэффициенты двух многочленов\n";
		cout << "4. Вычесть коэффициента двух многочленов\n";
		cout << "5. Вычислить корни многочлена\n";


		cout << "Введите 0, чтобы выйти из программы.\n\n>> ";

		int num; // для выбора пункта меню
		cin >> num;

		switch (num) 
		{
			case 1:
			{
				++polynom;
				system("cls");
				break;
			}
			case 2:
			{
				--polynom;
				system("cls");
				break;
			}
			case 3:
			{
				Polynom polynom2, resultt;
				polynom2.setDegree(polynom.getDegree());
				cout << "Введите коэффициенты для второго многочлена: " << endl;
				polynom2.setCoefficient();
				system("cls");
				cout << "Сумма двух многочленов\n";
				cout << polynom; cout << endl;
				cout << polynom2; cout << endl << endl;
				(polynom + polynom2);
				system("pause");
				system("cls");
				break;
			}
			case 4:
			{
				Polynom polynom2, resultt;
				polynom2.setDegree(polynom.getDegree());
				cout << "Введите коэффициенты для второго многочлена: " << endl;
				polynom2.setCoefficient();
				system("cls");
				cout << "Разность двух многочленов\n";
				//polynom.printPolynom(); cout << endl; // Теперь это не нужно
				cout << polynom << endl << endl;
				cout << polynom2 << endl << endl;
				(polynom - polynom2);
				system("pause");
				system("cls");
				break;
			}

			case 5:
			{
				polynom.answering();
				system("pause");
				system("cls");
				break;
			}
			case 0: 
			{
				return 0;
				break;
			}
			default:
			{
				flag = false; // выходим из цикла
				return 0;
			}
		}
	}

	system("pause");
	return 0;
}