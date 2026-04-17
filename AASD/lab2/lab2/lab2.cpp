#include <iostream>
#include <math.h>

#define size 100

using namespace std;

int main(){
    setlocale(LC_ALL, "rus");

    int start = 0;
    int inp = 0;
    cout << "Введите диапазон: ";
    cin >> inp;
    start = inp;

    int attemps = ceil(log2(inp));
    int temp = 0;
    bool state = true;
    char comparison;
    temp = inp;
    while (state) {
        cout << inp << " число. Ваше больше, меньше или совпадает (>, <, =): ";
        cin >> comparison;
        
        switch (comparison) {
        case '>':
            inp += ceil(temp / 2.0);
            break;
        case '<':
            inp -= ceil(temp / 2.0);
            break;
        case '=': {
            cout << "Максимально колличество шагов для диапазона: " << attemps << endl;
            int t = start;
            int c = start;
            for (int i = 0; i < attemps; i++) {
                cout << t << endl;
                t /= 2;
            }

            state = false;
            break;
        }
        default:
            cout << "Нельзя так делать";
            return 1;
            break;
        }
        temp = temp / 2.0;
    }
    return 0;
}