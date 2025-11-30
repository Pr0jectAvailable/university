
#include <iostream>
#include <string>

using namespace std;

int main()
{
    bool state = true;
    int i = 10;
    while (state) {
        int calculation = i * i;
        string num = to_string(calculation);
        if (calculation < 1000 && num[0] - '0' < num[1] - '0' && num[1] - '0' < num[2] - '0') {
            cout << calculation;
            state = false;
        }
        i++;
    }
}
