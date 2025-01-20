#include <climits>
#include <iostream>

using namespace std;

// Объявление функций
bool check(int num_villages, int start_village, int end_village, int **trips,
           int num_trips);
void findMinTimeRecursive(int current_village, int current_time,
                          int end_village, int num_trips, int **trips,
                          int &min_time);
int FindMinTime(int num_villages, int start_village, int end_village,
                int **trips, int num_trips);

int main() {
  int num_villages;
  cout << "Input the amount of villages: ";
  cin >> num_villages; // Ввод количества деревень

  int start_village, end_village;
  cout << "Input the number of villages d and v (d v): ";
  cin >> start_village >> end_village; // Ввод начальной и конечной деревень

  int num_trips;
  cout << "Input the amount of bus trips: ";
  cin >> num_trips; // Ввод количества рейсов

  cout << "Input the bus trips(start_village, t1, end_village, t2):" << endl;

  // Выделение памяти под массив рейсов
  int **trips = new int *[num_trips];
  for (int i = 0; i < num_trips; ++i) {
    trips[i] = new int[4]; // 4 значения для каждого рейса (откуда, куда, время
                           // отправления, время прибытия)
    for (int j = 0; j < 4; ++j) {
      cin >> trips[i][j];
    }
  }

  int time = -1; // Инициализируем -1 (если путь не найден)
  if (check(num_villages, start_village, end_village, trips, num_trips)) {
    time =
        FindMinTime(num_villages, start_village, end_village, trips, num_trips);
    if (time == -1) {
      cout << "There are no trips from start_village to the end_village"
           << endl;
    } else {
      cout << "The minimal time from the start_village to the end_village = "
           << time << endl;
    }
  } else {
    cout << "Incorrect input data." << endl;
  }

  // Освобождение памяти
  for (int i = 0; i < num_trips; ++i) {
    delete[] trips[i];
  }
  delete[] trips;

  return 0;
}

// Функция проверки корректности входных данных
bool check(int num_villages, int start_village, int end_village, int **trips,
           int num_trips) {
  // Проверка количества деревень
  if (num_villages < 1 || num_villages > 100) {
    return false;
  }
  // Проверка номеров начальной и конечной деревень
  if (start_village < 1 || start_village > num_villages || end_village < 1 ||
      end_village > num_villages) {
    return false;
  }
  // Проверка данных по каждому рейсу
  for (int i = 0; i < num_trips; ++i) {
    if (trips[i][0] < 1 || trips[i][0] > num_villages || trips[i][2] < 1 ||
        trips[i][2] > num_villages) {
      return false; // Неверный номер деревни отправления или прибытия
    }
    if (trips[i][1] < 0 || trips[i][1] > 10000 || trips[i][3] < 0 ||
        trips[i][3] > 10000 || trips[i][1] >= trips[i][3]) {
      return false; // Неверное время отправления или прибытия
    }
  }
  return true;
}

// Рекурсивная функция для поиска минимального времени пути
void findMinTimeRecursive(int current_village, int current_time,
                          int end_village, int num_trips, int **trips,
                          int &min_time) {
  // Если добрались до конечной деревни
  if (current_village == end_village) {
    if (current_time < min_time) {
      min_time = current_time;
    }
    return;
  }

  // Перебираем все рейсы
  for (int i = 0; i < num_trips; ++i) {
    // Если можем уехать из текущей деревни этим рейсом
    if (trips[i][0] == current_village && trips[i][1] >= current_time) {
      // Рекурсивно вызываем функцию для следующей деревни
      findMinTimeRecursive(trips[i][2], trips[i][3], end_village, num_trips,
                           trips, min_time);
    }
  }
}

// Функция для нахождения минимального времени пути (обертка для рекурсивной
// функции)
int FindMinTime(int num_villages, int start_village, int end_village,
                int **trips, int num_trips) {
  int min_time = INT_MAX; // Инициализируем "бесконечностью"

  findMinTimeRecursive(start_village, 0, end_village, num_trips, trips,
                       min_time);

  return (min_time == INT_MAX) ? -1 : min_time;
}
