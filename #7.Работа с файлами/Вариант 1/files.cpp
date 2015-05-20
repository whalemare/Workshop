#include <iostream>
using namespace::std;
#include <fstream>
#include <string>
#include <Windows.h> // для работы SetConsoleCP, SetConsoleOutputCP

  string line; // переменные для обработки строк
  string text; // для хранения текста из файла
  byte a; // для выбора программы
  int i=2048;
  string *word = new string[i];


void prog1()
{
  int strNum; // длина строки
  string strTemp; // для хранения первой буквы
  ifstream ifs;
  ofstream ofs;
  int k=0;
  ifs.open("text1.txt", ios::in);
  if (ifs)
  {
    cout << "### Текст из файла ###\n\n";
      while (!ifs.eof())
      {
          getline(ifs, word[k]); // считываем строки в переменные
          cout << word[k] << endl; // текст из файла
          k++; // новое слово
      }
  ifs.close(); // закрываем файл
  }
  else
      cout << "ой все!"; // ну если вдруг не открылся

  cout << "\nВведите длинну строки >> "; cin >> strNum;

  for (int z=0; z<=k; z++)
  {
      if (word[z].length()>strNum)
       {
           word[z]=""; // обнуляем ее
       }

       if (word[z]!="")
        cout << word[z] << endl; // выводим список оставшихся строк
  }

  ofs.open("text1_out.txt"); // открываем файл для записи

    for (int z=0; z<=k; z++)
    {
      if (word[z]!="")
        ofs << word[z];
    }
  ofs.close(); // Закрываем файл
}

void prog2()
{
  ifstream ifs; // для чтения
  ofstream ofs; // для записи
  string symb; // cимвол на удаление
  int k=0, z=0, o=0;
  int temp;

  ifs.open("text2.txt");
  if (ifs)
  {
    cout << "### Текст из файла ###\n\n";
      while (!ifs.eof())
      {
          ifs >> word[k]; // считываем слова в переменные
          cout << word[k] << endl; // текст из файла
          k++; // новое слово
      }
  ifs.close(); // закрываем файл
  }
  else
      cout << "ой все!"; // ну если вдруг не открылся

  cout << "Введите символ который нужно удалить >> "; cin >> symb;

ofs.open("text2_out.txt"); // откроем файл для записи
  for (z=0; z<=k; z++) // переберем все слова
  {
    temp = word[z].find(symb);
    if (temp!=string::npos)
        word[z]=word[z].erase(temp);
    ofs << word[z];
    ofs << " ";
  }
ofs.close(); // закроем файл
}

int main()
{
  SetConsoleCP(1251);          // установка кодовой страницы win-cp 1251 в поток ввода
  SetConsoleOutputCP(1251);    // установка кодовой страницы win-cp 1251 в поток вывода
  setlocale(LC_ALL, "Rus");    // Подключение русского языка

  cout << "Выберите программу: " << endl;
  cout << "1. Удалить строки, длинной больше заданной" << endl;
  cout << "2. Удалить из текста заданный символ.\n\n";

cin >> a;

  switch (a) {
    case '1':
      cout << "Вы выбрали программу 1.\n\n";
      prog1();
    break;
    case '2':
      cout << "Вы выбрали программу 2.\n\n";
      prog2();
      break;
  }

return 0;
}



