#include <iostream>

#define PER_SQUARE(x) ( ((int)sqrt(x) * (int)sqrt(x)) == (x) )
#define MAS(type,size) new type[size]

using namespace std;

int main(){
	setlocale(LC_ALL, "rus");

	int* mas = MAS(int, 10);
	cout << "Введите 10 чисел" << endl;
	for (int i = 0; i < 10; i++) {
		cin >> mas[i];
		if (cin.fail() || mas[i] < 0) {
			cout << "Неверный ввод";
			return 1;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (PER_SQUARE(mas[i])) {
			cout << "Число в корне целое: " << mas[i]<< endl;
		}
	}
	return 0;
}

//Напишите программу, где пользователь вводит n целых положительных чисел в динамический массив A.
//Из массива A найдите те числа, которые в корне дают целое число.
//При решении использовать макроопределения и дополнительные операции препроцессора.