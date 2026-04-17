#include "stdafx.h"
#include "lab1.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "RU-ru");

    int *birthday = new int[2];
    birthday[0] = 24; //ДД дня рождения
    birthday[1] = 8; //ММ дня рождения

    int *date = new int[3];
    cout << "Введите дату (ДДММГГГГ): ";
    scanf_s("%2d%2d%4d", &date[0], &date[1], &date[2]);

    if (!check(date)) {
        cout << "\n\nДата введена неправильно";
        system("pause");
        return 0;
    }

    cout << "\n\nГод " << (leap_year(date) ? "високосный" : "не високосный") << endl;
    cout << "Это " << day_count(date) << " день в году\n";
    birthday_check(birthday,date);

    cout << endl;
    daysInMonth(date);

    cout << "Введите дату (ДДДГГГГ): ";
    scanf_s("%3d%4d", &date[0], &date[2]);
    if (date[0] < 1 || (leap_year(date) && date[0] > 366) || (!leap_year(date) && date[0] > 365)) {
        cout << "\n\nДата введена неправильно";
        system("pause");
        return 0;
    }
    
    int* temp = dateFromDayNumber(date);
    cout << endl << "День: " << temp[0] << " Месяц: " << temp[1] << " Год: " << temp[2] << endl;
    
    system("pause");
}