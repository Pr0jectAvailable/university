#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "RU-ru");

    const int mask = 48;
    unsigned int num = 0;
    int bnum = 23;
    char buf[33];

    cout << "Введи число: ";
    cin >> num;
    cout << endl;

    _itoa_s((num & mask), buf, 2);
    cout << "Извлечено из А: " << buf << endl;
    _itoa_s(bnum, buf, 2);
    cout << "Число B: " << buf << endl;
    _itoa_s(((num & mask) | (bnum)), buf, 2);
    cout << "Изменённое число: " << buf << endl << endl;

    int inp1 = 0, inp2 = 0, temp = 0;
    _itoa_s(num, buf, 2);
    cout << "Вы можете инвертировать в 1 n битов (минимум 1) в числе А вправо от позиции p (считая от 1)." << endl << "Число A: " << buf << endl << "Введите n: ";
    cin >> inp1;
    cout << endl << "Введите p: ";
    cin >> inp2;

    temp = pow(2, inp2 - 1);
    inp2 = temp;
    for (int i = 1; i < inp1; i++) {
        inp2 /= 2;
        temp += inp2;
    }
    _itoa_s((num | temp), buf, 2);
    cout << endl << "После преобразования: " << buf;
}

//1.	Ввести целое число A.Извлечь 2 бита числа A, начиная с пятого по счету справа,
//и вставить их в число B, начиная также с пятого бита по счету справа.
//2.	Инвертировать в 1 n битов в числе А вправо от позиции p.