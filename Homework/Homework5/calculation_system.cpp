#include <iostream>
using namespace std;

void decimalToBinary(int n);

int main() {
  int number;
  cout << "Enter a natural number: ";
  cin >> number;

  // Проверяем, что введено натуральное число
  if (number <= 0) {
    cout << "The number must be natural!" << endl;
    return 1;
  }

  cout << number << " in binary system: ";
  decimalToBinary(number);
  cout << endl;

  return 0;
}

// Рекурсивная функция для перевода числа в двоичную систему
void decimalToBinary(int n) {
  if (n == 0) {
    // Базовый случай рекурсии: ничего не делаем
    return;
  }
  // орабатываем старшие разряды числа
  decimalToBinary(n / 2);
  // Выводим текущий младший разряд
  cout << (n % 2);
}
