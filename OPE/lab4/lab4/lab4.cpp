
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RU-ru");
    int inp = 0;

    cout << "Введите день недели от 1 до 7: ";
    cin >> inp;

    switch(inp){
    case 1: {
        cout << "\n\nПонедельник";
        break;
    }
    case 2: {
        cout << "\n\nВторник";
        break;
    }
    case 3: {
        cout << "\n\nСреда";
        break;
    }
    case 4: {
        cout << "\n\nЧетверг";
        break;
    }
    case 5: {
        cout << "\n\nПятница";
        break;
    }
    case 6: {
        cout << "\n\nСуббота";
        break;
    }
    case 7: {
        cout << "\n\nВоскресенье";
        break;
    }
    default: {
        cout << "\n\nЭЭЭЭЭЭЭЭ, идём по СЦЕНАРИЮ";
        break;
    }
    }

    return 0;
}
