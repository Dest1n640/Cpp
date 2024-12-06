#include <iostream>
#include <cmath>

using namespace std;

void checkLimit(double epsilon) {
    setlocale(LC_ALL, "ru");
    double x = 1.0;
    while (true) {
        double left = sin(x) / x;
        if (fabs(left - 1) < epsilon) {
            cout << "Левая часть равенства приблизилась к 1 при x = " << x << endl;
            break;
        }
        x /= 2;
    }
}

int main() {
    double epsilon = 1e-6;
    checkLimit(epsilon);
    return 0;
}
