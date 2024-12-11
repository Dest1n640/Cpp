#include <iostream>

using namespace std;

int main() {
    int N = 100;
    cout << "Input the line with str: "; 
    char* str = new char[N];
    cin.getline(str, N);

    int count = 0;
    int max_num = 0;

    for (int i = 0; str[i] != '\0'&& i <= N; i++) {
        if (str[i] == '0') {
            max_num++;
        } else {
            if (max_num > count) {
                count = max_num;
            }
            max_num = 0;
        }
    }

    if (max_num > count) {
        count = max_num;
    }

    cout << "Max length of str = " << count << endl;

    delete[] str;

    return 0;
}