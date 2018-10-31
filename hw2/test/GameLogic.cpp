#include "GameLogic.h"
#include "Util.h"
#include <iostream>

GameLogic::GameLogic()
{
  // TODO ?
}
  
GameLogic::~GameLogic()
{
  // TODO ?
}

void GameLogic::run()
{
  _finished = false;

  input_board_size();

  while (!_finished) {
    display_board_and_input_next_move();
  }
}

void GameLogic::input_board_size()
{
  // TODO

  std::cout << "Input board size (2-5): ";
  std::cout << "Invalid size." << std::endl;
}

void GameLogic::display_board_and_input_next_move()
{
  _board.print_board();
  std::cout << std::endl;

  // TODO

  std::cout << "Enter move for X: ";
  std::cout << "Enter move for O: ";
  std::cout << "Tie game!" << std::endl;
  std::cout << "X wins!" << std::endl;
  std::cout << "O wins!" << std::endl;
  std::cout << "Illegal move." << std::endl;
  std::cout << "Goodbye." << std::endl;

  _finished = true;
}
