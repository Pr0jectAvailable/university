#include <iostream>
#include "./Lab5.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int temp = 0;
	cout << "Введите размер 1 матрицы: ";
	cin >> temp;
	cout << endl << endl;

	int** mat1 = newMatrix(temp);
	matPrint(mat1, temp);

	int temp2 = 0;
	cout << "Введите размер 2 матрицы: ";
	cin >> temp2;
	cout << endl << endl;

	int** mat2 = newMatrix(temp2);
	matPrint(mat2, temp2);

	int** t = mutMatrix0(mat1, temp, mat2, temp2);
	if (t == NULL) {
		return 1;
	}
	cout << endl << endl;
	cout << "Произведение 1 матрицы на 2:" << endl;
	matPrint(t, temp);

	cout << endl << endl;
	cout << "Детерминанд 1 матрицы: " << determinant(mat1, temp) << endl;

	cout << endl << endl;
	cout << "Детерминанд 2 матрицы:" << determinant(mat2, temp2) << endl;

	return 0;
}