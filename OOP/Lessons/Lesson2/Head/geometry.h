#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <iostream>

// Структура для представления точки
struct Point {
  double x, y;
};

// Структура для представления треугольника
struct Triangle {
  Point vertexes[3];
  double area;
};

// Прототипы функций
double calcDistance(const Point &p1, const Point &p2);
double calcAreaByPoints(const Point &p1, const Point &p2, const Point &p3);
double calcTriangleArea(Triangle &tr);
void clearPoint(Point &p);
void clearTriangle(Triangle &tr);

// Перегрузка операторов ввода и вывода для Point
std::istream &operator>>(std::istream &in, Point &p);
std::ostream &operator<<(std::ostream &out, const Point &p);

// Перегрузка операторов ввода и вывода для Triangle
std::ostream &operator<<(std::ostream &out, const Triangle &tr);

#endif
