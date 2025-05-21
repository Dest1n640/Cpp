#include "../h/gameEngine.h"
#include "../h/board.h"
#include <vector>

GameEngine::GameEngine(int boardSize) : board(boardSize) {};

GameEngine::GameEngine(const Board &initialBoard) : board(initialBoard) {}

void GameEngine::setboard(const Board &b) {
  board = b;
  history.clear();
}

const Board &GameEngine::getBoard() const { return board; }

void GameEngine::applyMove(int r, int c, int val) {
  Cell &cell = board.getCell(r, c);
  if (cell.is_locked || !board.isValidMove(r, c, val))
    throw GameEngineException();

  history.push_back({r, c, cell.value, true});
  board.setCell(r, c, val);
}

void GameEngine::undo() {
  if (history.empty())
    throw GameEngineException();

  auto m = history.back();
  history.pop_back();
  board.setCell(m.row, m.col, m.oldValue);
}

bool GameEngine::is_win() const { return board.isFull(); }
