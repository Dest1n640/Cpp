#include <iostream>

using namespace std;

int factorial(int);

int main() {
  int n;
  cout << "Input the number: ";
  cin >> n;

  cout << factorial(n) << endl;

  return 0;
}

int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}
