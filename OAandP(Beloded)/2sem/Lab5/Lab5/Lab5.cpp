#include "pch.h"
#include "framework.h"
#include "Lab5.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int** newMatrix(int size){
	int** mat = new int*[size];
	for (int i = 0; i < size; i++) {
		mat[i] = new int[size];
		for (int b = 0; b < size; b++) {
			mat[i][b] = std::rand() % (100 - 1);
		}
	}
	return mat;
}

void matPrint(int** mat, int size) {
	for (int i = 0; i < size; i++) {
		for (int b = 0; b < size; b++) {
			std::cout << mat[i][b] << " ";
		}
		std::cout << std::endl;
	}

	return;
}

int** mutMatrix0(int** mat1, int size1, int** mat2, int size2) {
    if (size1 != size2) {
        std::cerr << "Ошибка размеров при умножении\n";
        return NULL;
    }

    int n = size1;
    int** mut_mat = new int* [n];

    for (int i = 0; i < n; ++i) {
        mut_mat[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            mut_mat[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                mut_mat[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return mut_mat;
}

double determinant(int** matrix, int n) {
    int** a = new int* [n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            a[i][j] = matrix[i][j];
        }
    }

    double det = 1.0;
    int sign = 1;

    for (int i = 0; i < n; ++i) {
        int pivot = i;
        for (int j = i + 1; j < n; ++j) {
            if (std::fabs(a[j][i]) > std::fabs(a[pivot][i])) {
                pivot = j;
            }
        }

        if (std::fabs(a[pivot][i]) < 0.001) {
            det = 0.0;
            break;
        }

        if (pivot != i) {
            int* temp = a[i];
            a[i] = a[pivot];
            a[pivot] = temp;
            sign = -sign;
        }

        det *= a[i][i];

        for (int j = i + 1; j < n; ++j) {
            double factor = a[j][i] / a[i][i];
            for (int k = i; k < n; ++k) {
                a[j][k] -= factor * a[i][k];
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;

    return det * sign;
}