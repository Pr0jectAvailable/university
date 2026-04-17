#include <iostream>

using namespace std;

int min(int* arr, int size);
int sigma(int* arr, int min_n);

int main(){
	setlocale(LC_ALL, "RU-ru");

	bool inp_state = true;
	int mas[10];
	int cou = 0;

	do
	{
		int inp = 0;
		cout << "\nВведите число: ";
		cin >> mas[cou];
		cout << "\nПродолжить ввод (1-да,2-нет): ";
		cin >> inp;

		if (inp != 1 || cou >= 9) {
			if(cou < 3){
				cout << "\nминимум 4 значения\n";
				inp = 1;
				cou++;
			}
			else {
				inp_state = false;
			}
		}
		else {
			/*system("cls");*/
			cou++;
		}
		
	} while (inp_state);

	int min_n = min(mas, cou);
	int sigma_sum = sigma(mas, min_n);

	cout << "\nМинимальное значение: " << min_n;
	cout << "\nСумма: " << sigma_sum;
	
}

int min(int* arr, int size) {
	int min = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	return min;
}

int sigma(int* arr, int min_n) {
	int sum = 0;

	for (int i = 0; i < 4; i++) {
		sum += 4 * arr[i] + min_n;

	}

	return sum;
}