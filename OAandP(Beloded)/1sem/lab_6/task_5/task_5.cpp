#include <iostream>

using namespace std;

int main()
{
    int b = 3;
    int a = 6;
    double c = 0.0006;

    for (int i = 8; i <= 24; i += 4) {
        double t = a * i / (pow(a, 2) - b) * exp(-a);

        double x = t > 5 * c ? 0.0048 + i * a : a + i * i * t;

        cout << "i = " << i << endl;
        cout << "x = " << x << endl << endl;
    }

    return 0;
}
