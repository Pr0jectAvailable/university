#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru-RU");
	int external[3];
	int internal[3];

	for (int i = 0; i < 3; i++) {
		cout << "\n¬ведите " << i+1 << " сторону внешней коробки ";
		cin >> external[i];
	}
	for (int i = 0; i < 3; i++) {
		cout << "\n¬ведите " << i+1 << " сторону внутренней коробки ";
		cin >> internal[i];
	}

	int volume = external[0] * external[1] * external[2] - internal[0] * internal[1] * internal[2];
	cout << "\n¬нутренн€€ коробка " << (volume >= 0 ? "помещаетс€" : "не помещаетс€") << " во внешнюю";

	return 0;
}