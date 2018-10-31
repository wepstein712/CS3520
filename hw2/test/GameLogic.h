#ifndef _GAME_LOGIC_H
#define _GAME_LOGIC_H



#include "Board.h"

// class representing input handling and logic for the game
class GameLogic {
 public:

  GameLogic();
  
  ~GameLogic();

  // runs the game.
  void run();

  // prompts user for board size and reads from stdin.
  // sizes outside the range 2-5 or input errors print an error message and the program finishes.
  void input_board_size();

  // displays the board; if the game is over displays a message about who won and the program finishes.
  // if the game is ongoing, prompts the appropriate player for input and reads in the row and column of their desired move.
  // if either is negative or there is an input error, the program prints a message and finishes.
  // otherwise, makes the move if it is legal or prints an error message if it is not.
  void display_board_and_input_next_move();

 private:

  Board _board; // the game board
  bool _finished; // true if the game has finished

};



#endif
