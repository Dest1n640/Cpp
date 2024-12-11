#include <iostream>

using namespace std;

int main() {
    int N = 1000;

    cout << "Input numbers: (In the end input a letter) ";
    int* line = new int[N];

    int* ptr = line;
    while (cin >> *ptr) {
        ptr++;
    }

    int* left = line;
    int* right = line + N - 1;
    int result = -1;

    while (left <= right) {
        int* mid = left + (right - left) / 2;

        if (*mid == 0) {
            right = mid - 1; 
        } else {
            left = mid + 1; 
        }
    }
    result = left - line;

    cout << "Index of first zero: " << result + 1 << endl;

    delete[] line;
    return 0;
}