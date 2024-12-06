#include <iostream>
#include <cmath>

using namespace std;

void findPointsInsideEllipse(int a, int b) {
    setlocale(LC_ALL, "ru");
    for (int x = -a; x <= a; ++x) {
        for (int y = -b; y <= b; ++y) {
            if ((x * x) / (double)(a * a) + (y * y) / (double)(b * b) <= 1) {
                cout << "(" << x << ", " << y << ")" << endl;
            }
        }
    }
}

int main() {
    int a = 5, b = 3;
    findPointsInsideEllipse(a, b);
    return 0;
}
