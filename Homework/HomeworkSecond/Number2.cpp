
#include <iostream>
#include <cmath>
#include <iomanip>  // для настройки точности вывода

// Задаем допустимую погрешность для сравнения значений
const double EPSILON = 1e-6;  // точность сравнения

// Функция для проверки равенства с учетом погрешности
bool areEqual(double a, double b) {
    return std::fabs(a - b) < EPSILON;
}

// Функция для численной проверки периодичности
void checkPeriodicity(double (*func)(double), double T, double step) {
    std::cout << "Проверка периодичности на интервале [0; 5T] с шагом " << step << ":\n";
    bool isPeriodic = true;

    for (double x = 0; x <= 5 * T; x += step) {
        double f_x = func(x);           // Значение функции в точке x
        double f_xT = func(x + T);      // Значение функции в точке x + T

        std::cout << std::fixed << std::setprecision(6)  // Выводим с нужной точностью
                  << "f(" << x << ") = " << f_x
                  << ", f(" << x << " + " << T << ") = " << f_xT;

        if (!areEqual(f_x, f_xT)) {
            std::cout << "  -> Значения НЕ равны!";
            isPeriodic = false;
        }

        std::cout << std::endl;
    }

    if (isPeriodic) {
        std::cout << "Функция периодическая с периодом " << T << ".\n";
    } else {
        std::cout << "Функция НЕ является периодической с периодом " << T << ".\n";
    }
}

// Примерные функции

// sin^2(x)
double sinSquared(double x) {
    return std::sin(x) * std::sin(x);
}

// th(x) — гиперболический тангенс
double tanhFunc(double x) {
    return std::tanh(x);
}

// (1/2) * sin(x)
double halfSin(double x) {
    return 0.5 * std::sin(x);
}

int main() {
    double T1 = M_PI;        // Период для sin^2 и 1/2 * sin
    double T2 = 2 * M_PI;    // Период для tg

    double step = 0.1;       // Шаг для численного расчета

    // Проверяем функцию sin^2(x)
    std::cout << "\nПроверка sin^2(x) с T = П:\n";
    checkPeriodicity(sinSquared, T1, step);

    // Проверяем функцию tanh(x) (гиперболический тангенс)
    std::cout << "\nПроверка th(x) (гиперболический тангенс), T = 2П:\n";
    checkPeriodicity(tanhFunc, T2, step);

    // Проверяем функцию (1/2) * sin(x)
    std::cout << "\nПроверка (1/2) * sin(x) с T = П:\n";
    checkPeriodicity(halfSin, T1, step);

    return 0;
}