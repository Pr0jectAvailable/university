#include <iostream>
#include <regex>

using namespace std;

int main(){
    setlocale(LC_ALL, "rus");

    string num;
    cout << "Введите слитно номер начиная с +: ";
    cin >> num;
    cout << endl;

    regex tempplate(R"(^\+[0-9]{12}$)");

    if (regex_match(num,tempplate)) {
        cout << "Номер введён правильно";
    }
    else {
        cout << "Номер введён неправильно";
    }

    return 0;
}
