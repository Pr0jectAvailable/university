#include "stdafx.h"
#include "day_count.h"

int day_count(int* date) {
    int count = 0;
    for (int i = 0; i < date[1] - 1; ++i) {
        count += days[i];
    }
    count += date[0];
    if (leap_year(date) && count > 59) {
        count += 1;
    }
    return count;
}