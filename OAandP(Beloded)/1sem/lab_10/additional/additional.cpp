#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "RU-ru");
    srand((unsigned)time(NULL));

    const int size_month = 31;
    const int max_value = 300;

    int measure_values[size_month];
    for (int i = 0; i < size_month;i++) {
        measure_values[i] = rand() % max_value;
    }

    int sum = 0;
    int day = 0;
    for (int i = 0; i < size_month - 6; i++) {
        int tempo = 0;
        for (int n = 0; n < 7; n++) {
            tempo += measure_values[i + n];
        }
        if (tempo > sum) {
            sum = tempo;
            day = i+1;
        }
    }

    for (int i = 0; i < size_month; i++) {
        cout << measure_values[i] << endl;
    }
    cout << endl;

    cout << "Самые дождливые 7 дней начинаются с " << day << " дня месяца, и заканчиваются " << day + 6 << " днём месяца";
}
// 1.	Имеются результаты n ежедневных измерений количества выпавших осадков. За какую из недель (отрезок времени длиной 7 дней), 
// считая с начала периода измерений, выпало наибольшее количество осадков?