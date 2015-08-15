#include "PuzzleGameSolver.h"

std::vector< PuzzleGame >
PuzzleGameSolver::solve(PuzzleGame p){
  if (p.piecesavailable.size()==0){
    std::vector< PuzzleGame > temp;
    temp.push_back(p);
    return(temp);
  }
  else{
    std::vector< PuzzleGame > resultcollector;
    for (HexagonCoordinate& coordinate : p.field.getElements()){
      std::vector< PuzzlePiece > testpieces = p.piecesavailable[0].getCombinatorics(coordinate);
      for (PuzzlePiece& testpiece : testpieces){
        if (p.field.contains(testpiece)){
          PuzzleGame newgame;
          newgame.field = p.field.subtract(testpiece);
          newgame.piecesinplace= p.piecesinplace;
          newgame.piecesinplace.push_back(testpiece);
          for(unsigned int i=1; i<p.piecesavailable.size(); i++)
            newgame.piecesavailable.push_back(p.piecesavailable[i]);
          std::vector< PuzzleGame > result = solve(newgame);
          for( PuzzleGame resultgame : result)
            resultcollector.push_back(resultgame);
        }
      }
    }
    return(resultcollector);
  }
}
