#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

#define FILE1 "./FILE1.txt"
#define FILE2 "./FILE2.txt"
#define buf_s 1024

int main(){
	setlocale(LC_ALL, "rus");

	string alphabet = "AEIOU";

	ifstream f1(FILE1);
	ofstream f2(FILE2);

	if (f1.fail()){
		cout << "Ошибка открытия файла " << FILE1;
		return 1;
	}

	string out;
	string buf;
	int w_count = 0;
	int letter_max = 0;
	int word_out = 0;
	while (getline(f1,buf)) {
		string word = "";
		buf += "\n";
		int letter_count = 0;
		bool state = false;
		int count = 0;

		for (int i = 0; i < buf.length(); i++) {
			/*cout << buf[i] << endl;*/
			if (!state && buf[i] != ' ' && buf[i] != '\n') {
				/*cout << buf.length() << endl;*/
				state = true;
				count++;
				w_count++;
			}
			else if (state == true && (buf[i] == ' ' || buf[i] == '\n')) {
				state = false;
				int c = 0;
				for (int p = 0; p < word.length(); p++) {
					for (int b = 0; b < alphabet.length(); b++) {
						if (alphabet[b] == toupper(word[p])) {
							c++;
						}
					}
				}
				if (c > letter_max) {
					letter_max = c;
					word_out = w_count;
				}
				word = "";
			}
			if (state) {
				letter_count++;
				word += buf[i];
			}
		}

		if (count > 2) {
			out += buf;
		}
	}

	f2 << out;

	cout << "Файл " << FILE2 << " записан" << endl;
	cout << "Слово имеющее больше колличество согласных " << word_out << " в изначальном документе";
	
	f1.close();


	return 0;
}

//1. Скопировать из файла FILE1 в файл FILE2 все строки, в которых более 2 слов.Определить номер слова, в котором больше всего гласных букв.
//2. Ввести с клавиатуры строку символов, состоящую из цифр и скобок, и записать ее в файл.Прочитать из файла данные, посчитать и вывести количество скобок различного вида
