#include <iostream>

using namespace std;

bool inputArray(int arr[10][10]) {
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      cout << "Enter value for [" << i << "][" << j << "] (0 or 1): ";
      cin >> arr[i][j];
      if (arr[i][j] != 0 && arr[i][j] != 1) {
        cout << "Error! You entered an invalid number." << endl;
        return false;
      }
    }
  }
  return true;
}

void dfs(int arr[10][10], bool visited[10][10], int x, int y) {
  int dx[] = {0, 0, 1, -1};
  int dy[] = {1, -1, 0, 0};
  visited[x][y] = true;
  for (int i = 0; i < 4; ++i) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && nx < 10 && ny >= 0 && ny < 10 && arr[nx][ny] == 1 &&
        !visited[nx][ny]) {
      dfs(arr, visited, nx, ny);
    }
  }
}

int countPolygons(int arr[10][10]) {
  bool visited[10][10] = {false};
  int count = 0;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (arr[i][j] == 1 && !visited[i][j]) {
        ++count;
        dfs(arr, visited, i, j);
      }
    }
  }
  return count;
}

int main() {
  int arr[10][10];
  cout << "Enter the elements of the array (0 or 1):" << endl;
  if (!inputArray(arr)) {
    cout << "Program terminated due to invalid input." << endl;
    return -1;
  }
  int amount = countPolygons(arr);
  cout << "The number of polygons: " << amount << endl;
  return 0;
}
