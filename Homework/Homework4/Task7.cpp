#include <iostream>

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
    for (int i = 0; i < n + 1; i++) {
        new_str[i] = '\0';
    }

    char* current_new = new_str;
    char* current_str = str;

    while (*current_str != '\0') {
        bool is_duplicate = false;
        char* checker = new_str;

        while (checker < current_new) {
            if (*current_str == *checker) {
                is_duplicate = true;
                break;
            }
            checker++;
        }

        if (!is_duplicate) {
            *current_new = *current_str;
            current_new++;
        }

        current_str++;
    }

    cout << "String with unique characters: " << new_str << endl;

    delete[] str;
    delete[] new_str;

    return 0;
}
