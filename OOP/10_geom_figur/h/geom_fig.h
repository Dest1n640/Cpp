#ifndef GEOM_FIG_H
#define GEOM_FIG_H

#include <csignal>
struct Points {
  int x, y;
  Points(int x = 0, int y = 0);
};

class Figure {
public:
  virtual double calc_area() = 0;
  virtual double calc_perimeter() = 0;
  virtual void name() = 0;
  // virtual ~Figure(){};
};

class Circle : public Figure {
  Points center;
  int radius;

public:
  Circle(int radius);
  double calc_area();
  double calc_perimeter();
  void name();
};

class Elips : public Figure {
  Points center; // Центр
  int radius_a;  // Большая полуось
  int radius_b;  // Маленькая полуось

public:
  Elips(Points center, int a, int b);
  double calc_area();
  double calc_perimeter();
  void name();
};

class Triangle : public Figure {
  Points a, b, c;

public:
  Triangle(Points a, Points b, Points c);
  double calc_area();
  double calc_perimeter();
  void name();
};

#endif
