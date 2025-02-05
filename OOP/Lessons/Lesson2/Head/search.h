#ifndef SEARCH_H
#define SEARCH_H

#include "geometry.h"

// Поиск треугольников максимальной площади
void searchLargestTriangles(const Point *pointArray, int numPoints,
                            Triangle *trArray, int maxTrNum);

#endif
