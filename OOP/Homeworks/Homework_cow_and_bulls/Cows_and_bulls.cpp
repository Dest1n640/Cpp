#include <iomanip>
#include <iostream>

using namespace std;

void calculateBullsAndCows(int *target, int *guess, int n, int &bulls,
                           int &cows);
bool isValid(int *number, int n);
void generateGuess(int *guess, int n, int **previousGuesses, int *bullsHistory,
                   int *cowsHistory, int numPreviousGuesses);
bool isConsistent(int *guess, int n, int *prevGuess, int prevBulls,
                  int prevCows);

int main() {
  int n = 4;

  // Запрашиваем у пользователя загаданное число
  int *target = new int[n];
  cout << "Enter the secret number (" << n
       << " digits, no repetition, e.g., 1 2 3 4):" << endl;
  for (int i = 0; i < n; i++) {
    cin >> target[i];
  }

  // Проверяем корректность ввода
  while (!isValid(target, n)) {
    cout << "Invalid number! Digits must not repeat. Try again:" << endl;
    for (int i = 0; i < n; i++) {
      cin >> target[i];
    }
  }

  // Выводим разделитель
  cout << string(40, '-') << endl;

  // Создаем массивы для хранения предыдущих предположений и их результатов
  int **previousGuesses = new int *[7]; // Максимум 7 попыток
  for (int i = 0; i < 7; i++) {
    previousGuesses[i] = new int[n];
  }
  int *bullsHistory = new int[7];
  int *cowsHistory = new int[7];

  // Создаем массив для хранения текущего предположения
  int *guess = new int[n];

  int attempts = 0;
  int bulls, cows;
  while (true) {
    attempts++;

    if (attempts == 1) {
      // Первое предположение (можно выбрать любое, например, 0 1 2 3)
      for (int i = 0; i < n; i++) {
        guess[i] = i;
      }
    } else {
      generateGuess(guess, n, previousGuesses, bullsHistory, cowsHistory,
                    attempts - 1);
    }

    // Выводим текущее предположение
    cout << setw(10) << "Attempt " << setw(3) << attempts << ": ";
    for (int i = 0; i < n; i++) {
      cout << guess[i] << " ";
    }
    cout << endl;

    // Подсчитываем быков и коров
    calculateBullsAndCows(target, guess, n, bulls, cows);

    // Выводим результат
    cout << setw(16) << "Bulls: " << setw(2) << bulls;
    cout << setw(8) << "Cows: " << setw(2) << cows << endl;

    // Выводим разделитель
    cout << string(40, '-') << endl;

    // Сохраняем текущую попытку и её результат
    for (int i = 0; i < n; i++) {
      previousGuesses[attempts - 1][i] = guess[i];
    }
    bullsHistory[attempts - 1] = bulls;
    cowsHistory[attempts - 1] = cows;

    // Проверяем, угадал ли компьютер число
    if (bulls == n) {
      cout << "Computer guessed the number in " << attempts << " attempts!"
           << endl;
      break;
    }

    // Ограничение на количество попыток
    if (attempts >= 7) {
      cout << "Computer failed to guess the number within 7 attempts." << endl;
      break;
    }
  }

  // Освобождаем память
  delete[] target;
  delete[] guess;
  for (int i = 0; i < 7; i++) {
    delete[] previousGuesses[i];
  }
  delete[] previousGuesses;
  delete[] bullsHistory;
  delete[] cowsHistory;

  return 0;
}

// Функция для подсчета быков и коров
void calculateBullsAndCows(int *target, int *guess, int n, int &bulls,
                           int &cows) {
  bulls = 0;
  cows = 0;
  for (int i = 0; i < n; i++) {
    if (target[i] == guess[i]) {
      bulls++;
    } else {
      for (int j = 0; j < n; j++) {
        if (target[i] == guess[j]) {
          cows++;
          break;
        }
      }
    }
  }
}

// Функция для проверки, является ли число корректным (нет повторяющихся цифр)
bool isValid(int *number, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (number[i] == number[j]) {
        return false;
      }
    }
  }
  return true;
}

// Функция для проверки, согласуется ли предположение с предыдущими результатами
bool isConsistent(int *guess, int n, int *prevGuess, int prevBulls,
                  int prevCows) {
  int bulls, cows;
  calculateBullsAndCows(prevGuess, guess, n, bulls, cows);
  return bulls == prevBulls && cows == prevCows;
}

// Функция для генерации предположения
void generateGuess(int *guess, int n, int **previousGuesses, int *bullsHistory,
                   int *cowsHistory, int numPreviousGuesses) {
  // Инициализируем guess первым возможным значением, если это не первая попытка
  if (numPreviousGuesses > 0) {
    for (int i = 0; i < n; i++) {
      guess[i] = 0;
    }
  }

  while (true) {
    // Проверяем, является ли текущее предположение допустимым
    bool valid = true;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (guess[i] == guess[j]) {
          valid = false;
          break;
        }
      }
      if (!valid)
        break;
    }

    // Проверяем, согласуется ли текущее предположение с предыдущими
    // результатами
    bool consistent = true;
    for (int i = 0; i < numPreviousGuesses; i++) {
      if (!isConsistent(guess, n, previousGuesses[i], bullsHistory[i],
                        cowsHistory[i])) {
        consistent = false;
        break;
      }
    }

    // Если предположение согласуется, возвращаем его
    if (consistent) {
      return;
    }

    // Переходим к следующему числу
    int i = n - 1;
    while (i >= 0 && guess[i] == 9) {
      guess[i] = 0;
      i--;
    }
    if (i < 0) {
      cout << "No valid guesses left after checking all combinations." << endl;
      return;
    }
    guess[i]++;
  }
}
