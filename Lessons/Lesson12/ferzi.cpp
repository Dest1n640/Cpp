#include <fstream>
#include <iostream>
#include <locale> //В задании данная библиотека не используется, но в решении из презентации она есть

using namespace std;

int readVert(ifstream &in);
int readHoriz(ifstream &in);
bool readQueens(const char *fileName, int *qx, int *qy);
bool isThreaten(int qx1, int qy1, int qx2, int qy2);
void writePair(ofstream &out, int qx1, int qy1, int qx2, int qy2);
bool isPathClear(int qx1, int qy1, int qx2, int qy2, const int *qx,
                 const int *qy);

int main() {
  int qx[8], qy[8];

  if (!readQueens("my_file.txt", qx, qy)) {
    cout << "The file cannot be read or contains invalid data." << endl;
    return -1;
  }

  ofstream out("Output_file.txt");
  if (!out.is_open()) {
    cout << "The output file cannot be created or written to." << endl;
    return -2;
  }

  for (int i = 0; i < 8; i++) {
    out << "Queen " << (i + 1) << ": Column = " << qx[i] << ", Row = " << qy[i]
        << endl;
  }
  for (int i = 0; i < 8; i++) {
    for (int j = i + 1; j < 8; j++) {
      if (isThreaten(qx[i], qy[i], qx[j], qy[j]) &&
          isPathClear(qx[i], qy[i], qx[j], qy[j], qx, qy)) {
        writePair(out, qx[i], qy[i], qx[j], qy[j]);
      }
    }
  }
  out.close();
  cout << "Queens' positions have been successfully written to the output file."
       << endl;
  return 0;
}

bool readQueens(const char *fileName, int *qx, int *qy) {
  ifstream in(fileName);
  if (!in.is_open()) {
    return false;
  }

  for (int i = 0; i < 8; i++) {
    qx[i] = readVert(in);
    qy[i] = readHoriz(in);
    if (in.fail() || qx[i] == 0 || qy[i] == 0) {
      in.close();
      return false;
    }
  }
  in.close();
  return true;
}

int readVert(ifstream &in) {
  char ch;
  in >> ch;
  if (ch < 'a' || ch > 'h') {
    return 0;
  }
  return ch - 'a' + 1;
}

int readHoriz(ifstream &in) {
  char ch;
  in >> ch;
  if (ch < '1' || ch > '8') {
    return 0;
  }
  return ch - '1' + 1;
}

bool isThreaten(int qx1, int qy1, int qx2, int qy2) {
  return (qx1 == qx2 || qy1 == qy2 || (qx1 - qx2 == qy1 - qy2) ||
          (qx2 - qx1 == qy2 - qy1));
}
bool isPathClear(int qx1, int qy1, int qx2, int qy2, const int *qx,
                 const int *qy) {
  int dx = (qx2 > qx1)   ? 1
           : (qx2 < qx1) ? -1
                         : 0; // Вопросительный знак позволяет записывать
                              // вопросительные конструкции более компактно
  int dy = (qy2 > qy1) ? 1 : (qy2 < qy1) ? -1 : 0;
  // условие ? выражение_если_истина : выражение_если_ложь;
  // Эквивалентно тому если бы я прописывал if/if else/else. Решил попробовать
  // решить через данный метод

  int x = qx1 + dx;
  int y = qy1 + dy;

  while (x != qx2 || y != qy2) {
    for (int i = 0; i < 8; i++) {
      if (qx[i] == x && qy[i] == y) {
        return false;
      }
    }
    x += dx;
    y += dy;
  }

  return true;
}

void writePair(ofstream &out, int qx1, int qy1, int qx2, int qy2) {
  char qv1 = (qx1 - 1) + 'a';
  char qv2 = (qx2 - 1) + 'a';
  out << qx1 << qy1 << qx2 << qy2 << endl;
}
