#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

#define SIZES 40

using namespace std;

struct Terminal {
	string train_num;
	string destination;
	string date;
	string arrival;
	string departure;
};

void add();
void delete_el();
void search();
void print_all();
void printt(Terminal t);
void save_to_file();
void load_from_file();

int sizem = 1;
Terminal terminal[SIZES] = { {"1208", "Минск", "ПН, ВТ, ЧТ", "17:30 следующего дня", "16.30"}};

int main(){
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
		default:{
			cout << "Неверный ввод" << endl;
			break;
		}
		}
	}
	return 0;
}

void add() {
	Terminal temp;
	cin.ignore();
	cout << "\nВведите номер поезда: ";
	getline(cin, temp.train_num);
	cout << "\nВведите пункт назначения: ";
	getline(cin, temp.destination);
	cout << "\nВведите дни следования (пн, вт, и т.д.): ";
	getline(cin, temp.date);
	cout << "\nВведите время прибытия: ";
	getline(cin, temp.arrival);
	cout << "\nВведите время отправления: ";
	getline(cin, temp.departure);
	cout << endl;
	terminal[sizem] = temp;
	sizem++;
	return;
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
		terminal[i] = terminal[i + 1];
	}
	sizem--;
	return;
}

void search() {
	int cells_size = 0;
	int cells[SIZES];
	int temp = 0;
	cout << "Пункт, в котором вы хотите найти\n(Номер поезда: 1  Пункт назначения: 2  Дни следования: 3  Время прибытия: 4  Время отправления: 5)\n: ";
	cin >> temp;
	if (cin.fail() || temp < 0 || temp > 6) {
		cout << endl << "Неправильный ввод" << endl;
		return;
	}
	string val;
	cin.ignore();
	cout << endl << "Напишите искомое значение: ";
	getline(cin, val);
	cout << endl;

	for (int i = 0; i < temp - 1; i++) {
		switch (temp) {
		case 1: {
			if (val == terminal[i].train_num) {
				cells[cells_size] = i;
				cells_size++;
			}
			break;
		case 2: {
			if (val == terminal[i].destination) {
				cells[cells_size] = i;
				cells_size++;
			}
			break;
		}
		case 3: {
			if (val == terminal[i].date) {
				cells[cells_size] = i;
				cells_size++;
			}
			break;
		}
		case 4: {
			if (val == terminal[i].arrival) {
				cells[cells_size] = i;
				cells_size++;
			}
			break;
		}
		case 5: {
			if (val == terminal[i].departure) {
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
	}
	cout << endl << "Найдены следующие ячейки по параметрам" << endl;
	for (int i = 0; i < cells_size;i++) {
		cout << i << ":" << endl;
		printt(terminal[cells[i]]);
	}
	cout << endl << endl;
	return;
}

void print_all() {
	for (int i = 0; i < sizem; i++) {
		printt(terminal[i]);
		cout << endl;
	}
	cout << endl << endl;
	return;
}

void printt(Terminal t) {
	printf_s("Номер поезда: %s\tПункт назначения: %s\tДни следования: %s\tВремя прибытия: %s\tВремя отправления: %s\t", t.train_num.c_str(), t.destination.c_str(), t.date.c_str(), t.arrival.c_str(),t.departure.c_str());
	return;
}

void save_to_file() {
	ofstream fout("data.txt");
	if (!fout) {
		cout << "Ошибка открытия файла" << endl;
		return;
	}
	fout << sizem << endl;
	for (int i = 0; i < sizem; i++) {
		fout << terminal[i].train_num << endl;
		fout << terminal[i].destination << endl;
		fout << terminal[i].date << endl;
		fout << terminal[i].arrival << endl;
		fout << terminal[i].departure << endl;
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
		getline(fin, terminal[i].train_num);
		getline(fin, terminal[i].destination);
		getline(fin, terminal[i].date);
		getline(fin, terminal[i].arrival);
		getline(fin, terminal[i].departure);
	}
	fin.close();
	cout << "Данные загружены" << endl;
}