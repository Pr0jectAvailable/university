#include <iostream>
#include <cmath>

using namespace std;

void for_f() {
    int a = 8;
    int m = 6;
    int b = 5 * pow(10, 3);

    float mas_k[3] = { 1.6, 9.1, 8 };

    for (int i = 0; i < 3; i++) {
        float d = sin(mas_k[i] / a) / cos(m * b);
        float c = d / (pow(d, 2) + 1) / (1 - exp(mas_k[i]));

        cout << "k = " << mas_k[i] << " | ";
        cout << "d = " << d << " | ";
        cout << "c = " << c << " |\n\n";
    }
}

void while_f() {
    int a = 8;
    int m = 6;
    int b = 5 * pow(10, 3);
    float count_var = a; 

    while (count_var > 2.9) {
        float d = sin(count_var / a) / cos(m * b);
        float c = d / (pow(d, 2) + 1) / (1 - exp(count_var));

        cout << "k = " << count_var << " | ";
        cout << "d = " << d << " | ";
        cout << "c = " << c << " |\n\n";

        count_var -= 0.5;
    }
}

void while_for_f() {
    float a = 2.0;
    int m = 6;
    int b = 5 * pow(10, 3);
    float mas_k[3] = { 1.7, 5, -2 };

    while (a < 2.9) {
        for (int i = 0; i < 3; i++) {
            float d = sin(mas_k[i] / a) / cos(m * b);
            float c = d / (pow(d, 2) + 1) / (1 - exp(mas_k[i]));

            cout << "a = " << a << " | ";
            cout << "k = " << mas_k[i] << " | ";
            cout << "d = " << d << " | ";
            cout << "c = " << c << " |\n\n";
        }
        a += 0.2;
    }
}

int main() {
    setlocale(LC_CTYPE, "Russian");

    int input = 0;
    cout << "Выбери вариант решения (1-for,2-while,3-двойной цикл): ";
    cin >> input;
    cout << endl;

    switch (input) {
    case 1: for_f(); break;
    case 2: while_f(); break;
    case 3: while_for_f(); break;
    default: cout << "Ну, начинай с начала";
    }
}