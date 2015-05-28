#include <iostream>
using namespace::std;
#include <string>
#include <Windows.h> // ��� ������ SetConsoleCP, SetConsoleOutputCP

/*
1. �������� ���������, ���������� � ����� ������
� ���� ������� �������� � ����������� ����������������
���� ������ � ������ � ����������� ���������� ��� �����������.

1.1 ���� ������ ������� ��������������.

2. ���������� ��������� �.4.1, ��������� ������ ���������� �� ���������
� ������������ ��������� ������. ��������� ���������� �������.

�������
���� ��������
�������
����� �����

��� ������ � ������ �����, �� ������ 0, ���������� � ������ �������

*/
int main()
{
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
	setlocale(LC_ALL, "Rus"); // ����������� �������� �����

	struct Datalib{ // ��������� ���������
		string lastName;	// �������
		string ddmmyy;		// ��� ��������
		string phone;		// ��������
		int money;			// ����� �����
	};
	const int i=3;
	Datalib *data = new Datalib[i]; // ����� ��������� ����� �������. (������ �������� ����� ������������ ��������� ������)
	Datalib dataTemp; // ��� ��������������� ��������� ��� ����������

	for (int l = 0; l < i; l++) {	// ��������� ����� >> data[l]
		cout << endl << "#" << l+1 << ".";
		cout << "������� ������� >> ";
		cin >> data[l].lastName;
		cout << "\n������� ���� �������� (��.��.����) >> ";
		cin >> data[l].ddmmyy;
		cout << "\n������� ����� �������� >> ";
		cin >> data[l].phone;
		cout << "\n������� ����� ����� >> ";
		cin >> data[l].money;
		cout << endl;
	}

	int temp; // ���������� ��� �������� �������� ���������
	for (int l = 0; l < i-1; l++) // ��������� ����������� "���������" ����� ������� ���� ��������� �� ���������
	{
		if (data[l].money>0)
			for (int j = 0; j < i - 1; j++)
			{
				if (data[j + 1].money > data[j].money) // ��������� �� �������� ����� �����
				{
					dataTemp = data[j + 1];
					data[j + 1] = data[j];
					data[j] = dataTemp;
				}
			}
	}

	cout << endl;
	// ������� ��������� (��� �������� ������ ���� ������ ��� ������� ���������)
	for (int l = 0; l < i; l++)
		cout << data[l].money << endl;

	system("pause");
	return 0;
}
