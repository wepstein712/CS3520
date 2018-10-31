#ifndef _BOARD_H
#define _BOARD_H



#include "Util.h"
#include <vector>

// class representing the state of the board
// keeps track of the spaces of the board as well as which player's turn it is
class Board {
 public:

  Board();
  
  ~Board();

  // resets the board to be of the given size; resets to X player's turn
  void reset_board_size(unsigned int size);

  // makes a move for the current player in the given row and column if possible, and returns true
  // if the move is not possible (the space is already filled or off the board) no move is made and returns false
  // rows and columns are 0-indexed, for example, the coordinates for a 2x2 board would be:
  //
  // r0 c0 | r0 c1
  // -------------
  // r1 c0 | r1 c1
  bool make_move(unsigned int row, unsigned int column);

  // gets the current status of the game based on the board
  // a game is won by a player if they have filled all the spaces in a row, column, or diagonal
  GameStatus get_status() const;

  // prints the board to stdout
  // uses X, O and space for spaces and | and - to draw lines
  // for example, a 3x3 board might look like:
  //
  // X|O|X
  // -----
  //  | |X
  // -----
  //  |O| 
  void print_board() const;

 private:

  // TODO

  // use a vector (and any other member variables needed) to represent the board state

};



#endif
