#pragma once
#include "Polynom.h"
#include <string>
class StringP : public Polynom
{
private:
	string polyString; // здесь будет храниться полином
public:
	StringP(Polynom);
	~StringP();

	void show(StringP string);

	string getString();
};

