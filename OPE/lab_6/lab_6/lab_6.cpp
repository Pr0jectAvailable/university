#include "interpretation.h"

using namespace std;

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
            cout << "\n  [Ошибка] Неверный пункт меню!\n";
            break;
        }
        }
    }

    cout << "\n";
    return 0;
}