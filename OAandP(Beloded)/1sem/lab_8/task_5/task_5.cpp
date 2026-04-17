#include <iostream>

using namespace std;

int main(){
    setlocale(LC_ALL, "RU-ru");
    float sum = 0;
    float inp[5];

    cout << "Введите 5 чисел\n";
    for (int i = 0; i < 5; i++) {
        float n = 0;
        cout << endl << i+1 << ": ";
        cin >> n;
        inp[i] = n;
        sum += n * n;
    }
    
    cout << endl;
    for (float t = 0.5; t <= 3; t += 0.5) {
        
        if (t <= 2) {
            cout << "y = " << cos(t * t) << endl;
        }
        else {
            cout << "y = " << sum + t << endl;
        }
    }
}
