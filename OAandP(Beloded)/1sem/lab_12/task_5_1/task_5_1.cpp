#include <iostream>

using namespace std;

int main(){
    int size = 20;
    int values[20];
    int* mas_link = values;
    int unique = size;

    for (int i = 0; i < size; i++) {
        mas_link[i] = 1 + rand() % 100;
    }

    for (int i = 0; i < size; i++) {
        for (int b = 0; b < size; b++) {
            if (mas_link[i] == mas_link[b] && b != i) {
                b = size;
                unique--;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        cout << i << ": " << mas_link[i] << " ";
    }

    cout << endl << unique;
}
//1. Дан целочисленный массив Х, содержащий n элементов.Найти количество различных чисел среди элемен - тов этого массива.