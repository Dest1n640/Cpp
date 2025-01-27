#include <iostream>
using namespace std;

int main() {
  cout << "Input the size of array: ";
  int n;
  cin >> n;

  // Проверка на корректность размера массива
  if (n <= 0) {
    cout << "Invalid array size!";
    return 1;
  }

  int *arr = new int[n];
  cout << "Enter array elements:" << endl;
  for (int i = 0; i < n; i++) {
    cout << "Arr[" << i << "] = ";
    cin >> arr[i];
  }

  int maxLength = 1; // Минимальная длина отрезка (один элемент сам симметричен)

  // Поиск максимального симметричного отрезка
  for (int start = 0; start < n; start++) {
    for (int end = start; end < n; end++) {
      bool isSymmetric = true;
      int len = end - start + 1;

      // Проверяем, является ли текущий отрезок симметричным
      for (int i = 0; i < len / 2; i++) {
        if (arr[start + i] != arr[end - i]) {
          isSymmetric = false;
          break;
        }
      }

      // Обновляем максимальную длину
      if (isSymmetric) {
        maxLength = max(maxLength, len);
      }
    }
  }

  cout << "The maximum length of the symmetric segment is: " << maxLength
       << endl;

  delete[] arr; // Освобождение памяти
  return 0;
}
