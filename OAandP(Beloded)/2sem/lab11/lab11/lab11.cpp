#include <iostream>
#include <locale>

using namespace std;

struct Number {
    int info;
    Number* next;
};

void create(Number** begin, Number** end, int p, int* count, int maxSize);
void view(Number* begin, int count);
int dequeue(Number** begin, Number** end, int* count);
void findMinMax(Number* begin);
int getCount(Number* begin);

int main() {
    setlocale(LC_ALL, "rus");

    int maxSize;
    cout << "максимальный размер очереди: ";
    cin >> maxSize;

    Number* begin = NULL;
    Number* end = NULL;
    int count = 0;

    int choice, value;

    do {
        cout << "\nменю" << endl;
        cout << "1 добавить элемент (отрицательный)" << endl;
        cout << "2 удалить элемент" << endl;
        cout << "3 вывести все элементы и их количество" << endl;
        cout << "4 найти минимальный и максимальный элемент" << endl;
        cout << "0 выход" << endl;
        cout << "Ввод: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "введите число: ";
            cin >> value;
            create(&begin, &end, value, &count, maxSize);
            break;
        case 2:
            if (count > 0) {
                dequeue(&begin, &end, &count);
            }
            else {
                cout << "пусто" << endl;
            }
            break;
        case 3:
            view(begin, count);
            break;
        case 4:
            findMinMax(begin);
            break;
        case 0:
            cout << "выход" << endl;
            break;
        default:
            cout << "неверный выбор" << endl;
        }
    } while (choice != 0);

    while (begin != NULL) {
        dequeue(&begin, &end, &count);
    }

    return 0;
}

void create(Number** begin, Number** end, int p, int* count, int maxSize) {
    if (*count >= maxSize) {
        cout << "очередь переполнена" << endl;
        return;
    }
    if (p >= 0) {
        cout << "в очереди должны быть только отрицательные числа" << endl;
        return;
    }
    Number* t = new Number;
    t->info = p;
    t->next = NULL;
    if (*begin == NULL) {
        *begin = *end = t;
    }
    else {
        (*end)->next = t;
        *end = t;
    }
    (*count)++;
    cout << "элемент " << p << " добавлен" << endl;
}

void view(Number* begin, int count) {
    if (begin == NULL) {
        cout << "пусто" << endl;
        return;
    }
    Number* t = begin;
    cout << "очередь: ";
    while (t != NULL) {
        cout << t->info << " ";
        t = t->next;
    }
    cout << endl;
    cout << "элементов в очереди: " << count << endl;
}

int dequeue(Number** begin, Number** end, int* count) {
    if (*begin == NULL) {
        cout << "пусто" << endl;
        return 0;
    }
    Number* t = *begin;
    int val = t->info;
    *begin = (*begin)->next;
    if (*begin == NULL) {
        *end = NULL;
    }
    delete t;
    (*count)--;
    cout << "элемент " << val << " удалён" << endl;
    return val;
}

void findMinMax(Number* begin) {
    if (begin == NULL) {
        cout << "пусто" << endl;
        return;
    }
    Number* t = begin;
    int minVal = t->info;
    int maxVal = t->info;
    while (t != NULL) {
        if (t->info < minVal) minVal = t->info;
        if (t->info > maxVal) maxVal = t->info;
        t = t->next;
    }
    cout << "минимальный: " << minVal << endl;
    cout << "максимальный: " << maxVal << endl;
}