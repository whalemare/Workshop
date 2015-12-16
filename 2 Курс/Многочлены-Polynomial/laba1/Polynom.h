#pragma once
#include <fstream>
using namespace::std;
class Polynom
{
private:
	int St;
	int* Kf;


public:
	Polynom *Next; // указатель на следующий элемент

	int degree; // степень многочлена

	float x1, x2; // корни многочлена

	int *coefficient = new int[degree]; // массив с коэффициентами многочлена
	Polynom(); // Конструктор

	~Polynom(); // Деструктор

	Polynom operator++(); // Унарное сложение -> перегрузка оператора
	
	Polynom operator--(); // Унарное вычитание

	Polynom operator+(Polynom); // Бинарное сложение

	Polynom operator-(Polynom); // Бинарное вычитание

	Polynom operator=(Polynom); 


	friend std::ostream &operator << (std::ostream&, Polynom&); // перегрузка оператора вывода
	friend std::istream &operator >> (std::istream&, Polynom&); // перегрузка оператоа ввода
	//friend std::ifstream &operator >> (std::ifstream&, Polynom&); // оператор вывода в файл

	//Setters
	void setDegree(int degree); // Устанавливает степень многочлена

	void setCoefficient(); // Устанавливает коэффициенты многочлена

	void printPolynom(); // Выводит на экран наш многочлен

	//Getters
	int getDegree(); // Возвращает степень многочлена

	float getX1();	// Возвращает 1 корень уравнения 
	float getX2();	// Возвращает 2 корень уравнения 

	void answering(); // Решает уравнение и возвращает его ответ
};