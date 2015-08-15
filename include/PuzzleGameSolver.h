/*
 * class for fit objects
 */

#ifndef PuzzleGameSolver_
#define PuzzleGameSolver_

#include "HexagonCoordinate.h"
#include "PuzzleGame.h"

#include <utility>
#include <vector> 


class PuzzleGameSolver {
 public:
  static std::vector< PuzzleGame > solve(PuzzleGame p);
};


#endif /* PuzzleGameSolver_ */
