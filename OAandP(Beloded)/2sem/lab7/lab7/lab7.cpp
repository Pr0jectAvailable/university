#include <iostream>
#include <fstream>
#include <string>

#define FILE "fie.txt"

using namespace std;

struct NumStruct {
    int number;
    NumStruct* next;
};

NumStruct* head = nullptr;

NumStruct* new_element(int num, NumStruct* address = nullptr);
void add_element(int value);
void print_list();
bool delete_element(int value);
bool search_element(int value);
void save_to_file();
void load_from_file();
void clear_list();
void sum_negative_two_digit();
void sum_negative_muloffive();

NumStruct* new_element(int num, NumStruct* address) {
    NumStruct* temp = new NumStruct;
    temp->number = num;
    temp->next = address;
    return temp;
}

void add_element(int value) {
    NumStruct* new_node = new_element(value);
    if (!head) {
        head = new_node;
        return;
    }
    NumStruct* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = new_node;
}

void print_list() {
    if (!head) {
        cout << "список пуст\n";
        return;
    }
    cout << "список: ";
    NumStruct* current = head;
    while (current) {
        cout << current->number << " ";
        current = current->next;
    }
    cout << endl;
}

bool delete_element(int value) {
    if (!head) {
        return false;
    }

    if (head->number == value) {
        NumStruct* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    NumStruct* current = head;
    while (current->next && current->next->number != value) {
        current = current->next;
    }
    if (current->next) {
        NumStruct* temp = current->next;
        current->next = temp->next;
        delete temp;
        return true;
    }
    return false;
}

bool search_element(int value) {
    int pos = 1;
    NumStruct* current = head;
    while (current) {
        if (current->number == value) {
            cout << "элемент " << value << " найден на позиции " << pos << endl;
            return true;
        }
        current = current->next;
        pos++;
    }
    cout << "элемент " << value << " не найден\n";
    return false;
}

void save_to_file() {
    ofstream out(FILE);
    if (!out) {
        cout << "ошибка\n";
        return;
    }
    NumStruct* current = head;
    while (current) {
        out << current->number << endl;
        current = current->next;
    }
    out.close();
    cout << "список сохранён в файл " << FILE << endl;
}

void load_from_file() {
    ifstream in(FILE);
    if (!in) {
        cout << "ошибка\n";
        return;
    }
    clear_list();

    int value;
    while (in >> value) {
        add_element(value);
    }
    in.close();
    cout << "список загружен из файла " << FILE << endl;
}

void clear_list() {
    while (head) {
        NumStruct* temp = head;
        head = head->next;
        delete temp;
    }
}

void sum_negative_two_digit() {
    int sum = 0;
    bool found = false;
    NumStruct* current = head;
    while (current) {
        int val = current->number;
        if (val < 0 && val >= -99 && val <= -10) {
            sum += val;
            found = true;
        }
        current = current->next;
    }
    if (found) {
        cout << "сумма: " << sum << endl;
    }
    else {
        cout << "элементов удолетворяющих поиску нет" << endl;
    }
}

void sum_negative_muloffive() {
    int sum = 0;
    bool found = false;
    NumStruct* current = head;
    while (current) {
        int val = current->number;
        if (val < 0 && val % 5 == 0) {
            sum += val;
            found = true;
        }
        current = current->next;
    }
    if (found) {
        cout << "сумма: " << sum << endl;
    }
    else {
        cout << "элементов удолетворяющих поиску нет" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    int choice;
    int value;

    do {
        cout << "\n------------------\n";
        cout << "1. Добавить элемент\n";
        cout << "2. Удалить элемент\n";
        cout << "3. Поиск элемента\n";
        cout << "4. Вывести список\n";
        cout << "5. Записать список в файл\n";
        cout << "6. Считать список из файла\n";
        cout << "7. Сумма отрицательных двузначных элементов\n";
        cout << "8. Сумма отрицательных элементов, кратных 5\n";
        cout << "0. Выход\n";
        cout << "ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "введите число для добавления: ";
            cin >> value;
            add_element(value);
            cout << "элемент добавлен\n";
            break;
        case 2:
            cout << "введите число для удаления: ";
            cin >> value;
            if (delete_element(value)) {
                cout << "элемент удалён\n";
            }
            else {
                cout << "элемент не найден\n";
            }
            break;
        case 3:
            cout << "введите число для поиска: ";
            cin >> value;
            search_element(value);
            break;
        case 4:
            print_list();
            break;
        case 5:
            save_to_file();
            break;
        case 6:
            load_from_file();
            break;
        case 7:
            sum_negative_two_digit();
            break;
        case 8:
            sum_negative_muloffive();
            break;
        case 0:
            cout << "выход\n";
            break;
        default:
            cout << "неверный выбор\n";
        }
    } while (choice != 0);

    clear_list();
    return 0;
}