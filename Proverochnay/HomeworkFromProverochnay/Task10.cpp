#include <iostream>

using namespace std;
int main() {
  int m, n;

  cout << "Input the number of colums: ";
  cin >> m;
  cout << "Input the number of rows: ";
  cin >> n;

  int **arr = new int *[m];
  for (int i = 0; i < m; i++) {
    arr[i] = new int[n];
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << "Arr[" << i << ']' << '[' << j << "] = ";
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 || j == 0) {
      }
    }
  }
}
