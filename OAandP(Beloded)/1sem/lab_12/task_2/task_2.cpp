#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU-ru");
    int a = 0;
    cout << "Ведите число: ";
    cin >> a;
    
    const int* pa = &a;
    /**pa = 12;*/ //была ошибка (нельзя менять значение переменной а)
    int b = 20;
    pa = &b;

    cout << endl << "Адрес " << pa << " значение " << *pa << endl;

    int* const pu = &a;
    /*pu = &b;*/ //была ошибка (кон-стантный указатель менять нельзя)
    *pu = 12;

    cout << "Адрес " << pu << " значение " << *pu;

}