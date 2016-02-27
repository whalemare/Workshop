#pragma once
#include <iostream>
using namespace std;

template <class T>
class templ
{
public:
	templ();
	~templ();

	T massiv[4]; // создаем массив с 4 объектами Т внутри него
	int size=0; // счетчик добавляемых элементов
	void add(T const &item); // метод с ссылкой на переменную типа Т из шаблона
	void show(); // метод для отображения на экране элементов массива

};

template<class T> templ<T>::templ()
{
	size = 0;
}

template<class T> templ<T>::~templ()
{
}

template<class T>
void templ<T>::add(T const &item)
{
	if (size != 5)
	{
		massiv[size] = item;
		size++;
	}
	else
	{
		cerr << "Массив полон";
	}
}

template<class T>
void templ<T>::show()
{
	cout << "показываем\n";
	for (int i = 0; i < size; i++)
		cout << massiv[i] << endl;
}

