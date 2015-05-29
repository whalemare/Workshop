#include <iostream>
using namespace::std;
#include <fstream>
#include <string>
#include <Windows.h> // для работы SetConsoleCP, SetConsoleOutputCP

  string line, temp; // переменные для обработки строк
  string text; // для хранения текста из файла
  byte a; // для выбора программы
  int i=2048;
  string *word = new string[i];


void prog1()
{
  string str; // слово
  ifstream ifs;
  ofstream ofs;
  int k=0;
  ifs.open("text2.txt");
  if (ifs)
  {
    cout << "### Текст из файла ###\n\n";
      while (!ifs.eof())
      {
          getline(ifs, word[k]); // считываем строки в переменные
          cout << word[k] << endl; // текст из файла
          k++; // новая строка
      }
  ifs.close(); // закрываем файл
  }
  else
      cout << "ой все!"; // ну если вдруг не открылся


  cout << "\nВведите слово >> "; cin >> str; cout << endl;

  for (int z=0; z<=k; z++) // перебор строк
  {
      if (word[z].find(str)!=-1)
        word[z]="";

       if (word[z]!="")
        cout << word[z] << endl; // выводим список оставшихся строк
  }

  ofs.open("text1_out.txt"); // открываем файл для записи

    for (int z=0; z<=k; z++)
    {
      if (word[z]!="")
        ofs << word[z];
        ofs << endl;
    }
  ofs.close(); // Закрываем файл
}

void prog2()
{
  ifstream ifs; // для чтения
  ofstream ofs; // для записи

  int k=0, z=0, leng=0;

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

ofs.open("text2_out.txt"); // откроем файл для записи
  for (z=0; z<=k; z++) // переберем все слова
  {
    leng = word[z].length();
    leng--;
    for (int i=0; i<leng; i++) // перебираем все буквы
      if (word[z].at(i+1) == word[z].at(i)) // если i и i+1 символы в слове равны, то
      {
//        cout << word[z].at(i+1) << "==" << word[z].at(i) << endl;
        word[z].at(i)=' ';
      }
 //     else
 //       cout << word[z].at(i+1) << "!=" << word[z].at(i) << endl;

    ofs << word[z];  // запись в файл
    ofs << " "; // пробел после каждого слова
  }
ofs.close(); // закроем файл
}

int main()
{
  SetConsoleCP(1251);          // установка кодовой страницы win-cp 1251 в поток ввода
  SetConsoleOutputCP(1251);    // установка кодовой страницы win-cp 1251 в поток вывода
  setlocale(LC_ALL, "Rus");    // Подключение русского языка

  cout << "Выберите программу: " << endl;
  cout << "1. Исключить строки, содержащее заданное слово." << endl;
  cout << "2. Во всех парах одинаковых символов второй символ заменить на пробел.\n\n";

cin >> a;

  switch (a) {
    case '1':
      cout << "Вы выбрали программу 1.\n\n";
      prog1();
      cout << "\nОткройте файл text1_out.txt чтобы увидеть результат";
    break;
    case '2':
      cout << "Вы выбрали программу 2.\n\n";
      prog2();
      cout << "\nОткройте файл text2_out.txt чтобы увидеть результат";
      break;
  }

return 0;
}



