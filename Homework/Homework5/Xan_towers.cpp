#include <iostream>

using namespace std;

long hanoi_tower(int);
double fastPower(double, int);

int main() {
  int rings;
  cout << "Input the number of rings: ";
  cin >> rings;
  cout << "Number of steps: " << hanoi_tower(rings) << endl;
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

long hanoi_tower(int rings) {
  if (rings == 0)
    return 0;
  else {
    return fastPower(2, rings) - 1;
  }
}
