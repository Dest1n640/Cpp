#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream out("prime.txt"); // Файл для вывода
    if (!out) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    const int PRIME_NUM = 1 << 18; // Всего нужно найти    // 100000 - максимальное число, так как массив int   /2<<19 stack overflow
    int primeFound = 0; // Уже найдено
    int primeArray[PRIME_NUM]; // Массив простых чисел
    int current = 2; // Текущее проверяемое число
    int limit = 1; // Последний проверяемый делитель
    bool isPrime; // Признак простоты

    while (primeFound < PRIME_NUM) { // Пока не нашли все числа

        if ((limit + 1) * (limit + 1) <= current) {
            limit++;
        }

        for (int i = 0; i < primeFound && primeArray[i] <= limit; i++) {
            if (current % primeArray[i] == 0) { // Если разделилось, то не простое
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            out << current << endl; // Вывод в файл
            primeArray[primeFound++] = current; // Сохранить, увелич. индекс
        }

        current++; // Переход к следующему числу
        isPrime = true;
    }

    out.close(); // Закрыть файл
    return 0;
}
