/*
 * class for fit objects
 */

#ifndef PuzzleGame_
#define PuzzleGame_

#include "PuzzlePiece.h"

#include <utility>
#include <vector> 

class PuzzleGame {
 public:
  PuzzleGame();

  PuzzlePiece field;
  std::vector< PuzzlePiece > piecesavailable;
  std::vector< PuzzlePiece > piecesinplace;
  void print();
};

#endif /* PuzzleGame_ */
