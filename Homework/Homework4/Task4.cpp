#include <iostream>

using namespace std;

int main() {
    int N = 80;
    cout << "Input the string: ";
    
    char* str = new char[N];
    cin.getline(str, N);

    for (int i = 0; i < N && str[i] != '\0'; i++) {
        if (str[i] == '{') {
            while (i < N && str[i] != '\0') {
                i++;
                if (str[i] == '[' || str[i] == ']' || str[i] == '(' || str[i] == '{' || str[i] == '}') {
                    cout << "Error: Invalid symbol after '{'. Exiting." << endl;
                    delete[] str;
                    return -1;
                }
            }
        } else if (str[i] == '(') {
            while (i < N && str[i] != '\0') {
                i++;
                if (str[i] == '[' || str[i] == ']' || str[i] == '(' || str[i] == '{' || str[i] == '}') {
                    cout << "Error: Invalid symbol after '('. Exiting." << endl;
                    delete[] str;
                    return -2;
                }
            }
        } else if (str[i] == '[') {
            while (i < N && str[i] != '\0') {
                i++;
                if (str[i] == '[' || str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}') {
                    cout << "Error: Invalid symbol after '['. Exiting." << endl;
                    delete[] str;
                    return -3;
                }
            }
        }
    }

    cout << "String is valid." << endl;
    delete[] str;
    return 0;
}
