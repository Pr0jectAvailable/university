#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU-ru");
    srand((unsigned)time(NULL));
    
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const int max_size = 15;
    char mas_sym[max_size];

    int cycle = 0;
    cout << "Сколько циклов перемещения символов нужно: ";
    cin >> cycle;
    cout << endl;
    
    for (int i = 0; i < max_size; i++) {
        mas_sym[i] = alphabet[rand() % (51)];
    }

    for (int i = 0; i < max_size; i++) {
        cout << mas_sym[i] << endl;
    }
    cout << endl;

    for (int n = 0; n < cycle; n++) {
        char temp = mas_sym[0];
        for (int i = 0; i < max_size-1; i++) {
            mas_sym[i] = mas_sym[i + 1];
        }
        mas_sym[max_size - 1] = temp;
    }

    for (int i = 0; i < max_size; i++) {
        cout << mas_sym[i] << endl;
    }
    cout << endl;
}
//2.  Задан массив из k символов латинского алфавита.Вывести на экран все символы, которые вхо - дят в этот массив по одному разу.