#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int *position = new int;
    int* word_position = new int(1);
    char *s = new char[256];

    cout << "Enter string: ";
    gets_s(s, 256);
    cout << endl << "Enter position (count from 1): ";
    cin >> *position;
    (*position)--;

    for (int i = 0; i < *position; i++) {
        if (*(s + i) == ' ') {
            (*word_position)++;
        }
    }

    cout << endl << "word number: " << *word_position << " symbol: '" << *(s + (*position)) << "'";

    delete position;
    delete word_position;
    delete[] s;

    return 0;
}

//Дана строка символов, состоящая из произвольного текста, слова разделены пробелами.
//Определить по - рядковый номер слова, один из символов которого находится на k - 
//й позиции(если на k - ю позицию попа - дает пробел, то найти номер предыдущего слова).