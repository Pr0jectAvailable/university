#include "stdafx.h"
#include "head.h"

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
        else if (date[1] % 2 == 0) {
            count += 30;
        }
        else {
            count += 31;
        }
    }
    count += date[0];
    return count;
}