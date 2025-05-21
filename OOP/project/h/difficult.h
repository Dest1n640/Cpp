#ifndef DIFFICULT_H
#define DIFFICULT_H

#include "board.h"
#include "gameEngine.h"
#include <random>
#include <vector>

enum class Difficult { Easy, Medium, Hard };

class PuzzleGenerator {
  Difficult level;

  bool fillGrid(Board &board, int row, int column, std::mt19937 &rng);
  void removeCells(Board &board, int removeCount, std::mt19937 &rng);

public:
  PuzzleGenerator(Difficult d);
  Board generate(int size);
};

#endif // !DIFFICULT_H
