#include "GameLogic.h"
#include "Util.h"
#include <iostream>

using namespace std;

GameLogic::GameLogic()
{
  Board _board = *(new Board());
  GameStatus _gstat = GameStatus:: PLAYING_X_TURN;
}

GameLogic::~GameLogic()
{
  //&_board.~board();
  //delete  &_board;
  
}
void GameLogic::run()
{
  _finished = false;

  input_board_size();
 
  cout << endl;
  while (!_finished) {   
    display_board_and_input_next_move();
  }

}

void GameLogic::input_board_size()
{
  int size = 0;
 
  std::cout << "Input board size (2-5): ";
  std::cin >> size;
  while (size < 2 || size >5) {
    std::cout << "Invalid size." << std::endl;
    std::cin >> size;
  }
  _board.reset_board_size(size);
}

void GameLogic::display_board_and_input_next_move()
{
  int row = -1, col = -1;
  int size = _board.get_board_size();
 
  //std::cout <<"Here is the current board state:" << std::endl;
  //_board.print_board();
  bool res_move = false;
 do {
  res_move = false;
  _board.print_board();
   switch (_board.get_status()) {
    case GameStatus::PLAYING_X_TURN:
      std::cout << "Enter move for X: ";
      if (std::cin >> col >> row) {
      std::cout << endl;
	if (col < 0 || col >= size || row < 0 || row >= size || !_board.check_move(row, col) ) {
        std::cout << "Illegal move." << std::endl; 
       res_move = true;
	} else {
	  _board.make_move(row, col);
        } 
     } else {  
        _finished = true;
        return;
      }
     // _board.make_move(row, col);
      break;
    case GameStatus::PLAYING_O_TURN:
    std::cout << "Enter move for O: ";
     if ( std::cin >> col >> row ) {
	std::cout << endl;
      if (col < 0 || col >= size || row < 0 || row >= size || !_board.check_move(row, col)) {
        std::cout << "Illegal move." << std::endl;
       // _finished = true;
       res_move = true;
      } else {
  	_board.make_move(row, col);
      } 
    } else {
 	_finished = true;
	return;
    }
     // _board.make_move(row, col);
      break;
    //default: std::cout << endl << "How did you get here? Bad programmer, BAD" << std::endl;
  }
} while (res_move);
  switch(_board.get_status()) {
    case GameStatus::PLAYING_X_TURN:
   //  std::cout << "uh what player X?" << endl;
     _board.next_turn();
      break;
    case GameStatus::PLAYING_O_TURN: 
   // std::cout << "uh what player O?" << endl; 
    _board.next_turn();
    break;
    case GameStatus::OVER_TIE: 
	_board.print_board();
    std::cout << "Tie game!" << endl; // << "Here is the game board: ";
   // _board.print_board();
    //std::cout << "Goodbye." << std::endl;
    _finished = true;
    break;
    case GameStatus::OVER_X_WON: 
	_board.print_board();
    std::cout << "X wins!" << endl; // << "Here is the game board: ";
   // _board.print_board();
   // std::cout << "Goodbye." << std::endl;
    _finished = true;
    break;
    case GameStatus::OVER_O_WON: 
     	_board.print_board();
	std::cout << "O wins!" << endl; // << "Here is the game board: ";
   // _board.print_board(); 
    std::cout << "Goodbye." << std::endl;
    _finished = true;
    break;
    default:// std::cout << "wow, just wow" << endl;
    _finished = true;
    break;
      
  }
}
