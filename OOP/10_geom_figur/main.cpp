#include "./h/geom_fig.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <vector>

void read_points_and_calculate(const std::string &filename);

// Реализация чисто виртуального деструктора Figure
Figure::~Figure() = default;

int main() {
  read_points_and_calculate("granitsy-uchastka2.txt");
  return 0;
}
void read_points_and_calculate(const std::string &filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Ошибка открытия файла: " << filename << std::endl;
    return;
  }

  std::vector<Points> points;
  int x, y;
  std::string line;

  while (std::getline(file, line)) {
    std::istringstream iss(line);
    if (iss >> x >> y) {
      points.emplace_back(x, y);
    }
  }

  try {
    Polygon polygon(points);
    std::cout << "Площадь: " << polygon.calc_area() << std::endl;
    std::cout << "Периметр: " << polygon.calc_perimeter() << std::endl;
  } catch (const Figure_Exception &e) {
    std::cerr << "Ошибка создания многоугольника." << std::endl;
  }
}
