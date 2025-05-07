#ifndef FIGURE_H
#define FIGURE_H

#include "../cpp/desk.cpp"

class Figure {
  Cell Cell;

public:
  Figure(int xx, int yy);
};
class Rook : public Figure {
public:
  Rook(int x, int y);
};

#endif
