#include "../Head/file.h"
#include <fstream>
#include <iostream>

// Подсчет числа точек во входном файле
int countPoints(const char *fileName) {
  std::ifstream in(fileName);
  if (!in.is_open()) {
    return -1; // Ошибка открытия файла
  }
  int count = 0;
  double x, y;
  while (in >> x >> y) {
    count++;
  }
  return count;
}

// Чтение точек из входного файла
bool readPoints(const char *fileName, Point *pointArray, int *numPoints) {
  std::ifstream in(fileName);
  if (!in.is_open()) {
    return false; // Ошибка открытия файла
  }

  int i = 0;
  while (in >> pointArray[i] && i < MAX_POINTS) {
    i++;
  }

  *numPoints = i;

  if (in.fail() && !in.eof()) {
    return false; // Ошибка чтения данных
  }
  return true;
}

// Вывод треугольников в выходной файл
bool writeTriangles(const char *fileName, const Triangle *trArray, int trNum) {
  std::ofstream out(fileName);
  if (!out.is_open()) {
    return false; // Ошибка открытия файла
  }
  for (int i = 0; i < trNum; i++) {
    out << "#" << i + 1 << ": " << trArray[i] << std::endl;
  }
  return true;
}
