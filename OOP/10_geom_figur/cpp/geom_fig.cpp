#include "../h/geom_fig.h"
#include <cmath>
#include <csignal>
#include <iostream>
#include <memory>

Points::Points(int x, int y) : x(x), y(y) {}

Circle::Circle(int radius) : radius(radius) {}

double Circle::calc_area() { return M_PI * (radius * radius); }

double Circle::calc_perimeter() { return 2 * M_PI * radius; }

void name() { std::cout << "Circle" << std::endl; }

Elips::Elips(Points center, int a, int b)
    : center(center), radius_a(a), radius_b(b) {}

double Elips::calc_area() { return M_PI * radius_a * radius_b; }

double Elips::calc_perimeter() {
  double h = ((radius_a - radius_b) * (radius_a - radius_b)) /
             ((radius_a + radius_b) * (radius_a + radius_b));
  return M_PI * (radius_a + radius_b) * (1 + (3 * h) / (10 + sqrt(4 - 3 * h)));
}
void Elips::name() { std::cout << "Elips" << std::endl; }

Triangle::Triangle(Points a, Points b, Points c) : a(a), b(b), c(c) {}

double Triangle::calc_area() {
  double p = ((a + b + c) / 2);
  return
}
