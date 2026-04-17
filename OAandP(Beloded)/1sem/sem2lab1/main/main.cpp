#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define fileA "fileA.txt"
#define fileB "fileB.txt"

#define tempSize 256

using namespace std;

int main() {
    setlocale(LC_ALL, "RU-ru");

    FILE* fA;
    FILE* fB;

    fA = fopen(fileA, "r");
    fB = fopen(fileB, "w");

    if (!fA || !fB) {
        perror("fopen failed");
        cout << "Error opening file" << endl;
        system("pause");
        return 1;
    }

    char temp[tempSize];
    fgets(temp, sizeof temp, fA);

    int output[tempSize / 2];

    int count = 0;
    int count_c = 0;
    char num[256] = {0};
    bool state = false;
    for (int i = 0; i < strlen(temp) + 1; i++) {
        if (temp[i] == ' ' || i == strlen(temp)) {
            output[count] = atoi(num);
            count++;
            num[0] = '\0';
            count_c = 0;
        }
        else {
            num[count_c] = temp[i];
            count_c++;
        }        
    }

    int c = 0;
    int k[tempSize / 2];
    char buf[tempSize / 2];
    num[0] = '\0';

    for (int i = 0; i < count; i++) {
        int n = output[i];
        for (int b = i + 1; b < count; b++) {
            if (n == output[b]) {
                bool st = false;
                for (int l = 0; l < c; l++) {
                    if (k[l] == n) {
                        st = true;
                        l = c;
                    }
                }
                if (st == false) {
                    k[c] = n;
                    c++;

                    snprintf(buf, sizeof buf, "%d", n);
                    strcat(num, buf);
                    strcat(num, " ");
                }
                b = count;
            }
        }
    }

    cout << "Полученные числа: " << num << endl;

    fputs(num, fB);

    cout << "Файл " << fileB << " был записан\n";

    fclose(fA);
    fclose(fB);

    system("pause");
    return 0;
}

//1. Компоненты файла fileA –  целые числа, значения которых повторяются.Получить файл fileB, образованный из fileA числами, которые встречаются в fileA более двух раз.
//2. Создать текстовый файл F1 не менее, чем из 5 строк, и записать в него информацию.Скопировать в файл F2 только те строки из F1, которые начинаются с цифры.
