#include "fun.h"
#include <limits>

#define filename "stack.txt"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    Node* stack = nullptr;
    Node* even_stack = nullptr;
    Node* odd_stack = nullptr;
    int choice;
    DataType value;

    do {
        cout << "\nМЕНЮ\n";
        cout << "1 добавить элемент\n";
        cout << "2 удалить элемент\n";
        cout << "3 показать стек\n";
        cout << "4 очистить стек\n";
        cout << "5 сохранить в файл\n";
        cout << "6 загрузить из файла\n";
        cout << "7 выйти\n";
        cout << "8 разделить стек на чётные/нечётные\n";
        cout << "9 подсчитать повторяющиеся элементы\n";
        cout << ": ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите число: ";
            cin >> value;
            push(stack, value);
            cout << "добавлено\n";
            break;

        case 2:
            if (pop(stack, value)) {
                cout << "удалён элемент: " << value << endl;
            }
            else {
                cout << "ошибка\n";
            }
            break;

        case 3:
            print_stack(stack);
            break;

        case 4:
            clear(stack);
            cout << "Стек очищен\n";
            break;

        case 5:
            if (save_to_file(stack, filename)) {
                cout << "стек сохранён" << filename << endl;
            }
            else {
                cout << "ошибка\n";
            }
            break;

        case 6:
            if (load_from_file(stack, filename)) {
                cout << "загружено" << filename << endl;
            }
            else {
                cout << "ошибка\n";
            }
            break;

        case 7:
            clear(stack);
            clear(even_stack);
            clear(odd_stack);
            cout << "bye bye\n";
            break;

        case 8:
            if (is_empty_s_s(stack)) {
                cout << "ошибка\n";
            }
            else {
                split_by_parity(stack, even_stack, odd_stack);
                cout << "разделение выполнено\n";
                cout << "чётные элементы: ";
                print_stack(even_stack);
                cout << "нечётные элементы: ";
                print_stack(odd_stack);
            }
            break;

        case 9: {
            int dup = count_duplicates(stack);
            cout << "количество повторяющихся элементов: " << dup << endl;
            break;
        }
        default:
            cout << "ошибка\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    } while (choice != 7);

    return 0;
}