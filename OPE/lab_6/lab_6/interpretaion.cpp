#include "interpretation.h"
#ifdef max
#undef max
#endif

using namespace std;

void asciiMode() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string upper, lower;
    cout << "\nЗаглавная латинская буква(буквы через пробел): ";
    getline(cin, upper);
    cout << "\nСтрочная латинская буква(буквы через пробел): ";
    getline(cin, lower);

    if (size(upper) == size(lower)) {
        for (int i = 0; i < size(upper); i += 2) {
            if (!isupper(upper[i]) || !islower(lower[i]) || upper[i] < 'A' || upper[i] > 'Z' || lower[i] < 'a') {
                cout << "\nВведены не латинские буквы!";
                return;
            }
            cout << "\nКод заглавной: " << (int)upper[i];
            cout << "\nКод строчной: " << (int)lower[i];
            cout << "\nРазница: " << abs(upper[i] - lower[i]) << endl;
        }
    }
    return;
}

void win1251Mode() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string upper, lower;
    cout << "\nЗаглавная латинская буква(буквы через пробел): ";
    getline(cin, upper);
    cout << "\nСтрочная латинская буква(буквы через пробел): ";
    getline(cin, lower);

    if (size(upper) == size(lower)) {
        for (int i = 0; i < size(upper); i += 2) {
            if ((int)(unsigned char)upper[i] < 192 || (int)(unsigned char)upper[i] > 223 || (int)(unsigned char)lower[i] < 224 || (int)(unsigned char)lower[i] > 255) {
                cout << "\nВведены не русские буквы!";
                return;
            }

            cout << "\nКод заглавной: " << (int)(unsigned char)upper[i];
            cout << "\nКод строчной: " << (int)(unsigned char)lower[i];
            cout << "\nРазница: " << abs((int)(unsigned char)upper[i] - (int)(unsigned char)lower[i]) << endl;
        }
    }
    return;
}

void digitMode() {
    char digit;
    cout << "\nВведите цифры: ";
    cin >> digit;

    if (!isdigit(digit)) {
        cout << "\nВведена не цифра!";
        return;
    }

    cout << "\nКод цифры: " << (int)digit;
}