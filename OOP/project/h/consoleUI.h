#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "board.h"
#include "difficult.h"
#include "gameEngine.h"

class ConsoleUI {
  Difficult selectDiff();
  int selectBoardSize();
  void displayBoard(const Board &board);
  void promptMove(GameEngine &engine);

public:
  void run();
};

#endif
