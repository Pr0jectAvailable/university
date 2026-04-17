#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cctype>
#include <iomanip>

#define F1n "F1.txt"
#define F2n "F2.txt"

#define sizem 1024

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU-ru");
    FILE* f1;
    FILE* f2;

    f1 = fopen(F1n, "rb");
    f2 = fopen(F2n, "w");

    if (!f1 || !f2) {
        perror("fopen failed");
        cout << "Error opening file" << endl;
        fclose(f1);
        fclose(f2);
        system("pause");
        return 1;
    }

    char temp[sizem];
    fseek(f1, 0, SEEK_END);
    long fileSize = ftell(f1);
    rewind(f1);

    auto bytesRead = fread(temp, 1, fileSize, f1);
    if (bytesRead != fileSize) {
        cout << "fread failed" << endl;
        fclose(f1);
        fclose(f2);
        return 1;
    }
    temp[fileSize] = '\0';

    char words[sizem] = {0};
    bool state = false;
    bool after_s = true;

    for (int i = 0; i < strlen(temp); i++) {
        if (isdigit(temp[i]) && !state && after_s) {
            state = true;
            char single_char[2] = { temp[i], '\0' };
            strcat(words, single_char);
        }
        else if (temp[i] == '\n' && state) {
            state = false;
            /*strcat(words, " ");*/
        }
        else if(state){
            char single_char[2] = { temp[i], '\0' };
            strcat(words, single_char);
        }
        else {
            after_s = false;
        }
        if (temp[i] == '\n') {
            after_s = true;
        }
    }

    fputs(words, f2);

    cout << "Файл " << F2n << " был записан";

    fclose(f1);
    fclose(f2);

    return 0;
}

//1. Компоненты файла fileA –  целые числа, значения которых повторяются.Получить файл fileB, образованный из fileA числами, которые встречаются в fileA более двух раз.
//2. Создать текстовый файл F1 не менее, чем из 5 строк, и записать в него информацию.Скопировать в файл F2 только те строки из F1, которые начинаются с цифры.