#include <iostream>

using namespace std;

double fastPower(double x, int n);

int main() {
  double x;
  int n;
  cout << "Input the number(can be double): ";
  cin >> x;
  cout << "Input the power: ";
  cin >> n;

  cout << fastPower(x, n) << endl;
  return 0;
}

double fastPower(double x, int n) {
  if (n == 0) {
    return 1;
  } else if (n % 2 != 0) {
    return x * fastPower(x, n - 1);
  } else {
    double halfPower = fastPower(x, n / 2);
    return halfPower * halfPower;
  }
}
