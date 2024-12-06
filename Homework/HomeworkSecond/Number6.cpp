#include <iostream>
#include <cmath>

using namespace std;

double factorial(int n) {
    return (n == 0) ? 1 : n * factorial(n - 1);
}

double binomialDirect(int m, double x) {
    return pow(1 + x, m);
}

double binomialSeries(int m, double x) {
    setlocale(LC_ALL, "ru");
    double sum = 0;
    for (int k = 0; k <= m; ++k) {
        double term = factorial(m) / (factorial(k) * factorial(m - k)) * pow(x, k);
        sum += term;
    }
    return sum;
}

int main() {
    int m = 5;
    double x = 0.5;

    double direct = binomialDirect(m, x);
    double series = binomialSeries(m, x);

    cout << "Результат через прямой расчет: " << direct << endl;
    cout << "Результат через разложение в ряд: " << series << endl;

    return 0;
}
