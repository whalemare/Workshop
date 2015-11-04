#pragma once
#include <stdio.h>
#include <iostream>

using namespace std;

class Mass {
private:
	int *buf; // указатель на элемент массива
	int sz; // размер массива
public:
	Mass(); // конструктор по умолчанию
	Mass(int); // конструктор с параметром
	Mass(Mass &); // конструкто копирования
	~Mass(); // деструктор

	friend istream &operator>>(istream&, Mass&); //перегруженный оператор для ввода массива
	friend ostream &operator<<(ostream&, const Mass&); //перегруженный оператор для вывода массива

	Mass operator=(const Mass&); //перегруженный оператор присваивания
	int operator[](int); //для возможности удобно обращаться к элементам массива. Например mas[2];
	
	int getSize(); // получить размер массива
	int find(int); // найти элемент в массиве
	void del(int); // удалить элемент по индексу
	void ins(int, int); // вставка
	void rep(int, int); // замена
	
	Mass operator++(); // перегрузка оператора - инкремент
	Mass operator+(Mass); // перегрузка оператора сложения
	friend Mass operator-(Mass, Mass ); // перегрузка оператор разности 
};