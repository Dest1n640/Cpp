#ifndef DESK_H
#define DESK_H

#include "../cpp/figure.cpp"
#include <map>

struct Cell {
  int x, y;
  Cell(int xx, int yy);
};

class Boaed {
  Figure *pFigure[8][8];
};

#endif // ! DESK_H
