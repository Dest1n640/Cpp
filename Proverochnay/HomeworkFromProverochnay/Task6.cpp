#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Input the length of the string: ";
  cin >> n;
  cin.ignore();

  cout << "Input the string with zeros: ";
  char *rts = new char[n + 1];
  cin.getline(rts, n + 1);

  int index = 0;
  int count_of_zeros = 0;

  for (int i = 0; i < n; i++) {
    if (rts[i] != '0') {
      rts[index++] = rts[i];
    } else {
      count_of_zeros++;
    }
  }

  while (index < n) {
    rts[index++] = '0';
  }

  cout << "Modified string: ";
  for (int i = 0; i < n; i++) {
    cout << rts[i];
  }
  cout << endl;

  delete[] rts;
  return 0;
}
