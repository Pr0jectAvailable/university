#include <iostream>

using namespace std;
//1. Введены с клавиатуры три числа. Найти сумму тех чисел, которые делятся на 5. Если таких чисел нет, то вывести текст «Error». Использовать только тернарные операторы.
int main() {
	setlocale(LC_ALL, "ru-RU");

	int inp = 0;
	int sum = 0;

	for (int i = 1; i < 4; i++) {
		cout << "\nВведи " << i << " число: ";
		cin >> inp;
		sum = inp % 5 == 0 ? sum + inp : sum;
	}
	if (sum == 0) {
		cout << "\nError";
		return 0;
	}
	cout << "\nСумма " << sum;
	return 0;
}