#include <iostream>
//4. Пройдет ли шар радиуса r через ромбообразное отверстие с диагоналями p и q?
using namespace std;

int main() {
	setlocale(LC_ALL, "ru-RU");
	
	int r_sphere = 0;
	int diag1 = 0;
	int diag2 = 0;

	cout << "Введи радиус шара ";
	cin >> r_sphere;

	cout << "\nТеперь диагональ ромба ";
	cin >> diag1;
	cout << "\nИ ещё одну ";
	cin >> diag2;

	cout << "\nДанный шар " << (int((diag1 * diag2) / (2 * sqrt(diag1 * diag1 + diag2 * diag2))) >= r_sphere ? "пройдёт" : "не пройдёт")
		<< " в ромб";

	return 0;
}