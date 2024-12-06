#include <iostream>
#include <cmath>

using namespace std;

void checkSecondLimit(double epsilon) {
    setlocale(LC_ALL, "ru");
    int n = 1;
    while (true) {
        double value = pow(1 + 1.0 / n, n);
        if (fabs(value - M_E) < epsilon) {
            cout << "Выражение приблизилось к e при n = " << n << endl;
            break;
        }
        n++;
    }
}

int main() {
    double epsilon = 1e-6;
    checkSecondLimit(epsilon);
    return 0;
}
