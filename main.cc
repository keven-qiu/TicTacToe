// main driver

#include <iostream>
#include <cstdlib>
#include "TicTacToe.h"

/*
      |      |      
      |      |      
______|______|______
      |      |      
      |      |      
______|______|______
      |      |      
      |      |      
      |      |      
*/

int main() {
  Board play(3);

  // use game loop instead of recursion in getInput
  while (true) {
    std::cout << std::flush;
    system("clear");
    play.printBoard();
    int location = play.getInput(std::cin);
    play.setLoc(location);
    play.changeTurn();
    if (play.checkBoth()) {
      play.printWinner();
      break;
    }
  }
}