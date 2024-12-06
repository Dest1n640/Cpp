
#include <iostream>
#include <cmath>
#include <iomanip>


const double EPSILON = 1e-6; 
bool areEqual(double a, double b) {
    
    return std::fabs(a - b) < EPSILON;
}

void checkPeriodicity(double (*func)(double), double T, double step) {
    setlocale(LC_ALL, "ru");
    std::cout << "Проверка периодичности на интервале [0; 5T] с шагом " << step << ":\n";
    bool isPeriodic = true;

    for (double x = 0; x <= 5 * T; x += step) {
        double f_x = func(x);       
        double f_xT = func(x + T);      

        std::cout << std::fixed << std::setprecision(6) 
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

double sinSquared(double x) {
    return std::sin(x) * std::sin(x);
}

double tanhFunc(double x) {
    return std::tanh(x);
}

double halfSin(double x) {
    return 0.5 * std::sin(x);
}

int main() {
    double T1 = M_PI;    
    double T2 = 2 * M_PI;  

    double step = 0.1;    

    std::cout << "\nПроверка sin^2(x) с T = П:\n";
    checkPeriodicity(sinSquared, T1, step);
    std::cout << "\nПроверка th(x) (гиперболический тангенс), T = 2П:\n";
    checkPeriodicity(tanhFunc, T2, step);
 
    std::cout << "\nПроверка (1/2) * sin(x) с T = П:\n";
    checkPeriodicity(halfSin, T1, step);

    return 0;
}