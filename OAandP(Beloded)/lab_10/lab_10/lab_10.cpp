#include <iostream>
#include <ctime>

void main() {
	setlocale(LC_ALL, "Russian");
	using namespace std;
	const int N = 100;
	int i, sz, A[N], rmn = 0, rmx = 99, sum = 0;
	cout << "Введите размер массива: ";
	cin >> sz;
	cout << "Массив A:" << endl;
	srand((unsigned)time(NULL));
	for (i = 0; i < sz; i++) {
		int rand_num = (int)(((double)rand() / (double)RAND_MAX) * (rmx - rmn) + rmn);
		A[i] = rand_num;
		sum += rand_num;
		cout << A[i] << endl;
	}
	cout << endl << "Сумма элементов массива: " << sum; 
}
// Добавить в программу операторы вычисления сум-мы элементов массива А