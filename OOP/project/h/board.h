#ifndef BOARD_H
#define BOARD_H

#include <filesystem>
#include <vector>

struct Cell {
  int value, row, column;
  bool is_locked;
  Cell(int x, int y, int v, bool locked);
};

class Block {
  int blockSize, blockIndex;
  std::vector<Cell *> cells;

public:
  Block(int index, int bSize);
  void addCell(Cell *c);
  bool contains(int val) const;
  int size() const;
  std::vector<Cell *> getCell() const;
};

class BoardException {};

class Board {
  int size;
  int blockSize;
  std::vector<std::vector<Cell>> grid;
  std::vector<Block> blocks;

  void initBlocks();

public:
  Board(int s);

  Cell &getCell(int r, int c);
  const Cell &getCell(int r, int c) const;
  void setCell(int x, int y, int value);
  bool isValidMove(int r, int c, int val) const;
  std::vector<Cell *> getRow(int r);
  std::vector<Cell *> getColumn(int c);
  std::vector<Cell *> getBlock(int r, int c);
  bool isFull() const;
  int getSize() const;
  int getBlockSize() const;
};

#endif
