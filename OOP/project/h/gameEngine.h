#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "board.h"
#include <vector>

struct Move {
  int row, col;
  int oldValue, newValue;
};

class GameEngineException {};

class GameEngine {
  Board board;
  std::vector<Move> history;

public:
  GameEngine(int boardSize);
  GameEngine(const Board &initialBoard);
  void applyMove(int x, int y, int value);
  void undo();
  bool is_win() const;
  void setboard(const Board &b);
  const Board &getBoard() const;
};

#endif
