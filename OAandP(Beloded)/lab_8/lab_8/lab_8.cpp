
#include <iostream>

using namespace std;

//int main()
//{
//    setlocale(LC_CTYPE, "Russian");
//    float a, sum = 0; int i;
//    const int size = 4;
//    for (i = 0; i < size; i++) {
//        cout << "Введите a" << i << endl;
//        cin >> a;
//        sum = sum + a;
//    }
//    cout << "Ответ " << sum << endl;
//}

//int main()
//{
//    setlocale(LC_CTYPE, "Russian");
//    float a, sum = 0, res = 1; int i;
//    const int size = 4;
//    for (i = 0; i < size; i++) {
//        cout << "Введите a" << i << endl;
//        cin >> a;
//        sum += a * a;
//        res *= a;
//    }
//    cout << "Сумма квадратов: " << sum << endl;
//    cout << "Произведение значений: " << res << endl;
//}

int main()
{
    setlocale(LC_CTYPE, "Russian");
    float sum = 1; int i;
    const int size = 5;
    for (i = 1; i <= size; i++) {
        /*cout << i << endl;*/
        sum *= i;
    }
    cout << "Ответ " << sum << endl;
}