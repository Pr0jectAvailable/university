#include "Heap.h"
#include <iostream>
#include <iomanip>

void AAA::print()
{
    std::cout << x;
}

namespace heap
{
    Heap create(int maxsize, CMP(*f)(void*, void*))
    {
        return *(new Heap(maxsize, f));
    }

    int Heap::left(int ix)
    {
        return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
    }

    int Heap::right(int ix)
    {
        return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
    }

    int Heap::parent(int ix)
    {
        return (ix + 1) / 2 - 1;
    }

    void Heap::swap(int i, int j)
    {
        void* buf = storage[i];
        storage[i] = storage[j];
        storage[j] = buf;
    }

    void Heap::heapify(int ix)
    {
        int l = left(ix), r = right(ix), irl = ix;
        if (l > 0)
        {
            if (isGreat(storage[l], storage[ix])) irl = l;
            if (r > 0 && isGreat(storage[r], storage[irl])) irl = r;
            if (irl != ix)
            {
                swap(ix, irl);
                heapify(irl);
            }
        }
    }

    void Heap::insert(void* x)
    {
        int i;
        if (!isFull())
        {
            storage[i = ++size - 1] = x;
            while (i > 0 && isLess(storage[parent(i)], storage[i]))
            {
                swap(parent(i), i);
                i = parent(i);
            }
        }
    }

    void* Heap::extractMax()
    {
        void* rc = nullptr;
        if (!isEmpty())
        {
            rc = storage[0];
            storage[0] = storage[size - 1];
            size--;
            heapify(0);
        }
        return rc;
    }

    void Heap::scan(int) const
    {
        int probel = 20;
        std::cout << '\n';
        if (size == 0)
            std::cout << "Куча пуста";
        for (int u = 0, y = 0; u < size; u++)
        {
            std::cout << std::setw(probel + 10) << std::setfill(' ');
            ((AAA*)storage[u])->print();
            if (u == y)
            {
                std::cout << '\n';
                if (y == 0)
                    y = 2;
                else
                    y += y * 2;
            }
            probel /= 2;
        }
        std::cout << '\n';
    }

    void Heap::siftUp(int i)
    {
        while (i > 0 && isLess(storage[parent(i)], storage[i]))
        {
            swap(parent(i), i);
            i = parent(i);
        }
    }

    void Heap::siftDown(int i)
    {
        heapify(i);
    }

    void Heap::buildHeap()
    {
        for (int i = size / 2 - 1; i >= 0; --i)
            siftDown(i);
    }

    void* Heap::extractMin()
    {
        if (isEmpty())
            return nullptr;

        int minIdx = 0;
        for (int i = 1; i < size; ++i)
            if (compare(storage[i], storage[minIdx]) == LESS)
                minIdx = i;

        void* rc = storage[minIdx];
        storage[minIdx] = storage[size - 1];
        size--;

        if (minIdx < size)
        {
            siftUp(minIdx);
            siftDown(minIdx);
        }
        return rc;
    }

    void* Heap::extractI(int index)
    {
        if (index < 0 || index >= size)
            return nullptr;

        void* rc = storage[index];
        storage[index] = storage[size - 1];
        size--;

        if (index < size)
        {
            siftUp(index);
            siftDown(index);
        }
        return rc;
    }

    Heap Heap::unionHeap(const Heap& h1, const Heap& h2)
    {
        int newMaxSize = h1.size + h2.size;
        Heap newHeap(newMaxSize, h1.compare);

        for (int i = 0; i < h1.size; ++i) {
            newHeap.storage[newHeap.size++] = h1.storage[i];
        }
        for (int i = 0; i < h2.size; ++i) {
            newHeap.storage[newHeap.size++] = h2.storage[i];
        }
        newHeap.buildHeap();
        return newHeap;
    }

    double Heap::average() const
    {
        if (size == 0) return 0.0;
        long long sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += ((AAA*)storage[i])->x;
        }
        return static_cast<double>(sum) / size;
    }

    void* Heap::getMax() const
    {
        if (isEmpty()) return nullptr;
        return storage[0];
    }
}