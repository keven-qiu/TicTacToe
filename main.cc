// main driver

#include <iostream>
#include <cstdlib>
#include "TicTacToe.h"

#define OS 1 // 1 = linux/macOS, 2 = Windows
#if OS == 1
#define clearScreen "clear"
#else
#define clearWindows "CLS";
#endif

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

  while (true) {
    // clear screen
    std::cout << std::flush;
    system(clearScreen);

    // print board
    play.printBoard();

    // get input and set location on board
    int location = play.getInput(std::cin);
    play.setLoc(location);
    
    // change turn
    play.changeTurn();
    
    // check if any winner
    if (play.checkBoth()) {
      play.printWinner();
      break;
    }
  }
}