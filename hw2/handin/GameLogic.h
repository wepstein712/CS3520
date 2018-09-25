#ifndef _GAME_LOGIC_H
#define _GAME_LOGIC_H



#include "Board.h"
#include <string>

class GameLogic {
 public:

  GameLogic();

  ~GameLogic();
void run();
void input_board_size();
  void display_board_and_input_next_move();

 private:

  Board _board; 

  bool _finished; 
  bool _x_turn;

  

};

#endif

