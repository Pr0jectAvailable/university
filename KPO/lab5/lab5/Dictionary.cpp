#include <iostream>
#include <cstring>
#include "Dictionary.h"

using namespace std;

namespace Dictionary {

    static int findIndex(const Instance& inst, int id) {
        for (int i = 0; i < inst.size; ++i) {
            if (inst.dictionary[i].id == id) {
                return i;
            }
        }
        return -1;
    }

    Instance Create(const char name[DICTNAMEMAXSIZE], int size) {
        if (strlen(name) >= DICTNAMEMAXSIZE) {
            throw THROW01;
        }
        if (size <= 0 || size > DICTMAXSIZE) {
            throw THROW02;
        }

        Instance inst;
        strcpy_s(inst.name, name);
        inst.maxsize = size;
        inst.size = 0;
        inst.dictionary = new Entry[size];
        return inst;
    }

    void AddEntry(Instance& inst, Entry ed) {
        if (inst.size >= inst.maxsize) {
            throw THROW03;
        }
        if (findIndex(inst, ed.id) != -1) {
            throw THROW04;
        }
        inst.dictionary[inst.size] = ed;
        inst.size++;
    }

    void DelEntry(Instance& inst, int id) {
        int idx = findIndex(inst, id);
        if (idx == -1) {
            throw THROW06;
        }
        for (int i = idx; i < inst.size - 1; ++i) {
            inst.dictionary[i] = inst.dictionary[i + 1];
        }
        inst.size--;
    }

    Entry GetEntry(Instance inst, int id) {
        int idx = findIndex(inst, id);
        if (idx == -1) {
            throw THROW05;
        }
        return inst.dictionary[idx];
    }

    void UpdEntry(Instance& inst, int id, Entry new_ed) {
        int idx = findIndex(inst, id);
        if (idx == -1) {
            throw THROW07;
        }
        if (new_ed.id != id) {
            int existingIdx = findIndex(inst, new_ed.id);
            if (existingIdx != -1 && existingIdx != idx)
                throw THROW08;
        }

        inst.dictionary[idx] = new_ed;
    }

    void Delete(Instance& d) {
        delete[] d.dictionary;
        d.dictionary = nullptr;
        d.size = 0;
        d.maxsize = 0;
        d.name[0] = '\0';
    }

    void Print(Instance d) {
        cout << "Пространство имён: " << d.name << std:: endl;
        for (int i = 0; i < d.size; ++i) {
            cout << "  id = " << d.dictionary[i].id << ", имя = " << d.dictionary[i].name << std::endl;
        }
    }

}

int main() {
    setlocale(LC_ALL,"rus");
    try {
        Dictionary::Instance d1 = Dictionary::Create("Преподаватели", 5);
        Dictionary::Entry e1 = { 1, "Гладкий" }, e2 = { 2, "Веялкин" }, e3 = { 3, "Смелов" }, e4 = { 4, "Урбанович" }, e5 = { 2, "Пацей" };
        Dictionary::AddEntry(d1, e1);
        Dictionary::AddEntry(d1, e2);
        Dictionary::AddEntry(d1, e3);
        Dictionary::AddEntry(d1, e4);
        Dictionary::Entry ex2 = Dictionary::GetEntry(d1,4);
        Dictionary::DelEntry(d1,2);
        Dictionary::Entry newentry1 = {6, "Гурин"};
        Dictionary::UpdEntry(d1,3, newentry1);
        Dictionary::Print(d1);
        Dictionary::Instance d2 = Dictionary::Create("Студенты", 5);
        Dictionary::Entry s1 = { 1, "Иванов" }, s2 = { 2, "Петров" }, s3 = { 3, "Сидоров" };
        Dictionary::AddEntry(d2, s1);
        Dictionary::AddEntry(d2, s2);
        Dictionary::AddEntry(d2, s3);
        Dictionary::Entry newentry3 = {3, "Николаев"};
        Dictionary::UpdEntry(d2,3, newentry3);
        Dictionary::Print(d2);
        Delete(d1);
        Delete(d2);
    }
    catch (const char* e) {
        std::cout << e << std::endl;
    };
    system("pause");
    return 0;
}