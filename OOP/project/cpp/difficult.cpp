#include "../h/difficult.h"
#include <algorithm> //либо так либо написать свой shuffle
#include <random>
#include <vector>

PuzzleGenerator::PuzzleGenerator(Difficult d) : level(d) {}

Board PuzzleGenerator::generate(int size) {
  Board board(size);
  std::mt19937 rng(std::random_device{}());

  fillGrid(board, 0, 0, rng);

  int total = size * size;
  int clues;
  switch (level) {
  case Difficult::Easy:
    clues = total * 3 / 5;
    break;
  case Difficult::Medium:
    clues = total * 2 / 5;
    break;
  case Difficult::Hard:
    clues = total * 1 / 5;
    break;
  }
  int removeCount = total - clues;
  removeCells(board, removeCount, rng);
  return board;
}

bool PuzzleGenerator::fillGrid(Board &board, int row, int col,
                               std::mt19937 &rng) {
  int n = board.getSize();
  if (row == n)
    return true; // all rows filled
  int nextRow = (col + 1 == n) ? row + 1 : row;
  int nextCol = (col + 1 == n) ? 0 : col + 1;

  // try numbers 1..n in random order
  std::vector<int> nums(n);
  for (int i = 0; i < n; ++i)
    nums[i] = i + 1;
  std::shuffle(nums.begin(), nums.end(), rng);

  for (int v : nums) {
    if (board.isValidMove(row, col, v)) {
      board.setCell(row, col, v);
      if (fillGrid(board, nextRow, nextCol, rng))
        return true;
      board.setCell(row, col, 0);
    }
  }
  return false; // backtrack
}
void PuzzleGenerator::removeCells(Board &board, int removeCount,
                                  std::mt19937 &rng) {
  int n = board.getSize();
  std::vector<std::pair<int, int>> positions;
  positions.reserve(n * n);
  for (int r = 0; r < n; ++r)
    for (int c = 0; c < n; ++c)
      positions.emplace_back(r, c);

  std::shuffle(positions.begin(), positions.end(), rng);
  int removed = 0;
  for (auto &pos : positions) {
    if (removed >= removeCount)
      break;
    int r = pos.first, c = pos.second;
    if (board.getCell(r, c).value != 0) {
      board.setCell(r, c, 0);
      ++removed;
    }
  }
}
