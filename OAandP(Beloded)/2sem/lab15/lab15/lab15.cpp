#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

void bubbleSortDesc(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int hoarePartitionDesc(int* arr, int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while (true) {
        do {
            i++;
        } while (arr[i] > pivot);
        do {
            j--;
        } while (arr[j] < pivot);
        if (i >= j) {
            return j;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void quickSortDesc(int* arr, int low, int high) {
    if (low < high) {
        int pi = hoarePartitionDesc(arr, low, high);
        quickSortDesc(arr, low, pi);
        quickSortDesc(arr, pi + 1, high);
    }
}

int main() {
    srand(time(0));

    int sizes[] = { 1000, 2000, 3000, 4000, 5000 };
    int numSizes = 5;

    cout << "время измерения в микросекундах:" << endl;
    for (int k = 0; k < numSizes; k++) {
        int size = sizes[k];
        int* original = new int[size];
        for (int i = 0; i < size; i++) {
            original[i] = rand() % 10000;
        }

        int* arr1 = new int[size];
        for (int i = 0; i < size; i++) {
            arr1[i] = original[i];
        }
        auto start = chrono::high_resolution_clock::now();
        bubbleSortDesc(arr1, size);
        auto end = chrono::high_resolution_clock::now();
        auto durationBubble = chrono::duration_cast<chrono::microseconds>(end - start).count();
        delete[] arr1;

        int* arr2 = new int[size];
        for (int i = 0; i < size; i++) {
            arr2[i] = original[i];
        }
        start = chrono::high_resolution_clock::now();
        quickSortDesc(arr2, 0, size - 1);
        end = chrono::high_resolution_clock::now();
        auto durationQuick = chrono::duration_cast<chrono::microseconds>(end - start).count();
        delete[] arr2;

        cout << "размер " << size << ": пузырьковая = " << durationBubble << " микросекунд, быстрая = " << durationQuick << " микросекунд" << endl;

        delete[] original;
    }

    int n;
    cout << "\nразмер массива A: ";
    cin >> n;
    int* A = new int[n];
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int maxIndex = 0;
    int maxVal = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > maxVal) {
            maxVal = A[i];
            maxIndex = i;
        }
    }

    int countB = 0;
    for (int i = maxIndex + 1; i < n; i++) {
        if (i % 2 == 0) {
            countB++;
        }
    }

    int* B = new int[countB];
    int idx = 0;
    for (int i = maxIndex + 1; i < n; i++) {
        if (i % 2 == 0) {
            B[idx++] = A[i];
        }
    }

    cout << "\nArray B (original): ";
    for (int i = 0; i < countB; i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    int* B1 = new int[countB];
    for (int i = 0; i < countB; i++) {
        B1[i] = B[i];
    }
    bubbleSortDesc(B1, countB);
    cout << "B sorted by bubble (descending): ";
    for (int i = 0; i < countB; i++) {
        cout << B1[i] << " ";
    }
    cout << endl;
    delete[] B1;

    int* B2 = new int[countB];
    for (int i = 0; i < countB; i++) {
        B2[i] = B[i];
    }
    quickSortDesc(B2, 0, countB - 1);
    cout << "B sorted by Hoare (descending): ";
    for (int i = 0; i < countB; i++) {
        cout << B2[i] << " ";
    }
    cout << endl;
    delete[] B2;

    delete[] A;
    delete[] B;

    cout << "\n=== New task: input arrays A and B ===\n";
    int sizeA, sizeB;
    cout << "Enter size of array A: ";
    cin >> sizeA;
    int* A2 = new int[sizeA];
    cout << "Enter " << sizeA << " integers for A: ";
    for (int i = 0; i < sizeA; i++) {
        cin >> A2[i];
    }

    cout << "Enter size of array B: ";
    cin >> sizeB;
    int* B3 = new int[sizeB];
    cout << "Enter " << sizeB << " integers for B: ";
    for (int i = 0; i < sizeB; i++) {
        cin >> B3[i];
    }

    int maxB = B3[0];
    for (int i = 1; i < sizeB; i++) {
        if (B3[i] > maxB) {
            maxB = B3[i];
        }
    }

    int countC = 0;
    for (int i = 0; i < sizeA; i++) {
        if (A2[i] < maxB) {
            countC++;
        }
    }

    int* C = new int[countC];
    int idxC = 0;
    for (int i = 0; i < sizeA; i++) {
        if (A2[i] < maxB) {
            C[idxC++] = A2[i];
        }
    }

    cout << "\nArray C (original): ";
    for (int i = 0; i < countC; i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    int* C1 = new int[countC];
    for (int i = 0; i < countC; i++) {
        C1[i] = C[i];
    }
    bubbleSortDesc(C1, countC);
    cout << "C sorted by bubble (descending): ";
    for (int i = 0; i < countC; i++) {
        cout << C1[i] << " ";
    }
    cout << endl;
    delete[] C1;

    int* C2 = new int[countC];
    for (int i = 0; i < countC; i++) {
        C2[i] = C[i];
    }
    quickSortDesc(C2, 0, countC - 1);
    cout << "C sorted by Hoare (descending): ";
    for (int i = 0; i < countC; i++) {
        cout << C2[i] << " ";
    }
    cout << endl;
    delete[] C2;

    delete[] A2;
    delete[] B3;
    delete[] C;

    return 0;
}