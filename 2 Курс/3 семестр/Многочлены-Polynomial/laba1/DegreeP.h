#pragma once
#include "Polynom.h"
class DegreeP : public Polynom
{
private:
	static const int n = 5; // размер массива
	int *massivOfDegree = new int[n]; // массив степеней

public:
	DegreeP();
	~DegreeP();
};

