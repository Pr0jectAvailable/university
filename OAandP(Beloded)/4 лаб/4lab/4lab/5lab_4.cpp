#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU-ru");

	int a, b, c, d;

	puts("Введите a ");
	cin >> a;
	puts("\n\nВведите b ");
	cin >> b;
	puts("\n\nВведите c ");
	cin >> c;

	d = pow(b, 2) - 4 * a * c;

	if (d < 0) {
		puts("\nКорней нет");
	}
	else {
		int x1, x2;
		x1 = (-b + sqrt(d) / 2 * a);
		x2 = (-b - sqrt(d) / 2 * a);
		cout << "x1: " << x1 << "; x2: " << x2;
	}

	return 0;
}