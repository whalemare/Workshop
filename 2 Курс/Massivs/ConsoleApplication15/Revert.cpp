#include "stdafx.h"
#include "Revert.h"


Revert::Revert()
{
}


Revert::~Revert()
{
}

void Revert::entered(int size)
{
	int number;
	for (int i = 0; i < size; i++)
	{
		cout << "Введите элемент " << i << endl; 
		cin >> number;
		queque.push(number);
	}
}

int Revert::getFront()
{
	return queque.front();
}

int Revert::getBack()
{
	return queque.back();
}

void Revert::print()
{
	int i = 0;
	while (!queque.empty())
	{
		cout << "Номер в очереди " << i << " -> ";
		cout << queque.front();
		cout << endl;
		queque.pop();
		i++;
	}
}


Revert::Revert(int a)
{
	buf = new int[a];
	Revert::size = a;
	size = a;
}
