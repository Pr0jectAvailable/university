#include <iostream>
#define history_len 256

using namespace std;

int history[history_len];

int main(){
    setlocale(LC_ALL, "rus");

    cout << "Вас приветствует калькулятор. Введите выражение" << endl;
    bool cycle = true;
    static int count = 0;

    while (cycle) {
        char operation;
        float val[2] = { 0,0 };
        int res = 0;

        for (int i = 0; i < 2; ++i) {
            cout << "Введите " << i + 1 << " значение: ";
            while (!(cin >> val[i])) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Не ломай мне прогу. Введите значение: ";
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << endl << "Введите операцию (+ - / * ^) или что то другое для выхода: ";
        cin >> operation;

        switch (operation) {
        case '+':
            res = val[0] + val[1];
            break;
        case '-':
            res = val[0] - val[1];
            break;
        case '/':
            res = val[0] / val[1];
            break;
        case '*':
            res = val[0] * val[1];
            break;
        case '^':
            res = val[0];
            for (int i = 1; i < val[1]; i++) {
                res *= val[0];
            }
            break;
        default:
            cout << endl << "Выход из программы";
            cycle = false;
            return 0;
            break;
        }

        cout << endl << "Результат: " << res <<endl;
        history[count++] = res;

        cout << "История: ";
        for (int i = 0; i < count; i++) {
            cout << history[i] << ", ";
        }
        cout << endl << endl;
    }
    return 0;
}