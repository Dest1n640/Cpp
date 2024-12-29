#include <iostream>

using namespace std;

int fillFlood(int **canvas, int x, int y, int rows, int cols);

int main() {
  int row, colums;
  cout << "Input the number of rows: ";
  cin >> row;
  cout << "Input the number of columns: ";
  cin >> colums;

  int **mass = new int *[row];
  for (int i = 0; i < row; ++i) {
    mass[i] = new int[colums];
  }

  cout << "Input the table for the algorithm:\n";
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < colums; ++j) {
      cout << "Elements [" << i << "][" << j << "]: ";
      cin >> mass[i][j];
    }
  }

  cout << "The mass:\n";
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < colums; ++j) {
      cout << mass[i][j] << " ";
    }
    cout << "\n";
  }

  int startX = 0, startY = 0;
  int maxSize = fillFlood(mass, startX, startY, row, colums);
  cout << "The maximum size of the flood fill = " << maxSize << endl;

  for (int i = 0; i < row; ++i) {
    delete[] mass[i];
  }
  delete[] mass;

  return 0;
}

int fillFlood(int **canvas, int x, int y, int rows, int cols) {
  if (x < 0 || x >= rows || y < 0 || y >= cols || canvas[x][y] != 1)
    return 0;

  canvas[x][y] = 0;

  int size = 1;
  size += fillFlood(canvas, x + 1, y, rows, cols);
  size += fillFlood(canvas, x - 1, y, rows, cols);
  size += fillFlood(canvas, x, y + 1, rows, cols);
  size += fillFlood(canvas, x, y - 1, rows, cols);

  return size;
}
