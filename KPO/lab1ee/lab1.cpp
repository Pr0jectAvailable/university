#include "stdafx.h"
#include "head.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "RU-ru");

    int *birthday = new int[2];
    birthday[0] = 24;
    birthday[1] = 8;

    int *date = new int[3];
    cout << "Введите дату (21052026): ";
    scanf_s("%2d%2d%4d", &date[0], &date[1], &date[2]);

    if (!check(date)) {
        cout << "\n\nДата введена неправильно";
        system("pause");
        return 0;
    }

    cout << "\n\nГод " << (leap_year(date) ? "високосный" : "не високосный") << endl;
    cout << "Это " << day_count(date) << " день в году\n";
    birthday_check(birthday,date);
    
    system("pause");
}