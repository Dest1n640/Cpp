#include <iostream>

using namespace std;

int main() {
  const int MAX_SIZE = 1000;
  char *rts = new char[MAX_SIZE];

  cout << "Input the array (string of characters): ";
  cin.getline(rts, MAX_SIZE);

  int n = 0;
  while (rts[n] != '\0') {
    n++;
  }

  int max_length = 1;
  int start = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      bool is_palindrome = true;

      for (int k = 0; k <= (j - i) / 2; k++) {
        if (rts[i + k] != rts[j - k]) {
          is_palindrome = false;
          break;
        }
      }

      if (is_palindrome && (j - i + 1) > max_length) {
        max_length = j - i + 1;
        start = i;
      }
    }
  }

  cout << "Maximum palindrome length: " << max_length << endl;
  cout << "Palindrome: ";
  for (int i = start; i < start + max_length; i++) {
    cout << rts[i];
  }
  cout << endl;

  delete[] rts;

  return 0;
}
