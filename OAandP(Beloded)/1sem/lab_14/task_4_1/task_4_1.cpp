#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "ru-RU");
    int const n = 3;
    int mas[3][3] = { {4,2,3},{4,5,6},{7,8,9} };
    int element = mas[0][0];
    int element_pos = 0;

    for (int i = 0; i < n; i++) {
        if (element > mas[i][i]) {
            element = mas[i][i];
            element_pos = i + 1;
        }
    }
    
    cout << "Наименьший эллемент на диагонали массива: " << element << " в " << element_pos << " столбце";

    return 0;
}

//1. Найти наименьший элемент главной диагонали матрицы С(n, n) и вывести на печать столбец, в кото - ром он находится.