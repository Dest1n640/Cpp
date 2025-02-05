#include "../Head/file.h"
#include "../Head/search.h"
#include <iostream>
#include <locale.h>

int main(int argc, char **argv) {
  setlocale(LC_ALL, "Russian");

  if (argc < 3) {
    std::cout << "Использование: Triangles.exe inf.txt outf.txt" << std::endl;
    return 1;
  }

  const char *inFileName = argv[1];
  const char *outFileName = argv[2];

  // Определение количества точек
  int numPoints;

  // Чтение точек из файла
  Point *pointArray = new Point[MAX_POINTS]; // Теперь MAX_POINTS известен

  if (!readPoints(inFileName, pointArray, &numPoints)) {
    std::cout << "Ошибка при чтении точек из файла " << inFileName << std::endl;
    delete[] pointArray;
    return 2;
  }

  if (numPoints < 3) {
    std::cout << "Недостаточно точек для построения треугольника." << std::endl;
    delete[] pointArray;
    return 3;
  }

  // Поиск треугольников
  const int maxTrNum = 3;
  Triangle trArray[maxTrNum];
  searchLargestTriangles(pointArray, numPoints, trArray, maxTrNum);

  // Запись результатов в файл
  if (!writeTriangles(outFileName, trArray, maxTrNum)) {
    std::cout << "Ошибка при записи треугольников в файл " << outFileName
              << std::endl;
    delete[] pointArray;
    return 4;
  }

  std::cout << "Программа успешно завершена." << std::endl;

  delete[] pointArray;
  return 0;
}
