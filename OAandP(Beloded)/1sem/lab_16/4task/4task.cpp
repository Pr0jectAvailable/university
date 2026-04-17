#include <iostream>
#include <string>

using namespace std;

void matrix(int** mat, int a, int b, int k, int n);
void sentense(string& str);

int main() {
    setlocale(LC_ALL, "Ru-ru");
    srand(time(NULL));
    int inp = 0;
    cout << "1 - работа с матрицей\n2 - работа с предложением\n:";
    cin >> inp;

    switch (inp) {
    case 1: {
        int k, n;
        cout << "Введите количество строк (до 12): ";
        cin >> k;
        cout << "Введите количество столбцов (до 8): ";
        cin >> n;
        if (k > 12 || n > 8) {
            cout << "Слишком много строк или столбцов";
            break;
        }

        int** mat = new int* [k];
        for (int i = 0; i < k; i++) {
            mat[i] = new int[n];
        }

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++)
                mat[i][j] = 1 + (rand() % 100);
        }

        cout << endl;

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }

        cout << endl;

        int line_from, line_to;

        cout << "Введите элемент a: ";
        cin >> line_from;
        cout << "Введите элемент b: ";
        cin >> line_to;

        cout << endl;

        matrix(mat, line_from, line_to, k, n);

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }

        for (int i = 0; i < k; i++) {
            delete[] mat[i];
        }
        delete[] mat;

        break;
    }
    case 2: {
        string text;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Введите текст: ";
        getline(cin, text);

        sentense(text);

        break;
    }
    default: {
        cout << "Неверный выбор!" << endl;
        break;
    }
    }
    return 0;
}

void matrix(int** mat, int a, int b, int k, int n) {
    int line_f = -1;
    int line_t = -1;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (line_f == -1 && mat[i][j] == a) {
                line_f = i;
            }
            if (line_t == -1 && mat[i][j] == b) {
                line_t = i;
            }
        }

        if (line_f != -1 && line_t != -1) {
            break;
        }
    }

    if (line_f != -1 && line_t != -1 && line_f != line_t) {
        int* temp = new int[n];
        for (int i = 0; i < n; i++) {
            temp[i] = mat[line_f][i];
        }

        for (int i = 0; i < n; i++) {
            mat[line_f][i] = mat[line_t][i];
            mat[line_t][i] = temp[i];
        }

        delete[] temp;
    }

    return;
}

void sentense(string& str) {
    int start = 0;
    bool inWord = false;

    for (int i = 0; i <= str.length(); i++) {
        if (i < str.length() && str[i] != ' ' && !inWord) {
            inWord = true;
            start = i;
        }
        else if ((i == str.length() || str[i] == ' ') && inWord) {
            int end = i - 1;
            
            if (end - start + 1 >= 2) {
                bool endsWithAYA = false;
                
                char secondLast = str[end - 1];
                char last = str[end];
                
                if ((secondLast == 'а' || secondLast == 'А') &&
                    (last == 'я' || last == 'Я')) {
                    endsWithAYA = true;
                }
                
                if (endsWithAYA) {
                    for (int j = start; j <= end; j++) {
                        cout << str[j];
                    }
                    cout << " ";
                }
            }
            inWord = false;
        }
    }
    cout << endl;
}