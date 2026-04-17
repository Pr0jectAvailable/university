#include <iostream>
#include <cmath>

using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int inp = 0;

	cout << "Введите количество товаров: ";
	cin >> inp;

	int* prices = new int[inp];
	int* sort = new int[inp];
	for (int i = 0; i < inp; i++) {
		prices[i] = rand() % 100 + 1;
		cout << prices[i] << ", ";
	}
	cout << endl << endl;

	for (int i = 0; i < inp; i++) {
		int min = 999;
		int id = 0;
		for (int b = 0; b < inp; b++) {
			if (min > prices[b]) {
				min = prices[b];
				id = b;
			}
		}
		sort[i] = min;
		prices[id] = 999;
	}

	for (int i = 0; i < inp; i++) {
		cout << sort[i] << ", ";
	}

	cout << endl << endl;

	int sum = 0;
	for (int i = floor(inp / 2); i < inp; i++) {
		sum += sort[i];
	}

	for (int i = 0; i < floor(inp / 2); i += 2) {
		int temp = sort[i];
		sort[i] = sort[inp - i - 1];
		sort[inp - i - 1] = temp;
	}
	
	for (int i = 0; i < inp; i++) {
		cout << sort[i] << ", ";
	}

	cout << endl;

	cout << "Максимальная сумма: " << sum;

	return 0;
}