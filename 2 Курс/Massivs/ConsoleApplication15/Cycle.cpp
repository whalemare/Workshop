#include "stdafx.h"
#include "Cycle.h"


Cycle::Cycle()
{
}


Cycle::~Cycle()
{
}

Cycle::Cycle(int a)
{
	buff = new int[a];
	Cycle::size = a;
	size = a;
}

void Cycle::add(int add) // add = кол-во добавляемых элементов
{
	int number;
	for (int i = 0; i < add; i++)
	{
		if (i >= size)
		{
			add = add - size;
			i = 0;
		}
		cout << "Вы вводите элемент под номером " << i << endl;
		cin >> number;
		buff[i] = number;
	}

}

ostream& operator<<(ostream &out, const Cycle &a) {
	if (a.size <= 0) // если массив пуст
		out << "Массив пуст";
	else
		for (int i = 0; i < a.size; ++i)
			out << a.buff[i]; // выводим элементы массива
	return out;
}
