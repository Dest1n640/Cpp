#include <iostream>

using namespace std;

int summ(int);

int main() {
  int n;
  cout << "Input the number: ";
  cin >> n;

  cout << summ(n) << endl;
  return 0;
}

int summ(int a) {
  if (a == 0) {
    return 0;
  } else {
    return a % 10 + summ(a / 10);
  }
}
