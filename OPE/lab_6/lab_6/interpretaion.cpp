#include "interpretation.h"
#ifdef max
#undef max
#endif

using namespace std;

void a_procedure() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string symbol_A, symbol_B;
    cout << "\nЗаглавная латинская буква(через пробел): ";
    getline(cin, symbol_A);
    cout << "\nСтрочная латинская буква(через пробел): ";
    getline(cin, symbol_B);

    if (size(symbol_A) == size(symbol_B)) {
        for (int i = 0; i < size(symbol_A); i += 2) {
            if (!isupper(symbol_A[i]) || !islower(symbol_B[i]) || symbol_A[i] < 'A' || symbol_A[i] > 'Z' || symbol_B[i] < 'a') {
                cout << "\nВведены не латинские буквы";
                return;
            }
            cout << "\nКод заглавной: " << (int)symbol_A[i];
            cout << "\nКод строчной: " << (int)symbol_B[i];
            cout << "\nРазница: " << abs(symbol_A[i] - symbol_B[i]) << endl;
        }
    }
    return;
}

void cyr_procedure() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string char_upper, char_lower;
    cout << "\nЗаглавная латинская буква(через пробел): ";
    getline(cin, char_upper);
    cout << "\nСтрочная латинская буква(через пробел): ";
    getline(cin, char_lower);

    if (size(char_upper) == size(char_lower)) {
        for (int i = 0; i < size(char_upper); i += 2) {
            int code_U = (int)(unsigned char)char_upper[i];
            int code_L = (int)(unsigned char)char_lower[i];

            if (code_U < 192 || code_U > 223 || code_L < 224 || code_L > 255) {
                cout << "\nВведены не русские буквы";
                return;
            }

            cout << "\nКод заглавной: " << code_U;
            cout << "\nКод строчной: " << code_L;
            cout << "\nРазница: " << abs(code_U - code_L) << endl;
        }
    }
    return;
}

void num_procedure() {
    char digit_char;
    cout << "\nВведите цифры: ";
    cin >> digit_char;

    if (!isdigit(digit_char)) {
        cout << "\nВведена не цифра";
        return;
    }

    cout << "\nКод цифры: " << (int)digit_char;
}