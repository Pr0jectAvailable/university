#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU-ru");
    int n, num, sum = 0;

    cout << "Введите количество элементов: ";
    cin >> n;

    cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num % 2 == 0) {
            sum += num;
        }
    }

    cout << "Сумма чётных элементов: " << sum << endl;
    return 0;
}