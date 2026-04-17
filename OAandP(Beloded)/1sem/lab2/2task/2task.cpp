#include <iostream>
#include <fstream>
#include <string>

#define FILE1 "./FILE1.txt"

using namespace std;

int main(){
    setlocale(LC_ALL, "rus");
    ofstream f1(FILE1);
    string temp = "";
    int bracket[6] = { 0,0,0,0,0,0 };

    if (f1.fail()) {
        cout << "Ошибка открытия файла " << FILE1;
        return 1;
    }

    cout << "Введите строку состоящую из цифр и скобок: ";
    cin >> temp;

    f1 << temp;
    cout << endl << "Файл " << FILE1 << " был записан" << endl;
    f1.close();

    ifstream f2(FILE1);
    if (f2.fail()) {
        cout << "Ошибка открытия файла " << FILE1;
        return 1;
    }

    getline(f2, temp);

    for (int i = 0; i < temp.length(); i++) {
        switch (temp[i]) {
        case '(':
            bracket[0]++;
            break;
        case ')':
            bracket[1]++;
            break;
        case '{':
            bracket[2]++;
            break;
        case '}':
            bracket[3]++;
            break;
        case '[':
            bracket[4]++;
            break;
        case ']':
            bracket[5]++;
            break;
        }
    }

    cout << "В файле: " << bracket[0]++ << " (," << bracket[1]++ << " )," << bracket[2]++ << " {," << bracket[3]++ << " }," << bracket[4]++ << " [," << bracket[5]++ << " ]";

    return 0;
}