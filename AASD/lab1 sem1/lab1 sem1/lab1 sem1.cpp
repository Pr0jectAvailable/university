#include <iostream>
#include <chrono>
#include <numeric>
#include <iomanip>
#include <cmath>

using namespace std;

int cycle(int n);
int recursion(int n);

int main(){
    setlocale(LC_ALL, "RU-ru");

    int n_num = 0;
    cout << "\nВведите N-число последовательности Фибоначчи: ";
    cin >> n_num;

    auto start = chrono::high_resolution_clock::now();
    cout << "\nЧисло Фибоначии циклом: " << cycle(n_num);
    auto end = chrono::high_resolution_clock::now();
    auto duration_mic = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "\nВремя выполнения " << duration_mic.count() << " микросекунды ";
    printf_s("\n\nВремя циклом %lld минут %.3f секунд\n",duration_mic.count() / 60'000'000,(duration_mic.count() % 60'000'000) / 1'000'000.0);

    start = chrono::high_resolution_clock::now();
    cout << "\n\nЧисло Фибоначчи рекурсией: " << recursion(n_num);
    end = chrono::high_resolution_clock::now();
    duration_mic = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "\nВремя выполнения " << duration_mic.count() << " микросекунды";
    printf_s("\n\nВремя циклом %lld минут %.3f секунд\n", duration_mic.count() / 60'000'000, (duration_mic.count() % 60'000'000) / 1'000'000.0);
}

int cycle(int n) {
    unsigned long long int sum[2] = {0,1};
    for (int i = 2; i < n; i++) {
        unsigned long long int temp = sum[0] + sum[1];
        sum[0] = sum[1];
        sum[1] = temp;
    }
    return sum[1];
}

int recursion(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;

    return recursion(n - 1) + recursion(n - 2);
}