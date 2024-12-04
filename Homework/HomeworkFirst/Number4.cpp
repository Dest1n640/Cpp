#include <iostream>
#include <cmath>


int main() {
    setlocale (LC_ALL, "RU");
    double a, b, c;
    std::cout << "Введите коэффициенты a, b и c: ";
    std::cin >> a >> b >> c;

    double x = -b / (2 * a);

    double y = a * x * x + b * x + c;
    std::cout << "Координаты вершины параболы: (" << x << ", " << y << ")" << std::endl;

    return 0;
}
