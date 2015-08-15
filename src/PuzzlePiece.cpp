#include "PuzzlePiece.h"

#include <iostream>
#include <iomanip>
#include <algorithm>

PuzzlePiece::PuzzlePiece()
  :m_elements(std::vector< HexagonCoordinate >()){
}

PuzzlePiece::PuzzlePiece(std::vector< HexagonCoordinate > elements)
  :m_elements(elements){
}

void
PuzzlePiece::translate(int x, int y){
  for (HexagonCoordinate&  coordinate : m_elements)
    coordinate.translate(x,y);
}

void
PuzzlePiece::mirror(){
  for (HexagonCoordinate& coordinate : m_elements)
    coordinate.mirror();
}

void
PuzzlePiece::rotate(){
  for (HexagonCoordinate& coordinate : m_elements)
    coordinate.rotate();
}

TMultiGraph*
PuzzlePiece::getPuzzlePieceGraph(int color) const {
  TMultiGraph *mg = new TMultiGraph();
  for (HexagonCoordinate& coordinate : getElements() )
    mg->Add(coordinate.getHexagon(color));
  return(mg);
}

std::vector< HexagonCoordinate >
PuzzlePiece::getElements() const{
  return(m_elements);
}


bool
PuzzlePiece::contains(PuzzlePiece p){
  for (HexagonCoordinate& puzzlepieceelement : p.getElements() ){
    bool found = std::find(m_elements.begin(), m_elements.end(), puzzlepieceelement)!=m_elements.end();
    if (!found) return(false);
  }
    
  return(true);
}

PuzzlePiece
PuzzlePiece::subtract(PuzzlePiece p){
  std::vector<HexagonCoordinate> tmp;
  std::vector<HexagonCoordinate> piece = p.getElements();
  for (HexagonCoordinate coordinate : getElements())
    if((std::find(piece.begin(), piece.end(), coordinate))==piece.end())
      tmp.push_back(coordinate);
  return(PuzzlePiece(tmp));
}

std::vector< PuzzlePiece >
PuzzlePiece::getCombinatorics(HexagonCoordinate coordinate){
  PuzzlePiece tmppiece(*this);
  std::vector< PuzzlePiece > tmp;
  for (int i=0; i<6; i++){
    tmppiece.rotate();
    tmp.push_back(PuzzlePiece(tmppiece));
  }
  tmppiece.mirror();
  for (int i=0; i<6; i++){
    tmppiece.rotate();
    tmp.push_back(PuzzlePiece(tmppiece));
  }

  for (PuzzlePiece& p : tmp){
    p.translate(coordinate.x(), coordinate.y());
  }
  return(tmp);
}
