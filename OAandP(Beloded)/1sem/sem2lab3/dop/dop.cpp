#include <iostream>

using namespace std;

int check();

int main() {
    setlocale(LC_ALL, "rus");

    static int sum = 0;
    static int count = 0;

    bool choice = true;
    while (choice) {
        int n;
        cout << "Введите размер массива: ";

        n = check();

        if (n <= 0) {
            cout << "Размер отрицательный" << endl;
            break;
        }

        int* arr = new int[n];

        cout << "Введите " << n << " элементов: ";
        int* ptr = arr;
        for (int i = 0; i < n; ++i) {
            *ptr = check();
            ptr++;
        }

        ptr = arr;
        for (int i = 0; i < n; ++i) {
            sum += *ptr;
            ptr++;
        }
        count += n;

        double average = 0.0;
        if (count != 0) {
            average = 1.0 * sum / count;
        }

        cout << "Cумма: " << sum << endl;
        cout << "Cреднее: " << average << endl;

        delete[] arr;

        char inp;
        cout << "Хотите ввести ещё? (y/n): ";
        cin >> inp;
        if (inp != 'y' && inp != 'Y') {
            choice = false;
        }
    }

    return 0;
}

int check() {
    int inp = 0;
    while (!(cin >> inp)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Не ломай мне прогу. Введите значение: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return inp;
}