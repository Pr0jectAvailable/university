#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char s[256];
    int wordCount = 0;
    int write_pos = 0;
    bool inWord = false;

    cout << "Enter string: ";
    gets_s(s);

    int len = strlen(s);

    for (int i = 0; i <= len; i++) {
        if (s[i] != ' ' && s[i] != '\0') {
            if (!inWord) {
                wordCount++;
                inWord = true;
            }

            if (wordCount % 2 == 1) {
                s[write_pos++] = s[i];
            }
        }
        else {
            if (inWord) {
                inWord = false;
                if (wordCount % 2 == 1 && s[i] == ' ') {
                    s[write_pos++] = ' ';
                }
            }
        }
    }
    s[write_pos] = '\0';
    cout << "Result: " << s << endl;

    return 0;
}

//Отредактировать заданное предложение, удаляя из него все слова с чётными номерами.