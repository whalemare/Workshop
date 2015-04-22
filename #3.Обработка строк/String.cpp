#include <iostream>
using namespace::std;
#include <string>;
#include <algorithm>
#include <cctype>
#include <Windows.h> // для работы SetConsoleCP, SetConsoleOutputCP

void replace(string &str)
{
    int z=0;
    for (int i = 0; i < str.size(); ++i)
    {

        if (!isalpha(str[i]) && !ispunct(str[i]))
        {
            str[i] = ' ';
            z++;
                   if (z>=4)
        {
            cout << "Нужно будет выполнить больше 4 итераций";
            break;
        }
        }

    }
}

int main()
{
SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
setlocale(LC_ALL,"Rus"); // Подключение русского языка
	string s1, s2;
	cout << "Введите две строки, в которых должна быть хоть одна цифра" << endl << endl;
	cout << "Первая >> ";
	getline(cin, s1); cout << endl;
	cout << "Вторая >> ";
	getline(cin, s2); cout << endl;
	// Подсчитаем длину строк
	int i = 0;
	int l = s1.size();
	// Посчитаем длинну 1 строки
	while (l != 0)
	{
		l -= 1;
		i++;
	}
	cout << "Длина первой строки " << i << " символов." << endl;
	i = 0;
	l = s2.size();
	// Посчитаем длинну 1 строки
	while (l != 0)
	{
		l -= 1;
		i++;
	}
	cout << "Длина второй строки " << i << " символов." << endl;
	// Удалим пробелы в строках и объеденим их
	string k = s1 + s2;
	cout << "Объединенные строки: " << k << endl;
//заменяем все цифры пробелами
replace(k);
cout << endl << "Обработанная строка >> " << k;
	cin >> i;
	return 0;
}
