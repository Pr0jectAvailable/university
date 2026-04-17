#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

#define FILE1 "FILE1.txt"

int main(){
    setlocale(LC_ALL, "rus");

    string input = "";

    cout << "Введите строку символов, состоящую из цифр и слов, разделенных пробелами:" << endl;
    getline(cin, input);

    ofstream f1(FILE1);

    if (f1.fail()) {
        cout << "Ошибка открытичя файла " << FILE1;
        return 1;
    }

    f1 << input;
    cout << "Файл " << FILE1 << " был записан" << endl;
    f1.close();

    ifstream f2(FILE1);

    if (f2.fail()) {
        cout << "Ошибка открытичя файла " << FILE1;
        return 1;
    }

    getline(f2, input);

    input += '\n';

    int c = 0;
    int num[256] = {0};
    for (int i = 0; i < input.length(); i++) {
        if (isdigit(input[i]) && (input[i + 1] == ' ' || input[i + 1] == '\n') && (input[i - 1] == ' ' || input[i - 1] == '\n')) {
            int n = input[i] - '0';
            if (n % 2 != 0) {
                num[c] = n;
                c++;
            }
        }
        
    }

    for (int i = 0; i < c; i++) {
        cout << num[i] << " ";
    }

    return 0;
}
