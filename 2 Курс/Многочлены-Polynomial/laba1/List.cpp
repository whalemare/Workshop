#include "List.h"
#include <iostream>
using namespace std;
List::~List()
{
	while (HEAD != NULL) // Пока по адресу хоть что-то есть
	{
		Polynom *temp = HEAD->Next; // Запишем указатель на адрес следующего элемента структуры
		delete HEAD; // Освобождаем память по месту начала списка
		HEAD = temp; // Меняем адрес начала списка
	}
}

void List::add(Polynom &polynom)
{
	Polynom *temp = new Polynom(); // Выделяем память под новый объект 
	temp->Next = HEAD; // меняем адрес начала списка 

	temp->degree = polynom.degree;
	for (int i = 0; i <= polynom.getDegree(); i++)
		temp->coefficient[i] = polynom.coefficient[i];
	cout << *temp; // покажем что записалось

	size++; // увеличиваем переменную хранящую размер на 1
	HEAD = temp; // меняем адрес начала списка
}

void List::addPos(Polynom polynom, int pos)
{
	if (pos == 0) // вставка в начало
		add(polynom);
	if (pos > 0 && pos < size)
	{
		Polynom* newPolynom = new Polynom();
		newPolynom->degree = polynom.degree;
		newPolynom->coefficient = polynom.coefficient;

		Polynom* temp = new Polynom(), *prev = NULL;

		temp = HEAD;
		for (int i = 0; i < pos; i++)
		{
			prev = temp;
			temp = temp->Next;
		}
		prev->Next = newPolynom;
		//newmass->Next = temp;
		size++;
	}
	// вставка в конце (0, 1, 2, 3 => size = 4)
	if (pos = size)
	{
		Polynom* newlink = new Polynom();

		newlink->degree = polynom.degree;
		newlink->coefficient = polynom.coefficient;

		newlink->Next = NULL;

		Polynom* temp = new Polynom();

		if (HEAD != NULL)
		{
			temp = HEAD;
			while (temp->Next != NULL)
			{
				temp = temp->Next;
			}
			temp->Next = newlink;
		}
		else
			HEAD = newlink;
	}
	else
	{
		cout << "Невозможно";
		return;
	}
	size++;
}

void List::show()
{
	Polynom *temp = HEAD; // объявляем указатель и пусть он указывает на начало списка
	int i = 0;

	while (temp != NULL) // пока есть на что указывать
	{
		cout << i << " полином: ";
		cout << *temp;
		cout << endl << endl;

		cout << endl;
		temp = temp->Next;
		i++;
	}
}

void List::pop(int n)
{
	Polynom *temp = HEAD; // обращаемся к началу списка

	if ((HEAD != NULL) && (n <= size) && (n >= 0)) // если по этому номеру что-то лежит и этот элемент внутри списка
	{
		for (int i = 0; i < n; i++)
			temp = temp->Next;
		cout << *temp;
	}
}

void List::clear()
{
	while (HEAD != NULL) // Пока по адресу хоть что-то есть
	{
		Polynom *temp = HEAD->Next; // Запишем указатель на адрес следующего элемента структуры
		delete HEAD; // Освобождаем память по месту начала списка
		HEAD = temp; // Меняем адрес начала списка
	}
}

int List::getSize()
{
	return size;
}

void List::del(int n)
{
	if ((HEAD != NULL) && (n < size) && (n >= 0)) // если по этому номеру что-то лежит и этот элемент внутри списка
	{
		Polynom *temp = HEAD, *prev = HEAD;

		for (int i = 0; i < n; i++)
		{
			prev = temp; // предыдущее значение temp
			temp = temp->Next;
		}

		if (temp == HEAD) // если элемент первый
			HEAD = temp->Next;
		else
			prev->Next = temp->Next;

		cout << "\nУдаляемый элемент: " << *temp;
		delete temp;
		size--;
	}
}