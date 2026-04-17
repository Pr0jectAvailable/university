#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>

#define fileA "fileA.txt"
#define fileB "fileB.txt"

#define msize 1024

using namespace std;

int main(){
    setlocale(LC_ALL, "RU-ru");

    FILE* fA = fopen(fileA, "r");
    FILE* fB = fopen(fileB, "w");

    if (!fA || !fB) {
        perror("fopen failed");
        cout << "Error opening file" << endl;
        fclose(fA);
        fclose(fB);
        system("pause");
        return 1;
    }

    char temp[msize] = { 0 };
    fgets(temp, sizeof temp, fA);

    bool state = false;
    int num[msize];
    int count = 0;
    char n[msize] = { 0 };

    for (int i = 0; i < strlen(temp); i++) {
        if (temp[i] != ' ') {
            state = true;

            char t[2] = {temp[i] , '\0'};
            strcat(n, t);
            /*cout << t << endl;*/
        }
        if((state == true && temp[i] == ' ') || i == strlen(temp)-1) {
            state = false;
            num[count] = atoi(n);
            count++;
            n[0] = '\0';
        }
    }
    
    char buf[msize] = { 0 };
    temp[0] = '\0';

    for (int i = 0; i < count; i++) {
        /*cout << num[i] << endl;*/
        if (num[i] > 0) {
            sprintf(buf, "%d", num[i]);
            strcat(buf, " ");
            strcat(temp, buf);
        }
    }

    fputs(temp, fB);

    cout << "Файл " << fileB << " записан";

    fclose(fA);
    fclose(fB);

    return 0;
}

//1. Компоненты файла fileA – целые отличные от нуля положительные и отрицательные числа.Получить файл fileB, состоящий из положительных чисел.
//2. Компоненты файла f – целые двухзначные числа.Получить файл g, образованный из f включением только чисел больших некоторого числа, вводимого с клавиатуры.
