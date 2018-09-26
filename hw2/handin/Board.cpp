#include "Board.h"
#include <iostream>
using namespace std; 

Board::Board()
{
  _board = *(new vector< vector <Space> >);
  GameStatus _gstat = GameStatus:: PLAYING_X_TURN;
}

Board::~Board()
{
   //_board = nullptr;
   for (int i = 0; i < _board.size(); i++) {
    _board[i].resize(0);
  } 
  _board.resize(0);
  //delete *(_board);
  
}

int Board::get_board_size() {
  return _board.size();
}

void Board::reset_board_size(unsigned int size)
{
  _gstat = GameStatus::PLAYING_X_TURN;

  _board.resize(0);
  _board.resize(size);
 
  for (auto i = 0; i < size; ++i) {
    _board[i].resize(0);
    _board[i].resize(size);
    for (auto j = 0; j < size; ++j) {
        _board[i][j] = Space::BLANK;

    }

  }
}

bool Board::make_move(unsigned int row, unsigned int column)
{
  if (check_move(row, column)) {
    switch (_gstat) {
      case  GameStatus::PLAYING_X_TURN:
        _board[row][column] = Space::X; 
         if (check_finished()) {
          set_endgame_state();
         }
       return true;
      case  GameStatus::PLAYING_O_TURN: 
        _board[row][column] = Space::O;
        if (check_finished()) {
            set_endgame_state();
        }
        return true;
      default: std::cout << "how, just how"; return false;
    }
  } else {
    return false;
  }

}

GameStatus Board::get_status() const
{
   return _gstat;

}

void Board::print_board() const { 
  
    for (int i = 0; i < _board.size(); i++) { 
        for (int j = 0; j < _board[i].size(); j++) { 
            
            switch ( _board[i][j]) {
              case Space::X: std::cout << "|X|"; break;
              case Space::O: std::cout << "|O|"; break;
              case Space::BLANK: std::cout << "| |"; break;
 
}            
}
        std::cout << std::endl; 
    } 

}

/*
void Board::print_board() const
{
 std::cout << "size = " << _board.size() << endl;
    for (int i = 0; i < _board.size(); i++) { 
        for (int j = 0; j < _board[i].size(); j++) { 
            
            switch (_board[i][j]) {
              case Space::X: std::cout << "X|";
                  break;
              case Space::O: std::cout << "O|";
                  break;
              case Space::BLANK: std::cout << " |" ;
                  break;
              default: std::cout << "E|";
                  break;
            }
        }
        std::cout << endl; 
    } 
}

*/


void Board::next_turn() {
  switch (_gstat) {
      case GameStatus::PLAYING_X_TURN: _gstat = GameStatus::PLAYING_O_TURN; break;
      case GameStatus::PLAYING_O_TURN: _gstat = GameStatus::PLAYING_X_TURN; break;
      default: std::cout << "how did you get here, bad bad bad person" << endl;
    }
}

bool Board::check_move(int x, int y) {
  switch (_board[x][y]) {
    case Space::BLANK: return true;
    defult: return false;
  }
  return false;
}

string Board::toString(Space val) {
   switch(val) {
     case Space::BLANK: return " ";
     case Space::X: return "X";
     case Space::O: return "O";
     default: return "E";
   }
   return "E";
 }



bool Board::check_finished() {
    return check_col() || check_row() || check_pos_diag() || check_neg_diag() || check_tie();
}

void Board::set_endgame_state() {
  if (check_tie()) {
    _gstat = GameStatus::OVER_TIE;
  } else {
    switch (_gstat) {
      case GameStatus::PLAYING_X_TURN: _gstat = GameStatus::OVER_X_WON; break;
      case GameStatus::PLAYING_O_TURN: _gstat = GameStatus::OVER_O_WON; break;
      default: std::cout << "you were sooo close, you fool" << endl;
    }
  }
}


bool Board::check_tie() {
  for (int i = 0; i < _board.size(); i++) {
    for (int j = 0; j < _board[i].size(); j++) {
      switch (_board[i][j]) {
        case Space::BLANK: return false; 
      }
    }
  }
  return true;
}

bool Board::check_col() {
  bool check = false;
  Space hold = Space::BLANK;
  
    for (int j = 0; j < _board.size(); j++) {
   for (int i = 0; i < _board[j].size(); i++) {
    
     if (i == 0) {
       if (toString(_board[i][j]) == " ") {
        
         hold = Space::BLANK;
         break;
       }
       hold = _board[i][j];
     
       continue;
     } else {
       if (toString(_board[i][j]) == toString(hold)) {
          if (i == _board[j].size() - 1) {
            check = true;
            
          }
         
         continue;
       } else {
         hold = Space::BLANK;
          
         break;
        
       }
      
     }
   }
  
  }
 //if (check) { std::cout << std::endl << "COL PASSED" << endl; }
 return check;
}


bool Board::check_row() {
  bool check = false;
  Space hold = Space::BLANK;

  for (int i = 0; i < _board.size(); i++) {
    for (int j = 0; j < _board[i].size(); j++) {
    
      if (j == 0) {
        if (toString(_board[i][j]) == " ") {
        
          break;
        }
        hold = _board[i][j];
      
        continue;
      } else {
        if (toString(_board[i][j]) == toString(_board[i][j-1])) {
          if (j == _board[i].size() - 1) {
            check = true;
            
          }
          continue;
        } else {
          break;
        
        }
      
      }
    }
  }

 //if (check) { std::cout << std::endl << "ROW PASSED" << endl; }


  return check;
}


bool Board::check_pos_diag() {
  bool check = false;
  Space hold = Space::BLANK;
  for (int i = 0; i < _board.size(); i++) {
    for (int j = 0; j < _board[i].size(); j++) {
      
      if (i+j == _board.size()-1) {
        if (j == _board.size()-1 ) {
          if (toString(_board[i][j]) == " ") {
            hold = Space::BLANK;
           
            break;
          } else {
            hold = _board[i][j];
            
          }
        } else {
          if (toString(_board[i][j]) == toString(hold)) {
            if (i == _board.size() - 1 && toString(_board[i][j]) != " ") {
              check = true;
              
            } 
            
            continue;
          } else {
            hold =  Space::BLANK;
            
            break;
          }
        }
      } else {
       
      }
    }
  }

 //if (check) { std::cout << std::endl << "POSD PASSED" << endl; }


  return check;

}


bool Board::check_neg_diag() {
  bool check = false;
  Space hold = Space::BLANK;

  for (int i = 0; i < _board.size(); i++) {
    for (int j = 0; j < _board[i].size(); j++) {
      
      if (i == j) {
        if (i == 0 ) {
          if (toString(_board[i][j]) == " ") {
            hold = Space::BLANK;
            break;
          } else {
            hold = _board[i][j];
           
          }
        } else {
          if (toString(_board[i][j]) == toString(hold)) {
            if (i == _board.size() - 1 && toString(_board[i][j]) != " ") {
              check = true;
              
            } 
           
            continue;
          } else {
            hold =  Space::BLANK;
            
            break;
          }
        }
      } 
    }
   
  }

 //if (check) { std::cout << std::endl << "NEGD PASSED" << endl; }


   return check;

}

