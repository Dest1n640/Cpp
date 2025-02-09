#include "search.h"
#include "../Head/geometry.h"

// Вставка треугольника в отсортированный массив
void findAndInsert(Triangle *trArray, int length, const Triangle &triangle) {
  int pos;
  for (pos = length - 1; pos >= 0; pos--) {
    if (triangle.area <= trArray[pos].area) {
      break;
    }
  }
  pos++;
  if (pos == length) {
    return;
  }
  for (int m = length - 2; m >= pos; m--) {
    trArray[m + 1] = trArray[m];
  }
  trArray[pos] = triangle;
}

// Поиск треугольников максимальной площади
void searchLargestTriangles(const Point *pointArray, int numPoints,
                            Triangle *trArray, int maxTrNum) {
  if (maxTrNum <= 0) {
    return;
  }

  // Очистка треугольников
  for (int i = 0; i < maxTrNum; i++) {
    clearTriangle(trArray[i]);
    trArray[i].area = 0.0; // Инициализация минимальной площадью
  }

  for (int i = 0; i < numPoints; i++) {
    for (int j = i + 1; j < numPoints; j++) {
      for (int k = j + 1; k < numPoints; k++) {
        Triangle triangle;
        triangle.vertexes[0] = pointArray[i];
        triangle.vertexes[1] = pointArray[j];
        triangle.vertexes[2] = pointArray[k];
        calcTriangleArea(triangle);
        findAndInsert(trArray, maxTrNum, triangle);
      }
    }
  }
}
