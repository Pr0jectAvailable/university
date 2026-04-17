#include <iostream>
#include <fstream>
#include <string>

#define FILE1 "FILE1.txt"
#define FILE2 "FILE2.txt"

using namespace std;

int main(){
    setlocale(LC_ALL, "rus");

    ifstream f1(FILE1);
    string out = "";
    string buf = "";

    if (f1.fail()) {
        cout << "Ошибка открытия файла " << FILE1;
        return 1;
    }

    int count = 0;
    while (getline(f1, buf)) {
        count++;
        if (count % 2 == 0) {
            out += buf;
            out += "\n";
        }
    }


    f1.clear();
    f1.seekg(0, ios::end);
    streamsize size = f1.tellg();
    cout << "размер файла " << size << " байт" << endl;

    ofstream f2(FILE2);
    if (f2.fail()) {
        cout << "Ошибка открытия файла " << FILE2;
        return 1;
    }

    f2 << out;
    cout << "Файл " << FILE2 << " был записан" << endl;

    f2.close();

    ifstream f3(FILE2);

    f3.clear();
    f3.seekg(0, ios::end);
    size = f3.tellg();
    cout << "размер файла " << size << " байт" << endl;

    return 0;
}

//1. Скопировать в файл FILE2 только четные строки из FILE1.Подсчитать размер файлов FILE1 и FILE2(в байтах).
//2. Ввести с клавиатуры строку символов, состоящую из цифр и слов, разделенных пробелами, и записать ее в файл.Прочитать из файла данные и вывести нечетные числа строки
