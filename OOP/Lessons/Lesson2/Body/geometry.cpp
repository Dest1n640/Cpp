#include "../Head/geometry.h"
#include <cmath>
#include <iostream>

// Расстояние между двумя точками
double calcDistance(const Point &p1, const Point &p2) {
  return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

// Вспомогательная функция: площадь треугольника по формуле Герона
double calcAreaBySides(double a, double b, double c) {
  double p = (a + b + c) / 2.0;
  if (p <= a || p <= b || p <= c) {
    return 0.0;
  }
  return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

// Площадь треугольника по координатам точек
double calcAreaByPoints(const Point &p1, const Point &p2, const Point &p3) {
  double a = calcDistance(p1, p2);
  double b = calcDistance(p2, p3);
  double c = calcDistance(p3, p1);
  return calcAreaBySides(a, b, c);
}

// Вычисление площади треугольника и сохранение результата в поле area
double calcTriangleArea(Triangle &tr) {
  tr.area = calcAreaByPoints(tr.vertexes[0], tr.vertexes[1], tr.vertexes[2]);
  return tr.area;
}

// Очистка точки (установка координат в 0)
void clearPoint(Point &p) { p.x = p.y = 0.0; }

// Очистка треугольника (установка площади в 0)
void clearTriangle(Triangle &tr) { tr.area = 0.0; }

// Перегрузка оператора ввода для Point
std::istream &operator>>(std::istream &in, Point &p) {
  in >> p.x >> p.y;
  return in;
}

// Перегрузка оператора вывода для Point
std::ostream &operator<<(std::ostream &out, const Point &p) {
  out << "(" << p.x << " " << p.y << ")";
  return out;
}

// Перегрузка оператора вывода для Triangle
std::ostream &operator<<(std::ostream &out, const Triangle &tr) {
  out << "A=" << tr.vertexes[0] << " B=" << tr.vertexes[1]
      << " C=" << tr.vertexes[2] << " area=" << tr.area;
  return out;
}
