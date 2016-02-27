#pragma once
#include "Mass.h"
#include <queue>  // подключаем заголовочный файл очереди

class Revert : Mass
{
private:
	int size;
	int *buf;
	queue<int> queque;

public:
	Revert();
	~Revert();

	void entered(int); // добавить элемент

	int getFront(); // взять первый элемент

	int getBack(); // взять последний элемент

	void print(); // распечатать

	Revert(int); // инициализация
};

