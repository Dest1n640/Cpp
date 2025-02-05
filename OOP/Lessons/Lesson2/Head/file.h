#ifndef FILE_H
#define FILE_H

#include "geometry.h"

// Максимальное количество точек (можешь изменить)
#define MAX_POINTS 1000

// Подсчет числа точек во входном файле
int countPoints(const char *fileName);

// Чтение точек из входного файла
bool readPoints(const char *fileName, Point *pointArray, int *numPoints);

// Вывод треугольников в выходной файл
bool writeTriangles(const char *fileName, const Triangle *trArray, int trNum);

#endif
