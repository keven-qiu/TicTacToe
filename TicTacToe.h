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
  // members
  const int size;
  std::vector<char> board;
  Turn turn;
  Result winner; 
  int locationsFilled;

public:
  // constructor
  Board(int);

  // game utility functions
  void printBoard() const;
  int getInput(std::istream&);
  void setLoc(int location);
  void changeTurn();
  bool checkBoth();
  bool checkWinner(const char) const;
  void printWinner() const; 
};

#endif
