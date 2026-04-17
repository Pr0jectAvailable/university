#include "stdafx.h"
#include "dateFromNumber.h"

int* dateFromDayNumber(int* date) {
    int* temp = new int[3];
    bool leap = false;

    if (leap_year(date)) {
        leap = true;
    }

    int month = 0;
    while (date[0] > (month == 1 && leap ? 29 : days[month])) {
        if (month == 1 && leap) {
            date[0] -= 29;
        }
        else{
            date[0] -= days[month];
        }
        month++;
    }
    temp[0] = date[0];
    temp[1] = month + 1;
    temp[2] = date[2];
    return temp;
}