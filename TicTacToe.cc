// implementation file

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "TicTacToe.h"

// Board Constructor
Board::Board(int boardSize):
  size(boardSize),
  board(boardSize * boardSize),
  turn(X),
  winner(NOWIN),
  locationsFilled(0)
{
  for (int i = 0; i < boardSize*boardSize; ++i)
    board[i] = '0'+i+1;
}

// print TicTacToe board to screen
// updates with new chars in member board
// does not mutate any member variables
// return: void
void Board::printBoard() const {
  std::cout << "         |         |         " << std::endl;
  std::cout << "    " << this->board[0] << "    |    " << this->board[1] << "    |    " << this->board[2] << "    " << std::endl;
  std::cout << "_________|_________|_________" << std::endl;

  std::cout << "         |         |         " << std::endl;
  std::cout << "    " << this->board[3] << "    |    " << this->board[4] << "    |    " << this->board[5] << "    " << std::endl;
  std::cout << "_________|_________|_________" << std::endl;
  std::cout << "         |         |         " << std::endl;
  std::cout << "    " << this->board[6] << "    |    " << this->board[7] << "    |    " << this->board[8] << "    " << std::endl;
  std::cout << "         |         |         " << std::endl;
}

// getInput gets location input from user
// param:
// std::istream& in: input stream reference
// returns location of input
int Board::getInput(std::istream& in) {
  int location;
  std::cout << "Print location of ";
  if (this->turn == X) std::cout << "X: ";
  else std::cout << "O: ";

  std::string s;
  while (in >> s) {
    if (in.eof())
      exit(0);
    std::istringstream iss{s};
    // if iss can be written to an int or if location is out of bounds
    if (!(iss >> location) || (location < 1 || location > 9))
      std::cout << "Please print a number from 1 to " << this->size*this->size << std::endl;
    else break;
  }
  
  ++(this->locationsFilled);
  
  return location;
}

void Board::setLoc(int location) {
  char c = this->turn == X ? 'X' : 'O'; 
  this->board[location-1] = c;
}

// changeTurn changes member variable turn
// to the person's turn
// return: void
void Board::changeTurn() {
  if (this->turn == X)
    this->turn = O;
  else
    this->turn = X;
}

bool Board::checkBoth() {
  bool checkX = checkWinner('X');
  bool checkO = checkWinner('O');

  if (checkX) this->winner = XWIN;
  else if (checkO) this->winner = OWIN;
  else if (this->locationsFilled == this->size*this->size && this->winner == NOWIN) this->winner = TIE;

  if (this->winner != NOWIN)
    return true;
  else
    return false;
}

// check if there are any winners in current round
// does not mutate any member variables
// params:
// const char letter: letter of person
bool Board::checkWinner(const char letter) const {
  // check rows
  for (int i = 0; i < this->size*this->size; i+=3)
    if (board[i] == letter && board[i]==board[i+1] && board[i+1]==board[i+2])
      return true;
  // check columns
  for (int i = 0; i < this->size; ++i)
    if (board[i] == letter && board[i]==board[i+3] && board[i+3]==board[i+6])
      return true;
  // check diagonals
  if (board[0] == letter && board[0]==board[4] && board[4]==board[8])
    return true;
  if (board[0] == letter && board[2]==board[4] && board[4]==board[6])
    return true;

  return false;
}

// print winner of the game
// does not mutate any member variables
// return: void
void Board::printWinner() const {
  std::cout << "--------------------" << std::endl;
  if (this->winner == XWIN)
    std::cout << "X";
  else if (this->winner == OWIN)
    std::cout << "O";
  else {
    std::cout << "Tie!" << std::endl;
    std::cout << "--------------------" << std::endl;
    return;
  }
  std::cout << " is the winner!" << std::endl;
  std::cout << "--------------------" << std::endl;
}
