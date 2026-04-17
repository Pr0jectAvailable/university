#include <iostream>

using namespace std;

bool leap_year(int* date);
int day_count(int* date);
bool check(int* date);
void birthday_check(int* birthday, int* date);

int main(){
    setlocale(LC_ALL, "RU-ru");

    int *birthday = new int[2];
    birthday[0] = 24;
    birthday[1] = 8;

    int *date = new int[3];
    cout << "Введите дату (21052026):";
    scanf_s("%2d%2d%4d", &date[0], &date[1], &date[2]);

    if (!check(date)) {
        cout << "\n\nДата введена неправильно";
        return 0;
    }

    cout << "\n\nГод " << (leap_year(date) ? "високосный" : "не високосный") << endl;
    cout << "Это " << day_count(date) << " день в году\n";
    birthday_check(birthday,date);
    
}

bool check(int* date) {
    if (date[1] > 12 || date[1] < 1) {
        return false;
    }
    if (date[0] < 1) {
        return false;
    }
    if (date[1] == 2) {
        if (leap_year(date) && date[0] > 29) {
            return false;
        }
        else if(date[2] > 28){
            return false;
        }
    }
    else if (date[1] % 2 == 0 && date[0] > 30) {
        return false;
    }
    else if(date[0] > 31){
        return false;
    }
    return true;
}

bool leap_year(int *date) {
    if ((date[2] % 4 == 0 && !(date[2] % 100 == 0)) || (date[2] % 100 == 0 && date[2] % 400 == 0)) {
        return true;
    }
    return false;
}

int day_count(int* date) {
    int count = 0;
    for (int i = 0; i < date[1] - 1; i++) {
        if (date[1] == 2) {
            if (leap_year(date)) {
                count += 29;
            }
            else {
                count += 28;
            }
        }
        else if(date[1] % 2 == 0) {
            count += 30;
        }
        else {
            count += 31;
        }
    }
    count += date[0];
    return count;
}

void birthday_check(int* birthday, int* date) {
    int count = 0;
    for (int i = 0; i < birthday[1] - 1; i++) {
        if (birthday[1] == 2) {
            if (leap_year(birthday)) {
                count += 29;
            }
            else {
                count += 28;
            }
        }
        else if (birthday[1] % 2 == 0) {
            count += 30;
        }
        else {
            count += 31;
        }
    }
    count += birthday[0];
    
    int today = day_count(date);

    if (today == count) {
        cout << "С днём рождения!\n";
    }
    else if (today < count) {
        cout << "Осталось " << count - today << " дней до дня рождения\n";
    }
    else if (today > count) {
        cout << "Прошло " << today - count << " дней с дня рождения\n";
    }
}