#include "../h/consoleUI.h"
#include "../h/difficult.h"
#include <iostream>

Difficult ConsoleUI::selectDiff() {
  int choice = 0;
  std::cout << "Select difficulty:\n"
               " 1) Easy\n"
               " 2) Medium\n"
               " 3) Hard\n"
               "Enter choice: ";
  while (!(std::cin >> choice) || choice < 1 || choice > 3) {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "Invalid. Enter 1, 2 or 3: ";
  }
  return static_cast<Difficult>(choice - 1);
}

int ConsoleUI::selectBoardSize() {
  int n = 0;
  std::cout << "Enter board size (e.g. 9 for 9x9): ";
  while (!(std::cin >> n) || n <= 0) {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout << "Invalid. Enter a positive integer: ";
  }
  return n;
}
void ConsoleUI::displayBoard(const Board &board) {
  int n = board.getSize();
  std::cout << "\n   ";
  for (int c = 0; c < n; ++c)
    std::cout << (c + 1) << ' ';
  std::cout << "\n  +" << std::string(n * 2, '-') << "+\n";

  for (int r = 0; r < n; ++r) {
    std::cout << (r + 1) << " |";
    for (int c = 0; c < n; ++c) {
      int v = board.getCell(r, c).value;
      std::cout << (v == 0 ? '.' : char('0' + v)) << ' ';
    }
    std::cout << "|\n";
  }
  std::cout << "  +" << std::string(n * 2, '-') << "+\n";
}

void ConsoleUI::promptMove(GameEngine &engine) {
  std::cout << "\nCommands:\n"
               " m row col value   -> make move\n"
               " u                 -> undo last move\n"
               " q                 -> quit\n"
               "Enter command: ";

  char cmd;
  std::cin >> cmd;
  if (cmd == 'm') {
    int r, c, v;
    std::cin >> r >> c >> v;
    try {
      engine.applyMove(r - 1, c - 1, v);
    } catch (const std::exception &e) {
      std::cout << "Invalid move: " << e.what() << "\n";
    }
  } else if (cmd == 'u') {
    try {
      engine.undo();
    } catch (const std::exception &e) {
      std::cout << "Nothing to undo.\n";
    }
  } else if (cmd == 'q') {
    std::cout << "Quitting. Bye!\n";
    std::exit(0);
  } else {
    std::cout << "Unknown command.\n";
  }
}

void ConsoleUI::run() {
  Difficult level = selectDiff();
  int size = selectBoardSize();

  PuzzleGenerator generator(level);
  Board puzzle = generator.generate(size);
  GameEngine engine(puzzle);

  while (true) {
    displayBoard(engine.getBoard());
    if (engine.is_win()) {
      std::cout << "\nCongratulations! You solved the puzzle!\n";
      break;
    }
    promptMove(engine);
  }
}
