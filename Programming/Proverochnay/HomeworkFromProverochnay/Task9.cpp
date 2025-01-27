#include <iostream>

using namespace std;

int main() {
  int m;
  cout << "Input the size of massive: ";
  cin >> m;

  int *arr = new int[m];
  cout << "Input the massive: " << endl;
  for (int i = 0; i < m; i++) {
    cout << "arr[" << i << ']';
    cin >> arr[i];
  }
  int amount = 0;
  for (int i = 0; i < m; i++) {
    if (arr[i - 1] < arr[i] && arr[i + 1] < arr[i] ||
        arr[i - 1] > arr[i] && arr[i + 1] > arr[i]) {
      ++amount;
    }
  }

  cout << "The amount of elements: " << amount << endl;
  delete[] arr;
  return 0;
}
