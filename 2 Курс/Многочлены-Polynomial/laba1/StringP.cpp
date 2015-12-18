#include "StringP.h"
#include <iostream>
#include <sstream>
using namespace::std;



StringP::StringP(Polynom polynom)
{
	for (int i = polynom.getDegree(); i >= 0; i--)
	{
		polyString += to_string(polynom.coefficient[i]);

		polyString += "x^";
		polyString += to_string(i);
		if (i != 0)
			polyString += " + ";
		else
			polyString += " = 0";
	}
}


StringP::~StringP()
{
}

void StringP::show(StringP string)
{
	cout << string.getString();
}

string StringP::getString()
{
	return polyString;
}
