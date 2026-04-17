#include <iostream>

using namespace std;

int main(){
    int* ptr ,l = 5;
    int sum = 0;
    int sum_bet = 0;
    int neg_fir = -1;
    int neg_sec = -1;

    if (!(ptr = (int*)malloc(l * sizeof(int)))) {
        cout << "Not enough memory";
        return 0;
    }

    for (int i = 0; i < l; i++) {
        cout << "\nInput element: ";
        scanf_s("%d", ptr + i);
    }

    for (int i = 0; i < l; i++) {
        if (i % 2 != 0) {
            sum += *(ptr + i);
        }
        
        if (*(ptr + i) < 0 && neg_fir == -1) {
            neg_fir = i;
        }
        printf("%d ", *(ptr + i));
    }

    for (int i = l - 1; i >= 0; i--) {
        if (*(ptr + i) < 0 && neg_sec == -1) {
            neg_sec = i;
            i = -1;
        }
    }

    for (int i = neg_fir + 1; i < neg_sec; i++) {
        sum_bet += *(ptr + i);
    }

    printf("\nSum of odd index %d ", sum);
    printf("\nSum between negative %d ", sum_bet);

    return 0;
}