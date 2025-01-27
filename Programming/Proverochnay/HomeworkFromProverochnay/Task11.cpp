#include <iostream>

using namespace std;

int main() {
  int n;
  cout << "Input the amount of pares: ";
  cin >> n;

  int box = 0, ligaments = 0, pares = 0;

  // Рассчитываем количество коробок (по 144 пары в каждой)
  if (n >= 144) {
    box = n / 144;
    n = n % 144; // Остаток пар после учета коробок
  }

  // Рассчитываем количество связок (по 12 пар в каждой)
  if (n >= 12) {
    ligaments = n / 12;
    n = n % 12; // Остаток пар после учета связок
  }

  // Оставшиеся пары
  pares = n;

  // Выводим результаты
  cout << "box = " << box << ", ligaments = " << ligaments
       << ", pares = " << pares << endl;

  return 0;
}
