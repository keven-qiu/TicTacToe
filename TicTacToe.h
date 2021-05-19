// declaration header file

#ifndef _TICTACTOE_H
#define _TICTACTOE_H

#include <iostream>
#include <vector>
#include <utility>

enum Turn {X = 0, O};
enum Result {XWIN = 101, OWIN, TIE, NOWIN};

class Board {
private:
  const int size;
  std::vector<char> board;
  Turn turn;
  Result winner; 
  int locationsFilled;

public:
  Board(int);
  void changeTurn();
  void start(std::istream&);
  int getInput(std::istream&);
  void setLoc(int location);
  bool checkBoth();
  bool checkWinner(const char);
  void printWinner(); 
};

#endif
