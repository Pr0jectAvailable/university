
#include <iostream>
#include <iomanip> 
#include <windows.h>

//дополнительно вар 1

using namespace std;

//void space(int quantity);
//
//int main()
//{
//    setlocale(LC_ALL, "ru_Ru");
//    SetConsoleCP(1251);
//
//    string fill;
//    cout << "Ввелуите символ для закрашивания полукруга:\t";
//    cin >> fill;
//    cout << "\n\n";
//
//    char sym = fill[0];
//
//    space(14);
//    cout << setw(12) << setfill(sym) << ' ' << endl;
//    space(12);
//    cout << setw(16) << setfill(sym) << ' ' << endl;
//    space(10);
//    cout << setw(20) << setfill(sym) << ' ' << endl;
//    space(8);
//    cout << setw(24) << setfill(sym) << ' ' << endl;
//    space(6);
//    cout << setw(28) << setfill(sym) << ' ' << endl;
//    space(4);
//    cout << setw(32) << setfill(sym) << ' ' << endl;
//    space(3);
//    cout << setw(34) << setfill(sym) << ' ' << endl;
//    space(2);
//    cout << setw(36) << setfill(sym) << ' ' << endl;
//    space(1);
//    cout << setw(38) << setfill(sym) << ' ' << endl;
//    cout << setw(40) << setfill(sym) << ' ' << endl;
//
//    cout << "\n\n\n\n\n";
//
//    int diag;
//
//    cout << "Введите диагональ квадрата:\t";
//    cin >> (diag);
//
//    cout << pow((diag), 2) / 2;
//}
//
void space(int quantity) {
    cout << setw(quantity) << setfill(' ') << ' ';
    return;
}

//дополнительно вариант 10

int main() {
	setlocale(LC_ALL, "ru_Ru");
	SetConsoleCP(1251);

	cout << "Введите символы для заполнения овала:\t";
	char sym;
	cin >> sym;

	space(14);
	cout << setw(12) << setfill(sym) << ' ' << endl;
	space(12);
	cout << setw(16) << setfill(sym) << ' ' << endl;
	space(10);
	cout << setw(20) << setfill(sym) << ' ' << endl;
	space(8);
	cout << setw(24) << setfill(sym) << ' ' << endl;
	space(6);
	cout << setw(28) << setfill(sym) << ' ' << endl;
	space(4);
	cout << setw(32) << setfill(sym) << ' ' << endl;
	space(3);
	cout << setw(34) << setfill(sym) << ' ' << endl;
	space(2);
    cout << setw(36) << setfill(sym) << ' ' << endl;
    space(1);
    cout << setw(38) << setfill(sym) << ' ' << endl;
    cout << setw(40) << setfill(sym) << ' ' << endl;

	cout << setw(40) << setfill(sym) << ' ' << endl;
	cout << setw(38) << setfill(sym) << ' ' << endl;
	space(1);
	cout << setw(36) << setfill(sym) << ' ' << endl;
	space(2);
	cout << setw(34) << setfill(sym) << ' ' << endl;

}