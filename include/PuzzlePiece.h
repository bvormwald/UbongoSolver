/*
 * class for fit objects
 */

#ifndef PuzzlePiece_
#define PuzzlePiece_

#include "HexagonCoordinate.h"

#include "TGraph.h"
#include "TMultiGraph.h"
#include <utility>
#include <vector> 

class PuzzlePiece {
 public:
  PuzzlePiece();
  PuzzlePiece(std::vector< HexagonCoordinate > elements);

  void translate(int x, int y);
  void mirror();
  void rotate();
  bool contains(PuzzlePiece p);
  PuzzlePiece subtract(PuzzlePiece p);

  std::vector< PuzzlePiece > getCombinatorics(HexagonCoordinate coordinate);
  
  std::vector< HexagonCoordinate > getElements() const;
  
  TMultiGraph* getPuzzlePieceGraph(int color) const;
  
 protected:
   std::vector< HexagonCoordinate > m_elements;
};
#endif /* PuzzlePiece_ */
