#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// CRC-32Q: x^32 + x^31 + x^24 + x^22 + x^16 + x^14 + x^8 + x^7 + x^5 + x^3 + x + 1
const unsigned int POLYNOMIAL = 0x814141AB;
const int W = 32;

unsigned int calculateCRC(const vector<bool>& data) {
    vector<bool> ext = data;
    ext.insert(ext.end(), W, false);

    unsigned int reg = 0;
    for (bool bit : ext) {
        int high = (reg >> (W - 1)) & 1;
        reg = (reg << 1) | (bit ? 1 : 0);
        if (high) reg ^= POLYNOMIAL;
        reg &= 0xFFFFFFFF;
    }
    return reg;
}

vector<bool> generateData(int length) {
    vector<bool> data(length);
    for (int i = 0; i < length; ++i)
        data[i] = rand() % 2;
    return data;
}

int main() {
    setlocale(LC_ALL, "rus");
    srand(static_cast<unsigned>(time(nullptr)));

    vector<bool> data = generateData(1000);

    unsigned int crc = calculateCRC(data);
    cout << "CRC-32Q: 0x" << hex << crc << dec << endl;

    vector<bool> dataWithCRC = data;
    for (int i = W - 1; i >= 0; --i)
        dataWithCRC.push_back((crc >> i) & 1);

    unsigned int check = calculateCRC(dataWithCRC);
    cout << "Проверка: 0x" << hex << check << dec << endl;
    cout << (check == 0 ? "Ошибок нет" : "Ошибка") << endl;

    return 0;
}