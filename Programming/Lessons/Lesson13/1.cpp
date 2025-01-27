#include <iostream>

using namespace std;

int func1(int, float &);

int main() {
  int a = 10;
  float b = 5.5;
  int d = func1(a, b);

  cout << "d = " << d << endl;
  return 0;
}

int func1(int a, float &b) {
  int c;
  c = a + (int)(b + 0.5);

  return c;
}
