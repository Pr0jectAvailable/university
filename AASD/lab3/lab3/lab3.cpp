#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

void printArray(int* arr, int n, const char* name) {
    cout << name << ": ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

void quickSort(int* arr, int left, int right) {
    if (left >= right) return;
    int pivot = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++; j--;
        }
    }
    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

void quickSortСall(int* arr, int n) {
    if (n > 0) quickSort(arr, 0, n - 1);
}

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(0));

    int N;
    cout << "Введите N: ";
    cin >> N;

    if (N <= 0) {
        cerr << "N должно быть положительным." << endl;
        return 1;
    }

    int* A = new int[N];
    int* B = new int[N];
    int* C = new int[N];
    int* D = new int[N];
    int* E = new int[N];

    for (int i = 0; i < N; i++) {
        A[i] = rand() % 10000 + 1;
    }

    printArray(A, N, "A");

    for (int i = 0; i < N; i++) {
        B[i] = A[i];
        C[i] = A[i];
        D[i] = A[i];
        E[i] = A[i];
    }

    auto start = chrono::high_resolution_clock::now();
    bubbleSort(B, N);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, nano> elapsed_ns = end - start;
    double elapsed_us = elapsed_ns.count() / 1000.0;
    printArray(B, N, "B (пузырьковая)");
    cout << "Время: " << elapsed_ns.count() << " нс (" << elapsed_us << " мкс, " << elapsed_us / 1000.0 << " мс)\n";

    start = chrono::high_resolution_clock::now();
    insertionSort(C, N);
    end = chrono::high_resolution_clock::now();
    elapsed_ns = end - start;
    elapsed_us = elapsed_ns.count() / 1000.0;
    printArray(C, N, "C (вставками)");
    cout << "Время: " << elapsed_ns.count() << " нс (" << elapsed_us << " мкс, " << elapsed_us / 1000.0 << " мс)\n";

    start = chrono::high_resolution_clock::now();
    selectionSort(D, N);
    end = chrono::high_resolution_clock::now();
    elapsed_ns = end - start;
    elapsed_us = elapsed_ns.count() / 1000.0;
    printArray(D, N, "D (выбором)");
    cout << "Время: " << elapsed_ns.count() << " нс (" << elapsed_us << " мкс, " << elapsed_us / 1000.0 << " мс)\n";

    start = chrono::high_resolution_clock::now();
    quickSortСall(E, N);
    end = chrono::high_resolution_clock::now();
    elapsed_ns = end - start;
    elapsed_us = elapsed_ns.count() / 1000.0;
    printArray(E, N, "E (быстрая)");
    cout << "Время: " << elapsed_ns.count() << " нс (" << elapsed_us << " мкс, " << elapsed_us / 1000.0 << " мс)\n";

    delete[] A;
    delete[] B;
    delete[] C;
    delete[] D;
    delete[] E;

    return 0;
}