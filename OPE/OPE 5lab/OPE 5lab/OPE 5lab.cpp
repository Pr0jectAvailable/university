
#include <iostream>
#include <locale>
#include <iomanip>
#include <windows.h>
#include <cctype>

using namespace std;

void asciiMode() {
    char upper, lower;
    cout << "\nЗаглавная латинская буква: ";
    cin >> upper;
    cout << "\nСтрочная латинская буква: ";
    cin >> lower;

    if (!isupper(upper) || !islower(lower) || upper < 'A' || upper > 'Z' || lower < 'a') {
        cout << "\nВведены не латинские буквы!";
        return;
    }

    cout << "\nКод заглавной: " << (int)upper;
    cout << "\nКод строчной: " << (int)lower;
    cout << "\nРазница: " << abs(upper - lower);
}

void win1251Mode() {

    char upper, lower;
    cout << "\nЗаглавная русская буква: ";
    cin >> upper;
    cout << "\nСтрочная русская буква: ";
    cin >> lower;

    if ((int)(unsigned char)upper < 192 || (int)(unsigned char)upper > 223 || (int)(unsigned char)lower < 224 || (int)(unsigned char)lower > 255) {
        cout << "\nВведены не русские буквы!";
        return;
    }

    cout << "\nКод заглавной: " << (int)(unsigned char)upper;
    cout << "\nКод строчной: " << (int)(unsigned char)lower;
    cout << "\nРазница: " << abs((int)(unsigned char)upper - (int)(unsigned char)lower);
    
}

void digitMode() {
    char digit;
    cout << "\nВведите цифру: ";
    cin >> digit;

    if (!isdigit(digit)) {
        cout << "\nВведена не цифра!";
        return;
    }

    cout << "\nКод цифры: " << (int)digit;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    bool cycle = true;
    int choice;
    while (cycle) {
        cout << "\n\nВыберите вариант:\n";
        cout << "ASCII - 1\n";
        cout << "Windows-1251 - 2\n";
        cout << "Цифра - 3\n";
        cout << "Выход - 4\n";
        cout << "Ввод: ";
        cin >> choice;

        switch (choice) {
        case(1): {
            asciiMode();
            break;
        }
        case(2): {
            win1251Mode();
            break;
        }
        case(3): {
            digitMode();
            break;
        }
        case(4): {
            cout << "\nBye bye";
            cycle = false;
            break;
        }
        default:{
            cout << "\nВыбирай из предложенных";
            break;
        }
        }
    }
    return 0;
}