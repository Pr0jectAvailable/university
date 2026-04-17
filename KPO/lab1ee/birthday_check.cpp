#include "stdafx.h"
#include "head.h"

using namespace std;

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