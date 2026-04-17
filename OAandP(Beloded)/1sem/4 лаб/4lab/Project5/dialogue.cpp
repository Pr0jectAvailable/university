#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU-ru");

	int inp = 0;
	cout << "Хочешь жить в достатке? (1-да, 2-нет): ";
	cin >> inp;

	switch (inp) {
	case 1: {
		cout << "\n\nОкей, следующий шаг. Сможешь встать с кровати? (1-да, 2-нет): ";
		cin >> inp;
		
		switch (inp) {
		case 1: {
			cout << "\n\nТак, осталось последнее, выбрать план.\n(1 - Пойти учиться на программиста, 2 - Искать работу через TOR, 3 - Пойти в тот самый тг канал, 4 - Кассир в маке, 5 - Вернуться на диван): ";
			cin >> inp;

			switch (inp) {
			case 1: {
				cout << "\n\nВы достаточно зарабатываете, но на нахождение работы мечты, вы потратили пол жизни.";
				break;
			}
			case 2: {
				cout << "\n\nНеплохой выход из черезывчайной ситуации, который привёл вас в 30 лет на места не столь отдалённые.";
				break;
			}
			case 3: {
				cout << "\n\nИз за вашего успеха, вы повторили сюжет breaking bad.";
				break;
			}
			case 4: {
				cout << "\n\nСчастивщик, проживающий спокойную жизнь.";
				break;
			}
			case 5: {
				cout << "\n\nНу да, встать с кровати было всё таки сложно.";
				break;
			}
			default: {
				cout << "\nне дядя, давай с начала";
				break;
			}
			}
			break;
		}
		case 2: {
			cout << "\nЯ тоже : )";
			break;
		}
		default: {
			cout << "\n: |";
			break;
		}
		}
		break;
	}
	case 2: {
		cout << "\nНе, ну как бы ладно";
		break;
	}
	default: {
		cout << "\nээээээ, давай с начала";
		break;
	}
	}
	return 0;
}