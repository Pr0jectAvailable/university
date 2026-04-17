#include "stdafx.h"
#include "head.h"

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
        else if (date[2] > 28) {
            return false;
        }
    }
    else if (date[1] % 2 == 0 && date[0] > 30) {
        return false;
    }
    else if (date[0] > 31) {
        return false;
    }
    return true;
}