// main.cpp
#include "Heap.h"
#include <iostream>
using namespace std;

heap::CMP cmpAAA(void* a1, void* a2)
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
    heap::CMP rc = heap::EQUAL;
    if (A1->x > A2->x)
        rc = heap::GREAT;
    else if (A2->x > A1->x)
        rc = heap::LESS;
    return rc;
#undef A2
#undef A1
}

int main()
{
    setlocale(LC_ALL, "rus");
    int k, choice, idx;
    heap::Heap h1 = heap::create(30, cmpAAA);

    for (;;)
    {
        cout << "\n1 - вывод кучи на экран\n";
        cout << "2 - добавить элемент\n";
        cout << "3 - удалить максимальный элемент\n";
        cout << "4 - удалить минимальный элемент\n";
        cout << "5 - удалить i-й элемент\n";
        cout << "6 - объединить с другой кучей\n";
        cout << "7 - вычислить среднее арифметическое\n";
        cout << "8 - вывести максимальный элемент (без удаления)\n";
        cout << "0 - выход\n";
        cout << "сделайте выбор: "; cin >> choice;

        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            h1.scan(0);
            break;
        case 2:
        {
            AAA* a = new AAA;
            cout << "введите ключ: "; cin >> k;
            a->x = k;
            h1.insert(a);
            break;
        }
        case 3:
        {
            void* removed = h1.extractMax();
            if (removed)
                cout << "Удалён максимальный элемент: " << ((AAA*)removed)->x << endl;
            else
                cout << "Куча пуста!\n";
            break;
        }
        case 4:
        {
            void* removed = h1.extractMin();
            if (removed)
                cout << "Удалён минимальный элемент: " << ((AAA*)removed)->x << endl;
            else
                cout << "Куча пуста!\n";
            break;
        }
        case 5:
        {
            cout << "Введите индекс элемента (0.." << h1.size - 1 << "): ";
            cin >> idx;
            void* removed = h1.extractI(idx);
            if (removed)
                cout << "Удалён элемент с индексом " << idx << ": " << ((AAA*)removed)->x << endl;
            else
                cout << "Неверный индекс или куча пуста!\n";
            break;
        }
        case 6:
        {
            heap::Heap h2 = heap::create(30, cmpAAA);
            int n;
            cout << "Сколько элементов добавить во вторую кучу? ";
            cin >> n;
            for (int i = 0; i < n; ++i)
            {
                AAA* a = new AAA;
                cout << "ключ " << i + 1 << ": ";
                cin >> k;
                a->x = k;
                h2.insert(a);
            }
            cout << "Вторая куча:\n";
            h2.scan(0);

            heap::Heap h3 = heap::Heap::unionHeap(h1, h2);
            cout << "Результат объединения:\n";
            h3.scan(0);
            break;
        }
        case 7:
        {
            double avg = h1.average();
            if (h1.isEmpty())
                cout << "Куча пуста, среднее не определено.\n";
            else
                cout << "Среднее арифметическое: " << avg << endl;
            break;
        }
        case 8:
        {
            void* maxElem = h1.getMax();
            if (maxElem)
                cout << "Максимальный элемент: " << ((AAA*)maxElem)->x << endl;
            else
                cout << "Куча пуста!\n";
            break;
        }
        default:
            cout << "Введена неверная команда!\n";
        }
    }
    return 0;
}