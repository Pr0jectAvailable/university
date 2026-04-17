#include <iostream>

using namespace std;

int main()
{
	int size = 5, ** A;
	int line = 0;

	srand(time(0));
	A = new int* [size];
	for (int i = 0; i < size; i++) {
		A[i] = new int[size];
		for (int j = 0; j < size; j++)
			A[i][j] = 1 + rand() % 10;
	}

	for (int i = 0; i < size; i++) {
		A[1][i] = 0;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (A[i][j] != 0) {
				j = size;
			}
			if (j == size - 1) {
				line = i;
				i = size;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		A[i][line] *= 0.5;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}
