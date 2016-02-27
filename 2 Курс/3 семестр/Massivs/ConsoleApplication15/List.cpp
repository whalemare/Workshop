#include "stdafx.h"
#include "List.h"


List::~List()
{
	while (HEAD != NULL) // Пока по адресу хоть что-то есть
	{
		Mass *temp = HEAD -> Next; // Запишем указатель на адрес следующего элемента структуры
		delete HEAD; // Освобождаем память по месту начала списка
		HEAD = temp; // Меняем адрес начала списка
	}
}

void List::add(Mass &mass)
{
	Mass *temp = new Mass(); // Выделяем память под новый объект 
	temp->Next = HEAD; // меняем адрес начала списка 


	temp->sz = mass.sz; // копируем размер массива в созданную переменную
	for (int i = 0; i < mass.sz; i++) // копируем элементы массива
		temp->buf[i] = mass.buf[i];

	size++; // увеличиваем переменную хранящую размер на 1
	HEAD = temp; // меняем адрес начала списка
}

void List::addPos(Mass mass, int pos)
{
	if (pos == 0) // вставка в начало
		add(mass);
	if (pos > 0 && pos < size)
	{
		Mass* newmass = new Mass();
		newmass->sz = mass.sz; // копируем размер массива в созданную переменную
		for (int i = 0; i < mass.sz; i++) // копируем элементы массива
			newmass->buf[i] = mass.buf[i];

		Mass* temp = new Mass(), *prev=NULL;
		
		temp = HEAD;
		for (int i = 0; i < pos; i++)
		{
			prev = temp;
			temp = temp->Next;
		}
		prev->Next = newmass;
		//newmass->Next = temp;
		size++;
	}
	// вставка в конце (0, 1, 2, 3 => size = 4)
	if (pos = size) 
	{
		Mass* newlink = new Mass();
		newlink->sz = mass.sz; // копируем размер массива в созданную переменную
		for (int i = 0; i < mass.sz; i++) // копируем элементы массива
			newlink->buf[i] = mass.buf[i];
		newlink->Next = NULL;

		Mass* temp = new Mass();

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
	Mass *temp = HEAD; // объявляем указатель и пусть он указывает на начало списка
	int i = 0;

	while (temp != NULL) // пока есть на что указывать
	{
		cout << i << " массив: ";
		for (int i = 0; i < temp->sz; i++)
			cout << temp->buf[i] << " ";
		cout << endl;
		temp = temp->Next;
		i++;
	}
}

void List::pop(int n)
{
	Mass *temp = HEAD; // обращаемся к началу списка

	if ((HEAD != NULL) && (n <= size) && (n>=0)) // если по этому номеру что-то лежит и этот элемент внутри списка
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
		Mass *temp = HEAD->Next; // Запишем указатель на адрес следующего элемента структуры
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
		Mass *temp = HEAD, *prev = HEAD;

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