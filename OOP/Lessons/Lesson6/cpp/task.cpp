#include "../h/task.h"
#include "../h/array.h"
#include <filesystem>
#include <iostream>

int solve(int k, int N, int *arr) {
  Array my_arr(N);
  for (int i = 0; i < N; i++)
    my_arr.insert(arr[i]);

  for (int i = 0; i < N; i++) {
    if (arr[i] % k == 0) {
      my_arr.remove(i);
      break;
    }
  }
}
