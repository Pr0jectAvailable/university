
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru-RU");
    bool state = true;
    int counter = 0;
    int i = 1;

    while (state) {
        if (i % 3 == 0 || i % 5 == 0) {
            cout << "Число: " << i << endl;
            counter++;
            if (counter >= 6) {
                state = false;
            }
        }
        i++;
    }
}
