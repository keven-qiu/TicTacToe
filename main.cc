#include <iostream>
#include "TicTacToe.h"

/*
___|___|___
___|___|___
   |   |   
*/

int main() {
  Board play(3);

  // use game loop instead of recursion in getInput
  while (true) {
    int location = play.getInput(std::cin);
    play.setLoc(location);
    play.changeTurn();
    if (play.checkBoth()) {
      play.printWinner();
      break;
    }
  }
}