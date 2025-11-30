#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_CTYPE, "Russian");
	int i, k, size = 4;
	double average = 0;
	float massivA[] = { 5, -4, 17.1, 9, 1 };
	cout << "Введите номер элемента (от 0 до 4)";
	cin >> k;
	for (int i = 0; i < size; i++) {
		average += massivA[i];
	}
	average /= size;
	for (i = k; i <= size; i++)
		massivA[i] = massivA[i + 1];
	size--;
	for (i = 0; i <= size; i++)
		cout << massivA[i] << endl;

	cout << endl << "Среднее значение элементов изначального массива: " << average;
}
// Добавить в программу операторы вычисления сред-него значения элементов ис-ходного массива.
// Условие