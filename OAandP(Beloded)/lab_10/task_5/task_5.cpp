#include <iostream>

using namespace std;

int main(){
    srand((unsigned)time(NULL));

    const int max_size = 8;
    const int max_num = 99;
    const int min_num = 0;

    int mas_num[max_size];
    for (int i = 0; i < max_size; i++) {
        mas_num[i] = rand() % (max_num - min_num + 1) + min_num;
    }

    for (int i = 0; i < max_size; i++) {
        cout << mas_num[i] << endl;
    }
    cout << endl;

    for (int i = max_size - 1; i > 0; i--) {
        int sum = 0;
        for (int m = 0; m < i; m++) {
            sum += mas_num[m];
        }
        mas_num[i] = sum;
    }

    for (int i = 0; i < max_size; i++) {
        cout << mas_num[i] << endl;
    }
}

//1. В массиве А каждый элемент, кроме первого, заменить суммой всех предыдущих.
//схема
