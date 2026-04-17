#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "RU-ru");
    srand(time(NULL));

    int max = 0;
    int values[20];

    for (int i = 0; i < 20; i++) {
        values[i] = 1 + rand() % 100;
    }

    for (int i = 0; i < 20; i++) {
        if (max < values[i]) {
            max = values[i];
        }
    }

    for (int i = 0; i < 20; i++) {
        cout << i << ": " << values[i] << " ";
    }

    cout << endl << "Максимальное значение " << max << endl << endl;

    int* max_link = values;
    int size = 20;
    int* mas = values;

    for (int i = 0; i < 20; i++) {
        mas[i] = 1 + rand() % 100;
    }

    for (int i = 0; i < 20; i++) {
        if (*max_link < mas[i]) {
            max_link = &mas[i];
        }
    }

    for (int i = 0; i < 20; i++) {
        cout << i << ": " << mas[i] << " ";
    }

    cout << endl << "Максимальное значение " << *max_link;
}
//Написать программу генерации элементов массива А из случайных чисел,
//их вывода и определения максимального элемента масси - 
//ва двумя способами(с указателями и без них).