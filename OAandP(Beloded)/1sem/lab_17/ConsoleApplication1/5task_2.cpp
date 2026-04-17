#include <iostream>
#include <limits>

void processMatrix(int** matrix, int n, bool& foundOnDiagonal, int& minValue, int& rowIndex, int& colIndex) {
    minValue = std::numeric_limits<int>::max();
    rowIndex = -1;
    colIndex = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] < minValue) {
                minValue = matrix[i][j];
                rowIndex = i;
                colIndex = j;
            }
        }
    }

    foundOnDiagonal = (rowIndex == colIndex);
}

int main() {
    int n;

    std::cout << "Введите размер квадратной матрицы (n): ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Размер матрицы должен быть положительным числом!" << std::endl;
        return 1;
    }

    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    std::cout << "\nВведите элементы матрицы " << n << "x" << n << ":" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "matrix[" << i << "][" << j << "] = ";
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "\nИсходная матрица:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    bool foundOnDiagonal;
    int minValue, rowIndex, colIndex;

    processMatrix(matrix, n, foundOnDiagonal, minValue, rowIndex, colIndex);

    if (foundOnDiagonal) {
        std::cout << "\nМинимальное значение находится на главной диагонали:" << std::endl;
        std::cout << "Значение: " << minValue << std::endl;
        std::cout << "Индексы: [" << rowIndex << "][" << colIndex << "]" << std::endl;
    }
    else {
        std::cout << "\nМинимальное значение НЕ находится на главной диагонали." << std::endl;
        std::cout << "Минимальное значение: " << minValue << std::endl;
        std::cout << "Его индексы: [" << rowIndex << "][" << colIndex << "]" << std::endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}