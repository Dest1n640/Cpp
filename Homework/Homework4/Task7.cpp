#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n;
    cout << "Input the size of the array: ";
    cin >> n;

    cin.ignore();

    cout << "Input the string: ";
    char* str = new char[n + 1];
    cin.getline(str, n + 1);

    char* new_str = new char[n + 1];
    memset(new_str, 0, n + 1);

    int new_len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        bool is_duplicate = false;

        for (int q = 0; q < new_len; q++) {
            if (str[i] == new_str[q]) {
                is_duplicate = true;
                break;
            }
        }

        if (!is_duplicate) {
            new_str[new_len] = str[i];
            new_len++;
        }
    }

    cout << "String with unique characters: " << new_str << endl;

    delete[] str;
    delete[] new_str;

    return 0;
}
