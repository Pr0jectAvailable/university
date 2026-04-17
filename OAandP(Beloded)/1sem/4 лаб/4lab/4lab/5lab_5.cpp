#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU-ru");

	int k,rema;
	char buf[13];

	cout << "Введи колличество грибов ";
	cin >> k;
	rema = k % 10;
	if (k < 21 && k > 9 || rema == 0 || rema > 4) {
		strcpy_s(buf, "грибов");
	}
	else if (rema == 1) {
		strcpy_s(buf, "гриб");
	}
	else {
		strcpy_s(buf, "гриба");
	}

	cout <<"Вы собрали " << k << " " << buf;
	return 0;
}