#include <iostream>

#define point 10

using namespace std;

int main(){
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int inp = 0;
    cout << "Введите количество участников: ";
    cin >> inp;

    int target = point * 0.6;
    int pwinners = 0;

    int* points = new int[inp];
    for (int i = 0; i < inp; i++) {
        points[i] = rand() % point + 1;
        cout << points[i] << ", ";
        if (points[i] >= target) {
            pwinners++;
        }
    }
    cout << endl << endl;

    cout << pwinners << " призёров";
    
    return 0;
}
