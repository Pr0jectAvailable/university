#include <iostream>

using namespace std;

int main()
{
    const int size = 5;
    int mas[size][size];

    for (int i = 0; i < size; i++) {
        for (int b = 1 + i; b < size + i + 1; b++) {
            if (b > size) {
                mas[b - 1 - i][i] = b - size;
            }
            else{
                mas[b - 1 - i][i] = b;
            }
        }
    }

    for (int i = 0; i < size; i++){
        for (int b = 0; b < size; b++) {
            cout << mas[i][b] << " ";
        }
        cout << endl;
    }
}

//Латинским квадратом порядка n называется квадратная таблица размером nхn, каждая строка и каждый столбец которой со - держат все числа от 1 до n.
//Для заданного n в матрице L(n, n) построить латинский квадрат порядка n.