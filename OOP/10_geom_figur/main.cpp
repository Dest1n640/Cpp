#include "./h/geom_fig.h"
#include <iostream>
#include <vector>

// Реализация чисто виртуального деструктора Figure
Figure::~Figure() = default;

int main() {
  try {
    // Тестирование круга
    Circle circle({0, 0}, 5);
    circle.name();
    std::cout << "Area: " << circle.calc_area() << std::endl; // ~78.5398
    std::cout << "Perimeter: " << circle.calc_perimeter()
              << std::endl; // ~31.4159

    // Тестирование эллипса
    Elips elips({0, 0}, 8, 4);
    elips.name();
    std::cout << "Area: " << elips.calc_area() << std::endl; // ~100.531
    std::cout << "Perimeter: " << elips.calc_perimeter()
              << std::endl; // ~39.498

    // Тестирование треугольника
    Triangle triangle({0, 0}, {3, 0}, {0, 4});
    triangle.name();
    std::cout << "Area: " << triangle.calc_area() << std::endl;           // 6
    std::cout << "Perimeter: " << triangle.calc_perimeter() << std::endl; // 12

    // Тестирование прямоугольника
    Rectangle rect({1, 4}, {5, 1});
    rect.name();
    std::cout << "Area: " << rect.calc_area()
              << std::endl; // 12 (ошибка в имени метода!)
    std::cout << "Perimeter: " << rect.calc_perimeter() << std::endl; // 14

    // Тестирование многоугольника
    std::vector<Points> poly_points = {{0, 0}, {3, 0}, {3, 4}, {0, 4}};
    Polygon polygon(poly_points);
    polygon.name();
    std::cout << "Area: " << polygon.calc_area() << std::endl;           // 12
    std::cout << "Perimeter: " << polygon.calc_perimeter() << std::endl; // 14

    // Проверка исключения для многоугольника
    std::vector<Points> invalid_points = {{0, 0}, {1, 1}};
    Polygon invalid_poly(invalid_points); // Выбросит исключение

  } catch (const PolygonException &) {
    std::cout << "\n[OK] Polygon exception caught!" << std::endl;
  }

  return 0;
}
