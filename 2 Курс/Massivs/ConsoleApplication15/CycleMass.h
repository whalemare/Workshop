#pragma once
#include "Mass.h"
class CycleMass : public Mass
{
private:
	int size;
	int *buff;
public:
	CycleMass();
	~CycleMass();

	CycleMass(int); // конструктор с параметром

	void add(int); // вставка
};

