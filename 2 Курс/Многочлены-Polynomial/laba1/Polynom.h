#pragma once

namespace Program
{

class Polynom
{
private:
	int St;
	int* Kf;
	int degree; // степень многочлена
	int *coefficient = new int[degree + 1]; // массив с коэффициентами многочлена

public:
	Polynom(); // Конструктор

	~Polynom(); // Деструктор

	//Setters
	void setDegree(int degree); // Устанавливает степень многочлена

	void setCoefficient(); // Устанавливает коэффициенты многочлена

	void printPolynom(); // Выводит на экран наш многочлен

	//Getters
	int getDegree(); // Возвращает степень многочлена
};

}