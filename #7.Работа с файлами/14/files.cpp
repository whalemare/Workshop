#include <iostream>
using namespace::std;
#include <fstream>
#include <string>
#include <Windows.h> // для работы SetConsoleCP, SetConsoleOutputCP

// prog1() -> оставить строки заканчивающиеся заданным словом
// prog2()




  string line, temp; // переменные для обработки строк
  string text; // для хранения текста из файла
  byte a; // для выбора программы
  int i=2048;
  string *word = new string[i];
  string *lastWord = new string[i];


void prog1()
{
  string str;
  string strTemp; // для хранения первой буквы
  ifstream ifs;
  ofstream ofs;
  int k=0, n=0;
  ifs.open("text1.txt", ios::in);
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
      cout << "ой все!"; // ну если вдруг файл потерялся

  cout << "\nВведите слово >> "; cin >> str; cout << endl;

  for (int z=0; z<=k; z++)
  {
  		n=word[z].rfind(' '); // номер последнего пробела
  		//cout << n << endl;
  			if (n!=-1) // если пробел был найден
			{
  				lastWord[z]=word[z].substr(n+1); // вырезаем последнее слово каждой строки
  				if (lastWord[z]==str)
  					cout << word[z] << endl;
  			}
  }

  ofs.open("text1_out.txt"); // открываем файл для записи
    for (int z=0; z<=k; z++)
    {
      if (lastWord[z]==str)
        ofs << word[z];
        ofs << endl;
    }
  ofs.close(); // Закрываем файл
}

void prog2()
{
  ifstream ifs; // для чтения
  ofstream ofs; // для записи
  string symb; // cимвол на замену
  int k=0, z=0;

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

  cout << "\nВведите символ на замену >> "; cin >> symb;

ofs.open("text2_out.txt"); // откроем файл для записи
  for (z=0; z<=k; z++) // переберем все слова
  {
    for (int i=0; i<word[z].length(); i++) // перебираем все буквы
    {
    	if (word[z].at(i) >= '0' && word[z].at(i) <= '9') // если цифра
    		word[z].at(i)=symb;
    }
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
  cout << "1. Oставить строки заканчивающиеся заданным словом" << endl;
  cout << "2. Заменить все цифры файла, заданным символом.\n\n";

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



