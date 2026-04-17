#include "stdafx.h"
#include "leap_year.h"

bool leap_year(int* date) {
    if ((date[2] % 400 == 0) || (date[2] % 4 == 0 && date[2] % 100 != 0)) {
        return true;
    }
    return false;
}