#include "h/equations.h" // Include equations.h to use linear_eq and quadr_eq
#include "h/rational.h"
#include <cmath> // For std::isnan
#include <iostream>

using namespace std;

int main() {
  // --- Rational Class Tests (from your original main) ---
  cout << "--- Rational Class Tests ---" << endl;
  // ... (Your Rational class test code from the previous main.cpp - 그대로
  // 복사) ... Constructors
  cout << "--- Constructors ---" << endl;
  Rational r1; // Default constructor (0/1)
  cout << "r1: " << r1 << endl;
  Rational r2(5); // Constructor with int (5/1)
  cout << "r2: " << r2 << endl;
  Rational r3(
      12,
      8); // Constructor with numerator and denominator (12/8 simplifies to 3/2)
  cout << "r3: " << r3 << endl;
  Rational r4(
      6, -4); // Constructor with negative denominator (6/-4 simplifies to -3/2)
  cout << "r4: " << r4 << endl;

  // Arithmetic operators
  cout << "\n--- Arithmetic Operators ---" << endl;
  Rational a(1, 2);
  Rational b(1, 4);
  cout << "a: " << a << ", b: " << b << endl;

  cout << "a + b: " << a + b << endl;
  Rational sum = a;
  sum += b;
  cout << "a += b: " << sum << endl;

  cout << "a - b: " << a - b << endl;
  Rational diff = a;
  diff -= b;
  cout << "a -= b: " << diff << endl;

  cout << "a * b: " << a * b << endl;
  Rational prod = a;
  prod *= b;
  cout << "a *= b: " << prod << endl;

  cout << "a / b: " << a / b << endl;
  Rational quot = a;
  quot /= b;
  cout << "a /= b: " << quot << endl;

  // Increment/Decrement operators
  cout << "\n--- Increment/Decrement Operators ---" << endl;
  Rational inc_dec(2, 3);
  cout << "inc_dec: " << inc_dec << endl;

  cout << "++inc_dec (prefix): " << ++inc_dec << endl;
  cout << "inc_dec (after prefix ++): " << inc_dec << endl;

  cout << "inc_dec++ (postfix): " << inc_dec++ << endl;
  cout << "inc_dec (after postfix ++): " << inc_dec << endl;

  cout << "--inc_dec (prefix): " << --inc_dec << endl;
  cout << "inc_dec (after prefix --): " << --inc_dec << endl;

  cout << "inc_dec-- (postfix): " << inc_dec-- << endl;
  cout << "inc_dec (after postfix --): " << inc_dec << endl;

  // Comparison operators
  cout << "\n--- Comparison Operators ---" << endl;
  Rational comp1(1, 2);
  Rational comp2(1, 2);
  Rational comp3(3, 4);

  cout << "comp1: " << comp1 << ", comp2: " << comp2 << ", comp3: " << comp3
       << endl;

  cout << "comp1 >= comp2: " << (comp1 >= comp2) << endl;
  cout << "comp1 <= comp2: " << (comp1 <= comp2) << endl;
  cout << "comp1 > comp3: " << (comp1 > comp3) << endl;
  cout << "comp1 < comp3: " << (comp1 < comp3) << endl;
  cout << "comp1 == comp2: " << (comp1 == comp2) << endl;
  cout << "comp1 != comp3: " << (comp1 != comp3) << endl;

  // Input/Output operators
  cout << "\n--- Input/Output Operators ---" << endl;
  Rational input_rational;
  cout << "Enter a rational number (numerator denominator): ";
  cin >> input_rational;
  cout << "You entered: " << input_rational << endl;

  // Type conversion operators
  cout << "\n--- Type Conversion Operators ---" << endl;
  Rational convert_rational(7, 2);
  cout << "convert_rational: " << convert_rational << endl;
  cout << "int(convert_rational): " << int(convert_rational) << endl;
  cout << "double(convert_rational): " << double(convert_rational) << endl;

  // --- Equation Solving Tests ---
  cout << "\n--- Equation Solving Tests ---" << endl;

  // --- Linear Equation Test ---
  cout << "\n--- Linear Equation ---" << endl;
  Rational k_linear(2); // k = 2
  Rational b_linear(5); // b = 5
  cout << "Solving linear equation: " << k_linear << "x + " << b_linear
       << " = 0" << endl;
  Rational x_linear = linear_eq(k_linear, b_linear);
  cout << "Solution x = " << x_linear << endl;

  // --- Quadratic Equation Tests ---
  cout << "\n--- Quadratic Equations ---" << endl;

  // Test 1: Two distinct real roots
  cout << "\n--- Quadratic Equation 1: Two distinct real roots ---" << endl;
  Rational a_quad1(1);  // a = 1
  Rational b_quad1(-3); // b = -3
  Rational c_quad1(2);  // c = 2
  cout << "Solving quadratic equation: " << a_quad1 << "x^2 + " << b_quad1
       << "x + " << c_quad1 << " = 0" << endl;
  QuadraticRoots roots1 = quadr_eq(a_quad1, b_quad1, c_quad1);
  if (roots1.hasRealRoots) {
    cout << "Root 1: x1 = " << roots1.x1 << endl;
    cout << "Root 2: x2 = " << roots1.x2 << endl;
  } else {
    cout << "No real roots." << endl;
  }

  // Test 2: One real root (discriminant = 0)
  cout << "\n--- Quadratic Equation 2: One real root ---" << endl;
  Rational a_quad2(1); // a = 1
  Rational b_quad2(2); // b = 2
  Rational c_quad2(1); // c = 1
  cout << "Solving quadratic equation: " << a_quad2 << "x^2 + " << b_quad2
       << "x + " << c_quad2 << " = 0" << endl;
  QuadraticRoots roots2 = quadr_eq(a_quad2, b_quad2, c_quad2);
  if (roots2.hasRealRoots) {
    cout << "Root 1: x1 = " << roots2.x1 << endl;
    cout << "Root 2: x2 = " << roots2.x2
         << endl; // x1 and x2 should be the same
  } else {
    cout << "No real roots." << endl;
  }

  // Test 3: No real roots (discriminant < 0)
  cout << "\n--- Quadratic Equation 3: No real roots ---" << endl;
  Rational a_quad3(1); // a = 1
  Rational b_quad3(1); // b = 1
  Rational c_quad3(1); // c = 1
  cout << "Solving quadratic equation: " << a_quad3 << "x^2 + " << b_quad3
       << "x + " << c_quad3 << " = 0" << endl;
  QuadraticRoots roots3 = quadr_eq(a_quad3, b_quad3, c_quad3);
  if (roots3.hasRealRoots) {
    cout << "Root 1: x1 = " << roots3.x1 << endl;
    cout << "Root 2: x2 = " << roots3.x2 << endl;
  } else {
    cout << "No real roots." << endl;
  }

  return 0;
}
