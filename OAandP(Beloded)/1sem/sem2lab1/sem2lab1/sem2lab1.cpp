#include <stdio.h>
#include <iostream>
#include <string>

#define sizem 256

using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    int a; errno_t err;
    FILE* f;
    err = fopen_s(&f, "a.txt", "w+");
    if (err != 0)
    {
        perror("Невозможно создать файл\n");
        return EXIT_FAILURE;
    }
    for (a = 0; a < 70; a += 3)
    {
        fprintf(f, "%d, ", a);
    }
    printf("Данные записаны в файл test.txt\n");

    
    
    rewind(f);
    char buffer[sizem];
    if (fgets(buffer, sizeof(buffer), f) != nullptr)
    {
        string text(buffer);
        printf("Данные: %s", text.c_str());
    }
    fclose(f);
    return 0;
}
