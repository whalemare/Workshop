#include <iostream>
using namespace::std;
#include <string>
#include <algorithm>
#include <vector>
#include <Windows.h> // для работы SetConsoleCP, SetConsoleOutputCP
    static int z=0;
    static int *zz = &z;

    bool comp(string a, string b) // Compare для обратной сортировки
    {
        string *aa=&a, *bb=&b;
        if (a>b)
        {
            z++;
            return (true);
        }

    }


int main()
{
SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
setlocale(LC_ALL,"Rus"); // Подключение русского языка
int i, j=0, z;
    cout << "Введите количество строк >> ";
    int COUNT;
    cin >> COUNT;
    string *str2 = new string[COUNT]; // cписок слов
    vector<string> myVector(COUNT);
    for (i=0; i<COUNT; i++) // Введите все COUNT строк -1995993627
    {
        cout << i+1 << ". ";
        cin >> str2[i];
        myVector[i]=str2[i];
    }

    sort(myVector.begin(), myVector.end(), comp); // отсортируем строки через компейр объявленый в начале
    cout << endl << "<< Отсортированные строки >>" << endl << endl;
    for (i=0; i<COUNT; i++)
        cout << myVector[i] << endl;
    cout << endl << "Длина первой строки " << str2[3] << " >> "<< str2[3].size() << endl;
    cout << endl << "Количество перестановок: " << COUNT << endl;
    system("pause");
    return 0;
}
