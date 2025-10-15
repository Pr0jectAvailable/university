#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU-ru");
	int k;
	puts("Вы хотите купить автомобиль? (1-да, 2-нет)");
	cin >> k;
	switch (k){
	case 1: {
		puts("Какой ? (1 - Майбах, 2 - Тойота, 3 - Лада)");
		cin >> k;

		switch (k) {
			case 1: {
				puts("Не слишком дорого?"); break;
			}
			case 2: {
				puts("Хороший выбор"); break;
			}
			case 3: {
				puts("Сомнительный выбор"); break;
			}
			break;
		}
		break;
	}
	case 2: {
		puts("Полезно ходить пешком"); break;
	}
	default: {
		puts("Некорректный вариант"); break;
	}
	}
	return 0;
}