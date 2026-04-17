#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

#define SIZES 40

using namespace std;

struct Flight {
    string flight_num;
    string destination;
    string depart_time;
    string depart_date;
    string price;
    string seats;
};

void add();
void delete_el();
void search();
void print_all();
void printt(Flight f);
void save_to_file();
void load_from_file();

int sizem = 1;
Flight flights[SIZES] = { {"SU123", "Москва", "10:30", "20.05.2026", "5000", "150"} };

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    bool exit = false;
    while (!exit) {
        int inp = 0;
        cout << "Меню" << endl;
        cout << "Ввод элементов: 1" << endl;
        cout << "Вывод элементов: 2" << endl;
        cout << "Удаление элементов: 3" << endl;
        cout << "Поиск элементов: 4" << endl;
        cout << "Запись элементов в файл: 5" << endl;
        cout << "Чтение элементов из файла: 6" << endl;
        cout << "Выход: 7" << endl << endl;
        cout << "Ввод: ";
        cin >> inp;
        cout << endl;
        switch (inp) {
        case 1: {
            add();
            break;
        }
        case 2: {
            print_all();
            break;
        }
        case 3: {
            delete_el();
            break;
        }
        case 4: {
            search();
            break;
        }
        case 5: {
            save_to_file();
            break;
        }
        case 6: {
            load_from_file();
            break;
        }
        case 7: {
            exit = true;
            break;
        }
        default: {
            cout << "Неверный ввод" << endl;
            break;
        }
        }
    }
    return 0;
}

void add() {
    if (sizem >= SIZES) {
        cout << "Достигнут максимальный размер списка!" << endl;
        return;
    }
    Flight temp;
    cin.ignore();
    cout << "\nВведите номер рейса: ";
    getline(cin, temp.flight_num);
    cout << "\nВведите пункт назначения: ";
    getline(cin, temp.destination);
    cout << "\nВведите время вылета: ";
    getline(cin, temp.depart_time);
    cout << "\nВведите дату вылета: ";
    getline(cin, temp.depart_date);
    cout << "\nВведите стоимость билета: ";
    getline(cin, temp.price);
    cout << "\nВведите количество мест: ";
    getline(cin, temp.seats);
    cout << endl;
    flights[sizem] = temp;
    sizem++;
}

void delete_el() {
    int temp = 0;
    print_all();
    cout << "Сейчас в списке есть " << sizem << " элементов. Какой хотите удалить: ";
    cin >> temp;
    cout << endl;
    if (cin.fail() || temp < 1 || temp > sizem) {
        cout << endl << "неправильный номер" << endl;
        return;
    }
    for (int i = temp - 1; i < sizem - 1; i++) {
        flights[i] = flights[i + 1];
    }
    sizem--;
}

void search() {
    int cells_size = 0;
    int cells[SIZES];
    int temp = 0;
    cout << "Пункт, в котором вы хотите найти\n(Номер рейса: 1  Пункт назначения: 2  Время вылета: 3  Дата вылета: 4  Стоимость: 5  Количество мест: 6)\n: ";
    cin >> temp;
    if (cin.fail() || temp < 1 || temp > 6) {
        cout << endl << "Неправильный ввод" << endl;
        return;
    }
    string val;
    cin.ignore();
    cout << endl << "Напишите искомое значение: ";
    getline(cin, val);
    cout << endl;

    for (int i = 0; i < sizem; i++) {
        switch (temp) {
        case 1: {
            if (val == flights[i].flight_num) {
                cells[cells_size] = i;
                cells_size++;
            }
            break;
        }
        case 2: {
            if (val == flights[i].destination) {
                cells[cells_size] = i;
                cells_size++;
            }
            break;
        }
        case 3: {
            if (val == flights[i].depart_time) {
                cells[cells_size] = i;
                cells_size++;
            }
            break;
        }
        case 4: {
            if (val == flights[i].depart_date) {
                cells[cells_size] = i;
                cells_size++;
            }
            break;
        }
        case 5: {
            if (val == flights[i].price) {
                cells[cells_size] = i;
                cells_size++;
            }
            break;
        }
        case 6: {
            if (val == flights[i].seats) {
                cells[cells_size] = i;
                cells_size++;
            }
            break;
        }
        }
    }

    if (cells_size == 0) {
        cout << "Ничего не найдено." << endl;
    }
    else {
        cout << endl << "Найдены следующие ячейки по параметрам" << endl;
        for (int i = 0; i < cells_size; i++) {
            cout << i + 1 << ":" << endl;
            printt(flights[cells[i]]);
            cout << endl;
        }
    }
    cout << endl << endl;
}

void print_all() {
    for (int i = 0; i < sizem; i++) {
        printt(flights[i]);
        cout << endl;
    }
    cout << endl;
}

void printt(Flight f) {
    printf_s("Номер рейса: %s\tПункт назначения: %s\tВремя вылета: %s\tДата вылета: %s\tСтоимость: %s\tМест: %s\t",
        f.flight_num.c_str(), f.destination.c_str(), f.depart_time.c_str(), f.depart_date.c_str(), f.price.c_str(), f.seats.c_str());
}

void save_to_file() {
    ofstream fout("data.txt");
    if (!fout) {
        cout << "Ошибка открытия файла" << endl;
        return;
    }
    fout << sizem << endl;
    for (int i = 0; i < sizem; i++) {
        fout << flights[i].flight_num << endl;
        fout << flights[i].destination << endl;
        fout << flights[i].depart_time << endl;
        fout << flights[i].depart_date << endl;
        fout << flights[i].price << endl;
        fout << flights[i].seats << endl;
    }
    fout.close();
    cout << "Данные сохранены" << endl;
}

void load_from_file() {
    ifstream fin("data.txt");
    if (!fin) {
        cout << "Файл data.txt не найден" << endl;
        return;
    }
    fin >> sizem;
    fin.ignore();
    for (int i = 0; i < sizem && i < SIZES; i++) {
        getline(fin, flights[i].flight_num);
        getline(fin, flights[i].destination);
        getline(fin, flights[i].depart_time);
        getline(fin, flights[i].depart_date);
        getline(fin, flights[i].price);
        getline(fin, flights[i].seats);
    }
    fin.close();
    cout << "Данные загружены" << endl;
}