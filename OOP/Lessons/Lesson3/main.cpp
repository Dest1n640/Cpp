#include <csignal>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string find_date(string file_name, string age, string data,
                 string month); // Функция которая считывает все нужные данные,
                                // которые соотвествуют нужной дате
string moonrice(string file_name); // Выделение нужной даты

int main() {
  string age, data, month;
  cout << "Input the age, data and month (ade data month): ";
  cin >> age >> data >> month;

  string file_name = "./moon/Moon/moon";
  file_name += age;
  file_name += ".dat";

  ifstream file(file_name);

  if (!file.is_open()) { // Проверка открылся ли файл
    cout << "the file is not open" << endl;
    return -1;
  } else {
    cout << "file succsesfully open";
  }
  file.close();

  find_date(file_name, age, data, month);

  return 0;
}

string find_date(string file_name, string age, string data, string month) {
  ifstream file(file_name);
  string needed_data;
  needed_data = age + month + data;

  if (!file.is_open()) {
    cout << "Error opening file in find_date function!" << endl;
    return "Error";
  }

  cout << "Full_data = " << needed_data << endl;
  string line;
  while (getline(file, line)) {
    if (line.find(needed_data) != string::npos) {
      cout << "Full line: " << line << endl;
    }
  }
  file.close();
  return line;
}

string moonrice(string file_name, string age, string data, string month) {
  ifstream file(file_name);
  string moonrice;

  if (!file.is_open()) {
    cout << "Error opening file in find_date function!" << endl;
    return "Error";
  }

  string lines = find_date(file_name, age, data, month);

  while (getline(file, lines)) {
    if (lines.find(moonrice) != string::npos) {
    }
  }
}
