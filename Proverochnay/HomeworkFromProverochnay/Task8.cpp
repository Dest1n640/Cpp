#include <iostream>

using namespace std;

void input_arr(int n, int arr[]);

int main() {
  int n;
  cout << "Input the size of arr: ";
  cin >> n;

  if (n <= 0) {
    cout << "Invalid size of array!" << endl;
    return 1;
  }

  int *X = new int[n];
  int *Y = new int[n];

  cout << "Input the first array (X):" << endl;
  input_arr(n, X);

  cout << "Input the second array (Y):" << endl;
  input_arr(n, Y);

  int amount = 0;
  for (int i = 0; i < n; i++) {
    if (X[i] == Y[i]) {
      amount++;
    }
  }

  if (amount == 0) {
    cout << "NO" << endl;
  } else {
    cout << "YES (" << amount << " matching elements)" << endl;
  }

  delete[] X;
  delete[] Y;

  return 0;
}

void input_arr(int n, int arr[]) {
  for (int i = 0; i < n; i++) {
    cout << "arr[" << i << ']' << " = ";
    cin >> arr[i];
  }
}
