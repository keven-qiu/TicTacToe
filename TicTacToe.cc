// implementation file

#include <iostream>
#include <vector>
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
    board[i] = i+1;
}

void Board::changeTurn() {
  if (this->turn == X)
    this->turn = O;
  else
    this->turn = X;
}

void Board::start(std::istream &in) {
  Board::getInput(in);
}

int Board::getInput(std::istream &in) {
  int location;
  std::cout << "Print location of ";
  if (this->turn == X) std::cout << "X: ";
  else std::cout << "O: ";

  ++(this->locationsFilled);

  char c;
  in >> c; 
  if (!(c >= '1' && c <= '9')) {
    std::cout << "Please print a number from 1 to " << this->size*this->size << std::endl;
    getInput(in);
  }
  location = c-'0';
  
  return location;
}

void Board::setLoc(int location) {
  char c = this->turn == X ? 'X' : 'O'; 
  this->board[location-1] = c;
}

bool Board::checkBoth() {
  bool checkX = checkWinner('X');
  bool checkO = checkWinner('O');

  if (checkX) this->winner = XWIN;
  else if (checkO) this->winner = OWIN;
  else if (this->locationsFilled == this->size && checkX && checkO) this->winner = TIE;

  if (this->winner != NOWIN)
    return true;
  else
    return false;
}

bool Board::checkWinner(const char letter) {
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

void Board::printWinner() {
  if (this->winner == XWIN)
    std::cout << "X";
  else if (this->winner == OWIN)
    std::cout << "O";
  else {
    std::cout << "Tie!" << std::endl;
    return;
  }
  std::cout << " is the winner!" << std::endl;
}
