#include <iostream>
using namespace std;

int main() {
    int N = 80;
    char* str = new char[N+1];
    cout << " Write the text - ";
    cin.getline(str, N);
    cout << str << endl;

    int j = 0;
    bool inSpace = false; 
    for (int i = 0; i < N + 1 && str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
            inSpace = false;
        } 
        else if (!inSpace) {
            str[j++] = ' ';
            inSpace = true;
        }
    }
    str[j] = '\0';

    cout << str << endl;

    delete[] str;
    return 0;
}
