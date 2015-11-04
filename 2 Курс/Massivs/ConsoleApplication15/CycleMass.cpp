#include "stdafx.h"
#include "CycleMass.h"


CycleMass::CycleMass()
{
}


CycleMass::~CycleMass()
{
}

CycleMass::CycleMass(int a)
{
	buff = new int[a];
	CycleMass::size = a;
	size = a;
}

void CycleMass::add(int add) // add = кол-во добавляемых элементов
{
	int number;
	for (int i = 0; i < add; i++)
	{
		if (i >= size)
		{
			add = add - size;
			i = 0;
		}
		cout << "Вы вводите элемент под номером " << i;
		cin >> number;
		buff[i] = number;
	}

}
