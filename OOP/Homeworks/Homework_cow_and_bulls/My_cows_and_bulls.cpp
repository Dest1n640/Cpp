#include <iostream>

using namespace std;

int amount_of_cows(int *number, int *answer, int n);
int amount_of_bulls(int *number, int *answer, int n);
int right_answer(int *number, int *answer, int n);
bool isConsistent(int *guess, int *prev_guess, int n, int prev_bulls,
                  int prev_cows);
bool isValid(int *guess, int n);
int algoritm(int *answer, int n, int *number, int **prev_guesses,
             int *prev_bulls, int *prev_cows, int num_prev_guesses);

// Структура для хранения истории попыток (заменена массивами)
const int MAX_ATTEMPTS = 10; // Максимальное количество попыток
int **history_guesses;       // Массив предыдущих предположений
int *history_bulls;          // Массив результатов по быкам
int *history_cows;           // Массив результатов по коровам
int num_prev_guesses = 0;    // Количество предыдущих предположений

int main() {
  int n;
  cout << "input the amount of numbers: ";
  cin >> n;

  int *number = new int[n]; // Загаданное число
  int *answer = new int[n]; // Предположение

  cout << "input the numbes: ";
  for (int i = 0; i < n; i++) {
    cin >> number[i];
  }

  // Инициализация массивов для истории
  history_guesses = new int *[MAX_ATTEMPTS];
  for (int i = 0; i < MAX_ATTEMPTS; ++i) {
    history_guesses[i] = new int[n];
  }
  history_bulls = new int[MAX_ATTEMPTS];
  history_cows = new int[MAX_ATTEMPTS];

  num_prev_guesses = 0; // Сбрасываем количество предыдущих предположений

  for (int attempt = 0; attempt < MAX_ATTEMPTS; ++attempt) {
    algoritm(answer, n, number, history_guesses, history_bulls, history_cows,
             num_prev_guesses); // Алгоритм генерирует предположение

    cout << "Attempt " << attempt + 1 << ": Generated guess: ";
    for (int i = 0; i < n; ++i) {
      cout << answer[i] << " ";
    }
    cout << endl;

    int cows = amount_of_cows(number, answer, n);
    int bulls = amount_of_bulls(number, answer, n);
    cout << "Cows: " << cows << ", Bulls: " << bulls << endl;

    if (right_answer(number, answer, n) == 0) {
      cout << "Algorithm found the correct answer!" << endl;
      break;
    }

    // Сохраняем результат попытки в историю
    for (int i = 0; i < n; ++i) {
      history_guesses[num_prev_guesses][i] = answer[i];
    }
    history_bulls[num_prev_guesses] = bulls;
    history_cows[num_prev_guesses] = cows;
    num_prev_guesses++;

    if (attempt == MAX_ATTEMPTS - 1) {
      cout << "Algorithm failed to find the correct answer within "
           << MAX_ATTEMPTS << " attempts." << endl;
    }
  }

  for (int i = 0; i < MAX_ATTEMPTS; ++i) {
    delete[] history_guesses[i];
  }
  delete[] history_guesses;
  delete[] history_bulls;
  delete[] history_cows;

  delete[] number;
  delete[] answer;
  return 0;
}

int amount_of_cows(int *number, int *answer, int n) {
  int cows = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (number[i] == answer[j] && i != j) {
        cows++;
      }
    }
  }
  return cows;
}

int amount_of_bulls(int *number, int *answer, int n) {
  int bulls = 0;
  for (int i = 0; i < n; i++) {
    if (number[i] == answer[i]) {
      bulls++;
    }
  }
  return bulls;
}

int right_answer(int *number, int *answer, int n) {
  int bulls = amount_of_bulls(number, answer, n);
  if (bulls == n) {
    cout << "right_anwser" << endl;
    return 0;
  } else {
    cout << "error anwswer" << endl;
    return -1;
  }
}

bool isConsistent(int *guess, int *prev_guess, int n, int prev_bulls,
                  int prev_cows) {
  int bulls = 0;
  int cows = 0;
  // Вычисляем быков и коров между guess и prev_guess
  for (int i = 0; i < n; ++i) {
    if (guess[i] == prev_guess[i]) {
      bulls++;
    }
    for (int j = 0; j < n; ++j) {
      if (guess[i] == prev_guess[j] && i != j) {
        cows++;
      }
    }
  }

  return (bulls == prev_bulls && cows == prev_cows);
}

bool isValid(int *guess, int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (guess[i] == guess[j]) {
        return false; // Есть повторяющиеся цифры
      }
    }
  }
  return true; // Все цифры уникальны
}

int algoritm(int *answer, int n, int *number, int **prev_guesses,
             int *prev_bulls, int *prev_cows, int num_prev_guesses) {
  int combination[4] = {0, 0, 0, 0}; // Предполагаем n = 4

  for (int i = 0; i < 10000; ++i) {
    int temp = i;
    for (int j = n - 1; j >= 0; --j) {
      combination[j] = temp % 10;
      temp /= 10;
    }
    if (!isValid(combination, n))
      continue; // Пропускаем, если не уникальны
    bool consistent = true;
    for (int k = 0; k < num_prev_guesses; ++k) {
      if (!isConsistent(combination, prev_guesses[k], n, prev_bulls[k],
                        prev_cows[k])) {
        consistent = false;
        break;
      }
    }

    if (consistent) {
      for (int j = 0; j < n; ++j) {
        answer[j] = combination[j];
      }
      return 0;
    }
  }

  // Если не нашли подходящего предположения, возвращаем что-то
  // Например, первую попытку (0123) если history пуста
  if (num_prev_guesses == 0 && n >= 4) {
    answer[0] = 0;
    answer[1] = 1;
    answer[2] = 2;
    answer[3] = 3;
    return 0;
  }
  return -1; // Не удалось найти предположение
}
