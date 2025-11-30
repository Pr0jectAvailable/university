#include "interpretation.h"

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    bool cycleState = true;
    int choice;
    while (cycleState) {
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
            cycleState = false;
            break;
        }
        default: {
            cout << "\nВыбирай из предложенных";
            break;
        }
        }
    }
    return 0;
}