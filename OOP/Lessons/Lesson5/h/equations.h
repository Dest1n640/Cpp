#ifndef EQUATIONS_H
#define EQUATIONS_H

#include "rational.h"

struct QuadraticRoots {
  double x1;
  double x2;
  bool hasRealRoots;
};
Rational linear_eq(Rational k, Rational b);
QuadraticRoots quadr_eq(Rational a, Rational b, Rational c);

#endif // !
