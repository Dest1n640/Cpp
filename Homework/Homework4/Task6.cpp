#include <iostream>

using namespace std;

int main() {
    int N = 1000;

    cout << "Inpute numbers:(In the end input the letter) ";
    int* line = new int[N];

    for (int i = 0; i < N; i++){
        cin >> line[i];
    }
    int left = 0, right = 999;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (line[mid] == 0) {
            right = mid - 1; 
        } else {
            left = mid + 1; 
        }
    }
    result = left;

    cout << "Index of first zero: " << result + 1 << endl;
    
    return 0;
}