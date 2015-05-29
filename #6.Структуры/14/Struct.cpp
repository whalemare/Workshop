#include <iostream>
using namespace::std;
#include <string>
#include <Windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Rus");

	struct Datalib{
		string reyc;
		string ddmmyy;
		string name;
		int num;
	};
	const int i=3;
	Datalib *data = new Datalib[i];
	Datalib dataTemp;

	for (int l = 0; l < i; l++) {
		cout << endl << "#" << l+1 << ".";
		cout << "¬ведите номер рейса >> ";
		cin >> data[l].reyc;
		cout << "\n¬ведите дату вылета (дд.мм.гггг) >> ";
		cin >> data[l].ddmmyy;
		cout << "\n¬ведите фамилию пассажира >> ";
		cin >> data[l].name;
		cout << "\n¬ведите номер кассы >> ";
		cin >> data[l].num;
		cout << endl;
	}

	int temp;
	for (int l = 0; l < i-1; l++)
	{
		if (data[l].num>0)
			for (int j = 0; j < i - 1; j++)
			{
				if (data[j + 1].num < data[j].num) // сортируем по возрастанию номера кассы
				{
					dataTemp = data[j + 1];
					data[j + 1] = data[j];
					data[j] = dataTemp;
				}
			}
	}

	cout << endl;
	// выводим структуры (дл¤ удобства просто один нужный нам элемент структуры)
	for (int l = 0; l < i; l++)
		cout << data[l].num << endl;

	system("pause");
	return 0;
}
