#include "stdafx.h"
#include "Mass.h"
#include "Revert.h"
#include "Cycle.h"
#include <stdlib.h> // для system("pause");
#include <locale.h> // для русской консоли
#include <stdio.h>
#include "List.h"
#include <iostream>
#include <fstream> // для файла
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	/*
	int n; 

	cout << "Введите размер массивов: ";

	cin >> n;
	Mass x(n);

	cout << "Введите элементы массива 1:\n ";
	cin >> x;
	cout << "Массив: " << x << endl << endl;


	int a;
	cout << "Найти элемент равный: ";
	cin >> a;
	cout << "Элемент номер " << x.find(a) << endl << endl;

	cout << "Удалить элемент с индексом ";
	cin >> a;
	x.del(a);
	cout << "Массив: " << x << endl << endl;

	int b;
	cout << "Вставить элемент ";
	cin >> a;
	cout << "Под индексом ";
	cin >> b;
	x.ins(b, a);
	cout << "Массив: " << x << endl << endl;

	cout << "Заменить элемент индекса: ";
	cin >> b;
	cout << "Элементом: ";
	cin >> a;
	x.rep(b, a);
	cout << "Массив: " << x << endl << endl;


	cout << "Увеличить все элементы массива на 1\n" ;
	cout << ++x;



	Mass x2(n);
	cout << "\nВведите элементы массива 2:\n";
	cin >> x2;
	cout << "Массив: " << x2 << endl << endl;

	cout << "Cложить два массива\n";
	cout << x + x2;

	cout << "\nВычесть элементы второго массива из элементов первого массива\n";
	cout << x - x2;

	cout << "Распечатаем значения второго массива в файл mass.txt\n";
	ofstream f; 
	// открываем файл для записи
	f.open("mass.txt");
	if (!f)
	{
		cerr << "Ошибка открытия файла";
		system("pause");
		system("cls");
	}
	else
		f << x2;
	f.close();

	cout << "Введем в новый массив значения из файла mass.txt\n";
	Mass newMas;
	ifstream ifs;
	ifs.open("mass.txt");
	if (!ifs)
	{
		cerr << "Ошибка открытия файла";
		system("pause");
		system("cls");
	}
	else
		ifs >> newMas;
	system("pause");
	cout << endl << endl << (newMas=x2);

	cout << "Лабораторная работа №4\n";
	int sizeMassiv;
	cout << "Создаем циклический массив размером: "; cin >> sizeMassiv;
	Cycle cycleMass(sizeMassiv);
	cout << "Введем в него N-ое кол-во цифр. \nВведите число большее его размера, чтобы увидеть работу циклического массива.\n";
	int nNumbers; // кол-во вводимых цифр
	cin >> nNumbers;
	cycleMass.add(nNumbers);

	cout << endl;
	cout << "\n Ваш массив: " << cycleMass;
	system("pause");
	system("cls");

	cout << "Создаем массив-очередь размером: "; cin >> sizeMassiv;
	Revert revetMass;
	revetMass.entered(sizeMassiv);
	system("cls");

	cout << "Первый в очереди: " << revetMass.getFront() << endl;

	cout << "Последний в очереди: " << revetMass.getBack() << endl;

	cout << "Вся очередь списком: \n";
	revetMass.print();

	*/

cout << "Лабораторная работа №5\n\n";

List list; // объявили объект список;
int n; // размер массива
int k; // число массивов

cout << "Введите количество вводимых массивов: ";
cin >> k;

cout << "Введите размеры массивов: ";
cin >> n;
Mass massiv(n); // создаем объект массив

for (int i = 0; i < k; i++)
{
	cin >> massiv; // вводим элементы массива
	list.add(massiv); // заносим их в список
}

cout << endl;
list.show(); // выводим наш список элементов


	cout << "Введите номер элемента который нужно извлечь: \n";
	cin >> n; cout << endl;
	list.pop(n);
	cout << endl;


//	cout << "Введите номер элемента который нужно удалить: \n";
//	cin >> n;

	cout << endl;
	list.clear();
	cout << "Удалили список\n";
	list.show();



	system("pause");
	return 0;
}

