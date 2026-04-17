#include "stdafx.h"
#include "head.h"

bool leap_year(int* date) {
    if ((date[2] % 4 == 0 && !(date[2] % 100 == 0)) || (date[2] % 100 == 0 && date[2] % 400 == 0)) {
        return true;
    }
    return false;
}