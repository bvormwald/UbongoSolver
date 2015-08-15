#include "PuzzleGame.h"
#include <iostream>

PuzzleGame::PuzzleGame()
  :field(),
   piecesavailable(),
   piecesinplace()
{
}

void
PuzzleGame::print(){
  std::cout << piecesavailable.size() << std::endl;
}
