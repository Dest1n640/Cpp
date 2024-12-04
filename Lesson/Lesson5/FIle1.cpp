#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double inputNumber, fractionalPart;
    int integerPart;

    cout << "Введите число: ";
    cin >> inputNumber;

    integerPart = static_cast<int>(inputNumber);
    fractionalPart = inputNumber - integerPart;
    int binaryMask = 0x40000000;

    while (binaryMask > integerPart) binaryMask >>= 1;


    while (binaryMask > 0) {
        if (integerPart >= binaryMask) {
            cout << "1";
            integerPart -= binaryMask;
        } else {
            cout << "0";
        }
        binaryMask >>= 1;
    }
    cout << endl;

    for (int i = 0; i < 24; i++) {
        fractionalPart *= 2;
        cout << static_cast<int>(fractionalPart);
        fractionalPart -= static_cast<int>(fractionalPart);
        if (fractionalPart <= 1e-8)
            break;
    }
    cout << endl;

    return 0;
}
