#include <iostream>
#include <iomanip>

using namespace std;

int main(void) {
    const int MAX_LENGTH = 80;
    char inputStr[MAX_LENGTH + 1] = {'0'};
    char resultStr[MAX_LENGTH + 1];
    char *inputPtr = inputStr;
    char *resultPtr = resultStr;
    int inputLength = 0;

    cout << "Enter the string and press enter" << endl;
    cin.getline(inputStr, MAX_LENGTH);

    cout << "Old string: " << endl;
    cout << inputStr << endl;

    for (int i = 0; i < MAX_LENGTH; i++) {
        if (*inputPtr != 0) {
            inputLength++;
        }
        if ((i == 0 || i == MAX_LENGTH - 1) && *inputPtr == ' ') {
            while (*inputPtr == ' ') {
                inputPtr++;
                continue;
            }
        }
        else if (*inputPtr == ' ' && *(inputPtr + 1) == ' ') {
            inputPtr++;
            continue;
        }
        else {
            *resultPtr = *inputPtr;
            inputPtr++;
            resultPtr++;
        }
    }
    resultPtr = resultStr;
    char *shiftPtr = resultPtr + MAX_LENGTH - inputLength;
    cout << "Shift index = " << MAX_LENGTH - inputLength << endl;

    for (int i = 0; i < MAX_LENGTH; i++) {
        if (*resultPtr == '0') {
            break;
        }
        *shiftPtr = *resultPtr;
        *resultPtr = 0;
        resultPtr++;
        shiftPtr++;
    }

    resultStr[MAX_LENGTH] = 0;

    cout << "New string: " << endl;
    cout << resultStr << endl;
    cout << "String length = " << inputLength << endl;

    return 0;
}
