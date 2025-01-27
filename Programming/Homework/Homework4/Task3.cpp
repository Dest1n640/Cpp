#include <iostream>
using namespace std;

int main() {
    const int N = 80;
    char str[N + 1] = {'\0'}; 
    int numbers[10] = {0}; 

    cout << "Enter the string: ";
    cin.getline(str, N); 

    cout << "Old string: " << str << endl;

    bool anyNumber = false;

    char* ptr = str;
    while (*ptr != '\0') {
        if (*ptr >= '0' && *ptr <= '9') {
            anyNumber = true;
            break; 
        }
        ptr++;
    }

    if (!anyNumber) {
        cout << "No number in string" << endl;
        return -1;
    }

    ptr = str;
    while (*ptr != '\0') {
        if (*ptr >= '0' && *ptr <= '9') {
            numbers[*ptr - '0']++;  
        }
        ptr++;
    }

    int max = 0; 
    int max_digit = -1; 

    for (int i = 0; i < 10; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
            max_digit = i;
        }
    }

    if (max_digit != -1) {
        cout << "The most frequent digit is: " << max_digit << endl;
        cout << "It appears " << max << " times." << endl;
    }
    
    return 0;
}
