#include <iostream>

using namespace std;

int main() {
    const int N = 80;
    cout << "Input the string: ";

    char* str = new char[N];
    cin.getline(str, N);

    char* ptr = str;

    while (*ptr != '\0') {
        if (*ptr == '{') {
            ptr++;
            while (*ptr != '\0') {
                if (*ptr == '[' || *ptr == ']' || *ptr == '(' || *ptr == '{' || *ptr == '}') {
                    cout << "Error: Invalid symbol after '{'. Exiting." << endl;
                    delete[] str;
                    return -1;
                }
                ptr++;
            }
        } else if (*ptr == '(') {
            ptr++;
            while (*ptr != '\0') {
                if (*ptr == '[' || *ptr == ']' || *ptr == '(' || *ptr == '{' || *ptr == '}') {
                    cout << "Error: Invalid symbol after '('. Exiting." << endl;
                    delete[] str;
                    return -2;
                }
                ptr++;
            }
        } else if (*ptr == '[') {
            ptr++;
            while (*ptr != '\0') {
                if (*ptr == '[' || *ptr == '(' || *ptr == ')' || *ptr == '{' || *ptr == '}') {
                    cout << "Error: Invalid symbol after '['. Exiting." << endl;
                    delete[] str;
                    return -3;
                }
                ptr++;
            }
        }
        ptr++;
    }

    cout << "String is valid." << endl;
    delete[] str;
    return 0;
}
