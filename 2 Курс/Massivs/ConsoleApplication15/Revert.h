#pragma once
#include "Mass.h"
#include <queue>  // подключаем заголовочный файл очереди

class Revert
{
private:
	int size;
	int *buf;
	queue<int> queque;

public:
	Revert();
	~Revert();

	void entered(int);

	int getFront();

	int getBack(); // mazafaka

	void print();

	Revert(int); // инициализация
};

