#include <locale>
#include <iostream>

using namespace std;

void main() {
	setlocale(LC_ALL, "RU-ru");
	const int maxSize = 30;
	int n, i, kmax = 0, kmin = 0;
	int a[maxSize];
	cout << "Введите размер массива (<30)" << endl;
	cin >> n;
	if (n > 30) {
		return;
	}
	srand((unsigned)time(NULL));
	for (i = 0; i < n; i++) {
		a[i] = rand() % 30;
		cout << a[i] << " ";
	}
	cout << endl;
	for (i = 1; i < n; i++) {
		if (a[i] > a[kmax]) {
			kmax = i;
		}
		else if(a[i] < a[kmin])
		{
			kmin = i;
		}
	}
	cout << "Максимальный элемент " << a[kmax] << endl;
	cout << "Минимальный элемент " << a[kmin] << endl;
}

// Внести изменения с тем, чтобы вычислялся ми-нимальный элемент массива.