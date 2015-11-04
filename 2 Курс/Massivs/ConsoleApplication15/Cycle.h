#pragma once
#include "Mass.h"

class Cycle : Mass
{
private:
	int size;
	int *buff;
public:
	Cycle();
	~Cycle();

	Cycle(int); // инициализация 
	void add(int); // вставка
	friend ostream &operator<<(ostream&, const Cycle&); //перегруженный оператор для вывода массива

};

