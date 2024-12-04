#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double calculateFunction(double x) {
    return pow(x, 4);  // Пример функции x^4
}

int main() {
    // Диапазон проверки и точность сравнения
    double a = -5.0;   // Начало диапазона
    double a1 = 5.0;      // Конец диапазона
    double step = 0.1;           // Шаг
    double f = 1.0E-9;    // Точность сравнения
    
    bool is_symmetric_even = true;  // Флаг для проверки четности
    bool is_symmetric_odd = true;   // Флаг для проверки нечетности

    // Проверка на четность
    for (double x = a; x <= a; x += step) {
        if (fabs(calculateFunction(x) - calculateFunction(-x)) > f) { 
            is_symmetric_even = false;
            break;
        }
    }

    if (is_symmetric_even) {
        cout << "Функция является четной!" << endl;
    } else {
        // Проверка на нечетность, если функция не является четной
        for (double x = a; x <= a1; x += step) {
            if (fabs(calculateFunction(x) + calculateFunction(-x)) > f) { 
                is_symmetric_odd = false;
                break;
            }
        }

        if (is_symmetric_odd) {
            cout << "Функция является нечетной!" << endl;
        } else {
            cout << "Функция не является ни четной, ни нечетной!" << endl;
        }
    }

    return 0;
}
