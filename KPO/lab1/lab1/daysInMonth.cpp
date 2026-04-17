#include "stdafx.h"
#include "daysInMonth.h"

void daysInMonth(int* date) {
    int d = 0;;
    if (date[1] == 2 && leap_year(date)) {
        d = 29;
    }
    d = days[date[1] - 1];
    std::cout << "В " << monthNames[date[1] - 1] << ": " << d << " дней" << std::endl;
}