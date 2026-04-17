#include <iostream>
#include <locale>
#include <iomanip>
#include <windows.h>
#include <cctype>

using namespace std;

void a_procedure() {
    char symbol_A, symbol_B;
    cout << "\n| Введите ЗАГЛАВНЫЙ символ (латиница): ";
    cin >> symbol_A;
    cout << "| Введите строчный символ (латиница):  ";
    cin >> symbol_B;

    if (!isupper(symbol_A) || !islower(symbol_B) || symbol_A < 'A' ||
        symbol_A > 'Z' || symbol_B < 'a') {
        cout << "|\n| [Ошибка] Некорректные символы\n";
        return;
    }

    cout << "|\n| Код заглавного:  " << (int)symbol_A;
    cout << "\n| Код строчного:    " << (int)symbol_B;
    cout << "\n| Разница кодов:    " << abs(symbol_A - symbol_B);
}

void cyr_procedure() {
    unsigned char char_upper, char_lower;
    cout << "\n| Введите ЗАГЛАВНУЮ букву (кириллица): ";
    cin >> char_upper;
    cout << "| Введите строчную букву (кириллица):  ";
    cin >> char_lower;

    int code_U = (int)char_upper;
    int code_L = (int)char_lower;

    if (code_U < 192 || code_U > 223 || code_L < 224 || code_L > 255) {
        cout << "|\n| [Ошибка] Некорректные символы\n";
        return;
    }

    cout << "|\n| Код заглавной:  " << code_U;
    cout << "\n| Код строчной:    " << code_L;
    cout << "\n| Разница кодов:   " << abs(code_U - code_L);
}

void num_procedure() {
    char digit_char;
    cout << "\n| Введите цифровой символ (0-9): ";
    cin >> digit_char;

    if (!isdigit(digit_char)) {
        cout << "|\n| [Ошибка] Это не цифра\n";
        return;
    }

    cout << "|\n| Код цифры: " << (int)digit_char;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    bool flag = true;
    int user_sel;

    while (flag) {
        cout << "\n\n" << "-----------------------------------------------";
        cout << "\n  М Е Н Ю   В Ы Б О Р А:\n";
        cout << "-----------------------------------------------";
        cout << "\n  1. Латинские символы (ASCII)";
        cout << "\n  2. Кириллические символы (Win-1251)";
        cout << "\n  3. Цифровые символы";
        cout << "\n  4. Завершение работы";
        cout << "\n" << "-----------------------------------------------";
        cout << "\n  Ваш выбор [1-4]: ";
        cin >> user_sel;
        cout << "-----------------------------------------------" << "\n";

        switch (user_sel) {
        case 1: {
            a_procedure();
            break;
        }
        case 2: {
            cyr_procedure();
            break;
        }
        case 3: {
            num_procedure();
            break;
        }
        case 4: {
            cout << "\n  [Завершение работы]\n";
            flag = false;
            break;
        }
        default: {
            cout << "\n  [Ошибка] Неверный пункт меню\n";
            break;
        }
        }
    }

    cout << "\n";
    return 0;
}