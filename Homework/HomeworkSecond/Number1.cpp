#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double f1(double x) { return x * x; }
double f2(double x) { return x * x * x; }
double f3(double x) { return sin(x); }
double f4(double x) { return cos(x); }

void checkEvenOdd(double (*func)(double), double start, double end, double step, double epsilon) {
    setlocale(LC_ALL, "ru");
    bool isEven = true, isOdd = true;
    for (double x = start; x <= end; x += step) {
        double fx = func(x);
        double f_neg_x = func(-x);
        if (fabs(fx - f_neg_x) > epsilon) isEven = false;
        if (fabs(fx + f_neg_x) > epsilon) isOdd = false;
    }
    if (isEven) cout << "Функция является четной." << endl;
    else if (isOdd) cout << "Функция является нечетной." << endl;
    else cout << "Функция ни четная, ни нечетная." << endl;
}

int main() {
    double start = -5.0, end = 5.0, step = 0.1, epsilon = 1e-6;
    cout << fixed << setprecision(6);
    cout << "Проверка f(x) = x^2:" << endl;
    checkEvenOdd(f1, start, end, step, epsilon);
    cout << "Проверка f(x) = x^3:" << endl;
    checkEvenOdd(f2, start, end, step, epsilon);
    cout << "Проверка f(x) = sin(x):" << endl;
    checkEvenOdd(f3, start, end, step, epsilon);
    cout << "Проверка f(x) = cos(x):" << endl;
    checkEvenOdd(f4, start, end, step, epsilon);
    return 0;
}
