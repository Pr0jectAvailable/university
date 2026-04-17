#include <iostream>

using namespace std;

int main()
{
    int size = 20;
    int values[20];
    int* mas_link = values;
    int* buf = new int[size];
    int average = 0;

    for (int i = 0; i < size; i++) {
        mas_link[i] = 1 + rand() % 100;
        average += mas_link[i];
    }
    average /= size;

    int index_b = 0;
    int index_t = size - 1;
    for (int i = 0; i < size; i++) {
        if (mas_link[i] < average) {
            buf[index_b] = mas_link[i];
            index_b++;
        }
        else {
            buf[index_t] = mas_link[i];
            index_t--;
        }
    }

    for (int i = 0; i < 20; i++) {
        cout << i << ": " << buf[i] << " ";
    }

}

//2. Разделить массив на две части, поместив в первую элементы, меньшие среднего арифметического их сум - мы, а во вторую  большие.