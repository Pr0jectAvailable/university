#include <iostream>
using namespace std;

const int MAX_SIZE = 10;
const int MAX_MATRICES = 10;

int sum_below(int matrix[MAX_SIZE][MAX_SIZE], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j) { 
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

int find_max_sum(int count, ...) {
    int matrices[MAX_MATRICES][MAX_SIZE][MAX_SIZE];
    int sizes[MAX_MATRICES];

    int matrix1[][MAX_SIZE] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int matrix2[][MAX_SIZE] = { {10, 20}, {30, 40} };
    int matrix3[][MAX_SIZE] = { {1, 2, 3, 4}, {5, 6, 7, 8},
                               {9, 10, 11, 12}, {13, 14, 15, 16} };

    int n1 = 3, n2 = 2, n3 = 4;

    sizes[0] = n1;
    sizes[1] = n2;
    sizes[2] = n3;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n1; j++) {
            matrices[0][i][j] = matrix1[i][j];
        }
    }

    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n2; j++) {
            matrices[1][i][j] = matrix2[i][j];
        }
    }

    for (int i = 0; i < n3; i++) {
        for (int j = 0; j < n3; j++) {
            matrices[2][i][j] = matrix3[i][j];
        }
    }

    int max_sum = -2147483647;
    for (int k = 0; k < count; k++) {
        int current_sum = sum_below(matrices[k], sizes[k]);
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    return max_sum;
}

int main() {
    setlocale(LC_ALL, "RU-ru");

    cout << "Максимальная сумма (2 матрицы): " << find_max_sum(2) << endl;
    cout << "Максимальная сумма (3 матрицы): " << find_max_sum(3) << endl;
    cout << "Максимальная сумма (1 матрица): " << find_max_sum(1) << endl;

    return 0;
}

//Написать функцию для вычисления суммы элементов квадратной матрицы,
//которые расположены ниже главной диагонали.
//С ее помощью найти максимальное значение такой суммы в n матрицах.