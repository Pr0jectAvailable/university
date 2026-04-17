#include <iostream>

using namespace std;

int summ_fun(int a, int b); // прототип функции для 22 задания

int main() {
    // порядковый номер по списку: 13
    const int n = 13;

    // Задание 4: переменные типа bool
    bool b1 = false;   // false - 0x00, адрес 0x0056FB0B
    bool b2 = true;    // true  - 0x01, адрес 0x0056FAFF

    // Задание 5
    char latinChar = 'e';   // 'e' (ASCII: 0x65), адрес 0x0056FAF3

    // Задание 6
    char cyrillicChar = 'е'; // русская 'е' (Windows-1251: 0xe5), адрес 0x0056FAE7

    // Задание 7
    wchar_t latinWide = L'F'; // 'F' (Unicode 0x0046), кодировка UTF-16LE, адрес 0x0056FAD8

    // Задание 8
    wchar_t cyrillicWide = L'Ф'; // 'Ф' (Unicode 0x0424), кодировка UTF-16LE, адрес 0x0056FACC

    // Задание 9
    short sh1 = 9 + n;        // X = 22, значение 0x0016, адрес 0x0056FAC0
    short sh2 = -(9 + n);      // -X = -22, значение 0xFFEA, адрес 0x0056FAB4

    // вычисление (16 бит):
    //   X = 22 = 0x0016
    //   -X = -22:
    //   1) 22 = 0x0016
    //   2) инверсия: 0xFFE9
    //   3) +1: 0xFFEA

    // Задание 10
    short maxShort = 0x7FFF;   // максимальное short: 32767, адрес 0x0056FAA8
    short minShort = 0x8000;   // минимальное short: -32768, адрес 0x0056FA9C

    // Задание 11
    unsigned short maxUShort = 0xFFFF; // максимальное unsigned short: 65535, адрес 0x0056FA90
    unsigned short minUShort = 0x0000; // минимальное unsigned short: 0, адрес 0x0056FA84

    // Задание 12
    int i1 = 10 + n;        // Y = 23, значение 0x00000017, адрес 0x0056FA78
    int i2 = -(10 + n);      // -Y = -23, значение 0xFFFFFFE9, адрес 0x0056FA6C

    // вычисление (32 бита):
    //   Y = 23 = 0x00000017
    //   -Y = -23:
    //   1) 23 = 0x00000017
    //   2) инверсия: 0xFFFFFFE8
    //   3) +1: 0xFFFFFFE9

    // Задание 13
    int maxInt = 0x7FFFFFFF;   // максимальное int: 2147483647, адрес 0x0056FA60
    int minInt = 0x80000000;   // минимальное int: -2147483648, адрес 0x0056FA54

    // Задание 14
    unsigned int maxUInt = 0xFFFFFFFF; // максимальное unsigned int: 4294967295, адрес 0x0056FA48
    unsigned int minUInt = 0x00000000; // минимальное unsigned int: 0, адрес 0x0056FA3C

    // Задание 15
    long l1 = 11 + n;        // Z = 24, значаение 0x00000018, адрес 0x0056FA30
    long l2 = -(11 + n);      // -Z = -24, значаение 0xFFFFFFE8, адрес 0x0056FA24

    // вычисление:
    //   Z = 24 = 0x00000018
    //   -Z = -24:
    //   1) 24 = 0x00000018
    //   2) инверсия: 0xFFFFFFE7
    //   3) +1: 0xFFFFFFE8

    // Задание 16
    long maxLong = 0x7FFFFFFF;   // максимальное long: 2147483647, адрес 0x0056FA18
    long minLong = 0x80000000;   // минимальное long: -2147483648, адрес 0x0056FA0C

    // Задание 17
    unsigned long maxULong = 0xFFFFFFFF; // максимальное unsigned long: 4294967295, адрес 0x0056FA18
    unsigned long minULong = 0x00000000; // минимальное unsigned long: 0, адрес 0x0056F9F4

    // Задание 18
    float f1 = 1.0f + n;      // S = 14.0f, значение 0x41600000, адрес 0x0056F9E8
    float f2 = -(1.0f + n);    // -S = -14.0f, значение 0xC1600000, адрес 0x0056F9DC

    // вычисление (IEEE 754):
    //   14 = 1110.0, 1.110 * 2^3
    //   Знак = 0
    //   Порядок = 3 + 127 = 130 = 10000010
    //   Мантисса = 11000000000000000000000 (23 бита)
    //   14.0: знак 0 10000010 11000000000000000000000 = 0x41600000
    //   -14.0: знак 1 - 1 10000010 11000000000000000000000 = 0xC1600000

    // Задание 19
    double zero = 0.0;
    double posInf = 1.0 / zero; // значение: INF, адрес 0x003DF784
    double negInf = -1.0 / zero; // значение: -INF, адрес 0x003DF774
    double nanInf = 0.0 / zero; // значение: IND, адрес 0x003DF764

    // Задание 20


    // объявление переменных
    char c = 'c'; // значение: 'c' (0x63)
    wchar_t wc = L'c'; // значение: L'c' (0x0063)
    short s = 1; // значение: 1 (0x0001)
    int i = 2; // значение: 2 (0x00000002)
    float f = 3.0; // значение: 3.0f (0x40400000)
    double d = 4.0; // значение: 4.0 (0x40100000)

    // создание указателей на них
    char* lc = &c; //значение: 0x003df75b
    wchar_t* lwc = &wc; //значение: 0x003df74c
    short* ls = &s; //значение: 0x003df740
    int* li = &i; //значение: 0x003df734
    float* lf = &f; //значение: 0x003df728
    double* ld = &d; //значение: 0x003df718

    lc += 3; //значение: 0x003df75e
    lwc += 3; //значение: 0x003df752
    ls += 3; //значение: 0x003df746
    li += 3; //значение: 0x003df740
    lf += 3; //значение: 0x003df734
    ld += 3; //значение: 0x003df730

    // Задание 21

    // объявление переменных
    char cs = 'c';
    wchar_t wcs = L'c';
    short ss = 1;
    int is = 2;
    float fs = 3.0;
    double ds = 4.0;

    // создание ссылок для них
    char& rc = cs; // значение: 'c' (0x63)
    wchar_t& rwc = wcs; // значение: L'c' (0x0063)
    short& rs = ss; // значение: 1 (0x0001)
    int& ri = is; // значение: 2 (0x00000002)
    float& rf = fs; // значение: 3.0f (0x40400000)
    double& rd = ds; // значение: 4.0 (0x40100000)

    

    // Задание 22

    int (*sumFun)(int,int) = &summ_fun; //создание указателя на функцию. Значение: 0x002d13bb
    int res = sumFun(5, 4); // обращение к функции через указатель. Значение: 9

    //По адресу находяться:
    //int summ_fun(int a, int b) {
    //002D1820  push        ebp
    //002D1821  mov         ebp, esp
    //002D1823  sub         esp, 0C0h
    //002D1829  push        ebx
    //002D182A  push        esi
    //002D182B  push        edi
    //002D182C  mov         edi, ebp
    //002D182E xor ecx, ecx
    //002D1830  mov         eax, 0CCCCCCCCh
    //002D1835  rep stos    dword ptr es : [edi]
    //002D1837  mov         ecx, offset _D8E4DA54_SE_Lab02@cpp(02DC077h)
    //002D183C  call        @__CheckForDebuggerJustMyCode@4 (02D1320h)
    //002D1841  nop
    //return a + b;
    //002D1842  mov         eax, dword ptr[a]
    //002D1845  add         eax, dword ptr[b]
    //}


    return 0;
}


//Создание функции сложения 2-х полученных чисел (22 задание)
int summ_fun(int a, int b) { 
    return a + b;
}