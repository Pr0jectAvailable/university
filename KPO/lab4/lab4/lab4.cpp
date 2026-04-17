#include <iostream>

using namespace std;

typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;

struct Date {
    day dd;
    month mm; 
    year yyyy;

    bool operator == (Date& other) {
        return yyyy == other.yyyy && mm == other.mm && dd == other.dd;
    }

    bool operator < (Date& other) {
        if (yyyy != other.yyyy) {
            return yyyy < other.yyyy;
        }
        if (mm != other.mm) {
            return mm < other.mm;
        }
        return dd < other.dd;
    }

    bool operator > (Date& other) {
        return !(*this < other) && !(*this == other);
    }
};

int main(){
    setlocale(LC_ALL, "rus");

    Date date1 = { 7,1,1980 };
    Date date2 = { 7,2,1993 };
    Date date3 = { 7,1,1980 };

    if (date1 < date2) cout << "истина" << endl;
    else cout << "ложь" << endl;

    if (date1 > date2) cout << "истина" << endl;
    else cout << "ложь" << endl;

    if (date1 == date2) cout << "истина" << endl;
    else cout << "ложь" << endl;

    if (date1 == date3) cout << "истина" << endl;
    else cout << "ложь" << endl;
}