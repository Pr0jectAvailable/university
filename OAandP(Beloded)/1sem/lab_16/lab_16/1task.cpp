#include <iostream>

using namespace std;

int  square(int&);
void main()
{
    for (int x = 1; x <= 10; x++)
        cout << square(x) << ' ';
}
int square(int& y)
{
    return y * y;
}
