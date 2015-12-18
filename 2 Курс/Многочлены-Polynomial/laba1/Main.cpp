#include <iostream>
#include <fstream>
#include "Polynom.h"
#include "StringP.h"
#include "List.h"
#include <array>
using namespace std;
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
		//cout << "Оп.\n";

		//4 лаба
		//StringP stringP = StringP(polynom);
		//stringP.show(stringP);

		cout << endl << "Выберите необходимое действие:\n";
		cout << "1. Увеличить все коэффициенты многочлена на 1\n";
		cout << "2. Уменьшить все коэффициенты многочлена на 1\n";
		cout << "3. Сложить коэффициенты двух многочленов\n";
		cout << "4. Вычесть коэффициента двух многочленов\n";
		cout << "5. Вычислить корни многочлена\n";
		cout << "6. Запись в файл\n";
		//cout << "Лабораторная работа #4 - cодержит в себе класс с массивом степеней и класс с отформатированной строкой многочлена\n";
		//cout << "Нигде не используется за их неудобством\n";
		cout << "Лабораторная работа №5-----------------------\n";
		cout << "7. Создать список многочленов\n";


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
			case 6:
//				printToFile(polynom);
				cout << "Запись в файл";
				system("pause");
				system("cls");
				break;
			case 7:
			{
				List list;
				
				Polynom poly;
				cout << "Введите количество вводимых многочленов >> ";
				int n;
				cin >> n;
				cout << "\nВведите степень многочленов >> ";
				cin >> degree;
				poly.setDegree(degree);

				for (int i = 0; i < n; i++)
				{
					cout << "\n Введите " << i << " многочлен\n";
					cin >> poly;
					list.add(poly);
					cout << endl;
				}
				list.show();
				system("pause");
				//list.show();
				int k;
				cout << "Введите дополнительный многочлен\n";
				cin >> poly; cout << endl;
				cout << "Выберите место вставки >> ";
				cin >> k;
				list.addPos(poly, k);
				cout << endl;
				list.show();

				system("pause");
				system("cls");

				cout << "Введите номер элемента который нужно извлечь: \n";
				cin >> k; cout << endl;
				list.pop(k);
				cout << endl;


				cout << "Введите номер элемента который нужно удалить: \n";
				cin >> k;
				list.del(k);
				cout << endl;
				list.show();
				
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

void printToFile(Polynom polynom)
{
	ofstream f;
	f.open("poly.txt", ios::out); // открываем файл для записи
	if (!f)
	{
		cerr << "Ошибка открытия файла!";
		system("pause");
		system("cls");
	}
	else
	{
		f << polynom; // запишем уравнение в файл
		f << "Конец.";
		cout << polynom;
		cout << "\nЗапись в файл выполнена успешно!";
		system("pause");
		system("cls");
	}
	f.close();
}