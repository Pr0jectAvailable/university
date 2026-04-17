#include <iostream>

int main(){
    setlocale(LC_ALL, "ru-RU");

    const int m = 5;
    const int n = 6;
    int (*mas)[n] = new int[m][n];
    int count = 0;

    int values[5][6] = {
    { 200, 25,  8, 14, 33, 19 },
    { 42,  7, 51,  3, 28, 16 },
    {  5, 39, 400, 47, 12, 31 },
    { 18,  2, 44,  9, 37, 24 },
    { 29, 13,  6, 41, 20, 35 }
    };

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mas[i][j] = values[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int sum = 0;
        int max_el = mas[i][0];
        for (int b = 0; b < n; b++){
            if (max_el < mas[i][b]) {
                max_el = mas[i][b];
            }
            sum += mas[i][b];
        }
        sum -= max_el;
        if (sum < max_el) {
            count++;
        }
    }

    std::cout << "Колличество эллементов, которые больше, чем сумма остальных эллементов в столбце: " << count;

    return 0;
}

//Задана числовая матрица размером nxm.Определить количество таких элементов матрицы,
//значение каж - дого из которых больше суммы остальных элементов своего столбца.