#include <iostream>
#include <cmath>

void processArray(double* A, int sizeA, double*& B, int& sizeB, double& sumSquares) {
    sizeB = 0;
    for (int i = 0; i < sizeA; i += 2) {
        if (A[i] > 0) {
            sizeB++;
        }
    }

    if (sizeB > 0) {
        B = new double[sizeB];

        int indexB = 0;
        sumSquares = 0.0;

        for (int i = 0; i < sizeA; i += 2) {
            if (A[i] > 0) {
                B[indexB] = A[i];
                sumSquares += B[indexB] * B[indexB];
                indexB++;
            }
        }
    }
    else {
        B = nullptr;
        sumSquares = 0.0;
    }
}

int main() {
    setlocale(LC_ALL, "RU-ru");
    const int SIZE_A = 20;
    double* A = new double[SIZE_A];

    std::cout << "Введите 20 элементов массива A (положительные и отрицательные):" << std::endl;
    for (int i = 0; i < SIZE_A; i++) {
        std::cout << "A[" << i << "] = ";
        std::cin >> A[i];
    }

    double* B = nullptr; 
    int sizeB = 0; 
    double sumSquares = 0.0; 

    processArray(A, SIZE_A, B, sizeB, sumSquares);

    if (sizeB > 0 && B != nullptr) {
        std::cout << "\nМассив B из положительных элементов массива A с четными индексами:" << std::endl;
        for (int i = 0; i < sizeB; i++) {
            std::cout << "B " << i << " = " << B[i] << std::endl;
        }
        std::cout << "\nСумма квадратов элементов массива B: " << sumSquares << std::endl;
    }
    else {
        std::cout << "\nВ массиве A нет положительных элементов с четными индексами." << std::endl;
        std::cout << "Сумма квадратов элементов массива B: " << sumSquares << std::endl;
    }

    delete[] A;
    if (B != nullptr) {
        delete[] B;
    }

    return 0;
}