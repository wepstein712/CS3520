#ifndef _BOARD_H
#define _BOARD_H


#include "Util.h"
#include <vector>
#include <string>
class Board {
 public:

  Board();

  ~Board();
void reset_board_size(unsigned int size);
 bool make_move(unsigned int row, unsigned int column);
GameStatus get_status() const;

  void print_board() const;

  int get_board_size();

  void next_turn();

  bool check_move(int row, int column);

 private:
  std::vector<std::vector<Space> > _board;
  GameStatus _gstat;

 
  std::string toString(Space val);
  bool check_finished();
  bool check_tie();
  bool check_col();
  bool check_row();
  bool check_pos_diag();
  bool check_neg_diag();
  void set_endgame_state();

};



#endif
