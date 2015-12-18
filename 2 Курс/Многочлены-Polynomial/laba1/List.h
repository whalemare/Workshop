#pragma once
#include "Polynom.h"
class List
{
private:
	Polynom *HEAD; // указатель на начало списка масс
public:
	List() :HEAD(NULL) {};
	~List();

	int size; // размер массива
	void add(Polynom &polynom); // функция добавления элемента
	void addPos(Polynom polynom, int pos); // функция добавления элемента по заданному номеру
	void show(); // функция распечатки списка
	void del(int n); // функци удаления элемента из списка; n = номер элемента
	void pop(int n); // получаем элемент из списка; n = номер элемента
	void clear(); // очистить весь список
	int getSize(); // узнать размер списка
};

