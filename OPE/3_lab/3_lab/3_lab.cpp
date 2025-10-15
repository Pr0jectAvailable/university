#include <iostream>

//Windows-1251
//Theodore Griffin Vaselievich = 54 68 65 6F 64 6F 72 65 20 47 72 69 66 66 69 6E 20 56 61 73 65 6C 69 65 76 69 63 68
//ТеодорГрифинВасильевич = D2 E5 EE E4 EE F0 C3 F0 E8 F4 E8 ED C2 E0 F1 E8 EB FC E5 E2 E8 F7
//Griffin2006Теодор = 47 72 69 66 66 69 6E 32 30 30 36 D2 E5 EE E4 EE F0

//UTF-8
//Theodore Griffin Vaselievich = 54 68 65 6F 64 6F 72 65 20 47 72 69 66 66 69 6E 20 56 61 73 65 6C 69 65 76 69 63 68
//ТеодорГрифинВасильевич = D0 A2 D0 B5 D0 BE D0 B4 D0 BE D1 80 D0 93 D1 80 D0 B8 D1 84 D0 B8 D0 BD D0 92 D0 B0 D1 81 D0 B8 D0 BB D1 8C D0 B5 D0 B2 D0 B8 D1 87
//Griffin2006Теодор = 47 72 69 66 66 69 6E 32 30 30 36 D0 A2 D0 B5 D0 BE D0 B4 D0 BE D1 80

//UTF-16
// Theodore Griffin Vaselievich = 54 00 68 00 65 00 6F 00 64 00 6F 00 72 00 65 00 20 00 47 00 72 00 69 00 66 00 66 00 69 00 6E 00 20 00 56 00 61 00 73 00 65 00 6C 00 69 00 65 00 76 00 69 00 63 00 68 00
// ТеодорГрифинВасильевич = 22 04 35 04 3E 04 34 04 3E 04 40 04 13 04 40 04 38 04 44 04 38 04 3D 04 12 04 30 04 41 04 38 04 3B 04 4C 04 35 04 32 04 38 04 47 04
// Griffin2006Теодор = 47 00 72 00 69 00 66 00 66 00 69 00 6E 00 32 00 30 00 30 00 36 00 22 04 35 04 3E 04 34 04 3E 04 40 04

int main()
{

    int number = 0x12345678;
    char hello[] = "Hello, ";
    char lfie[] = "Theodore Griffin Vaselievich";
    char rfie[] = "ТеодорГрифинВасильевич";
    char lrf[] = "Griffin2006Теодор";

    wchar_t Lfie[] = L"Theodore Griffin Vaselievich";
    wchar_t Rfie[] = L"ТеодорГрифинВасильевич";
    wchar_t LRf[] = L"Griffin2006Теодор";

    std::cout << hello << number << std::endl;
    return 0;
}
