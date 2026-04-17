#include <iostream>
#include <string>
using namespace std;

int main() {
    int k;
    cin >> k;

    string line = "";
    int power = 1;

    while (line.length() < k) {
        line += to_string(power);
        power *= 2;
    }

    cout << line[k - 1] << endl;
    return 0;
}