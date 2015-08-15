#include <iostream>
#include "HexagonCoordinate.h"
#include "PuzzlePiece.h"
#include "PuzzleGame.h"
#include "PuzzleGameSolver.h"

#include "TMultiGraph.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TH2D.h"
#include <utility>
#include <vector>


int main(int argc, char* argv[])
{
  std::vector<HexagonCoordinate> elements9;
  elements9.push_back(HexagonCoordinate(0,0));
  elements9.push_back(HexagonCoordinate(0,1));
  elements9.push_back(HexagonCoordinate(1,1));
  elements9.push_back(HexagonCoordinate(2,0));
  elements9.push_back(HexagonCoordinate(3,0));
  PuzzlePiece piece9(elements9);

  std::vector<HexagonCoordinate> elements3;
  elements3.push_back(HexagonCoordinate(0,0));
  elements3.push_back(HexagonCoordinate(1,0));
  elements3.push_back(HexagonCoordinate(1,1));
  elements3.push_back(HexagonCoordinate(2,0));
  PuzzlePiece piece3(elements3);

  std::vector<HexagonCoordinate> elements8;
  elements8.push_back(HexagonCoordinate(0,0));
  elements8.push_back(HexagonCoordinate(1,0));
  elements8.push_back(HexagonCoordinate(1,1));
  elements8.push_back(HexagonCoordinate(0,1));
  elements8.push_back(HexagonCoordinate(2,1));
  PuzzlePiece piece8(elements8);

  std::vector<HexagonCoordinate> elements2;
  elements2.push_back(HexagonCoordinate(0,0));
  elements2.push_back(HexagonCoordinate(1,0));
  elements2.push_back(HexagonCoordinate(0,1));
  elements2.push_back(HexagonCoordinate(1,1));
  PuzzlePiece piece2(elements2);

  std::vector<HexagonCoordinate> elements10;
  elements10.push_back(HexagonCoordinate(0,0));
  elements10.push_back(HexagonCoordinate(0,1));
  elements10.push_back(HexagonCoordinate(1,0));
  elements10.push_back(HexagonCoordinate(2,0));
  elements10.push_back(HexagonCoordinate(3,-1));
  PuzzlePiece piece10(elements10);
  
  
  std::vector<HexagonCoordinate> fieldelementsA41;
  fieldelementsA41.push_back(HexagonCoordinate(0,0));
  fieldelementsA41.push_back(HexagonCoordinate(0,1));
  fieldelementsA41.push_back(HexagonCoordinate(0,2));
  fieldelementsA41.push_back(HexagonCoordinate(1,-1));
  fieldelementsA41.push_back(HexagonCoordinate(1,0));
  fieldelementsA41.push_back(HexagonCoordinate(1,1));
  fieldelementsA41.push_back(HexagonCoordinate(1,2));
  fieldelementsA41.push_back(HexagonCoordinate(2,-2));
  fieldelementsA41.push_back(HexagonCoordinate(2,-1));
  fieldelementsA41.push_back(HexagonCoordinate(2,0));
  fieldelementsA41.push_back(HexagonCoordinate(2,1));
  fieldelementsA41.push_back(HexagonCoordinate(3,-2));
  fieldelementsA41.push_back(HexagonCoordinate(3,-1));
  fieldelementsA41.push_back(HexagonCoordinate(3,0));
  PuzzlePiece fieldA41(fieldelementsA41);


  std::vector<HexagonCoordinate> fieldelementsB38;
  fieldelementsB38.push_back(HexagonCoordinate(-1,2));
  fieldelementsB38.push_back(HexagonCoordinate(-1,3));
  fieldelementsB38.push_back(HexagonCoordinate(0,0));
  fieldelementsB38.push_back(HexagonCoordinate(0,1));
  fieldelementsB38.push_back(HexagonCoordinate(0,2));
  fieldelementsB38.push_back(HexagonCoordinate(0,3));
  fieldelementsB38.push_back(HexagonCoordinate(1,-1));
  fieldelementsB38.push_back(HexagonCoordinate(1,0));
  fieldelementsB38.push_back(HexagonCoordinate(1,1));
  fieldelementsB38.push_back(HexagonCoordinate(1,2));
  fieldelementsB38.push_back(HexagonCoordinate(2,-2));
  fieldelementsB38.push_back(HexagonCoordinate(2,-1));
  fieldelementsB38.push_back(HexagonCoordinate(2,0));
  fieldelementsB38.push_back(HexagonCoordinate(2,1));
  fieldelementsB38.push_back(HexagonCoordinate(3,-3));
  fieldelementsB38.push_back(HexagonCoordinate(3,-2));
  fieldelementsB38.push_back(HexagonCoordinate(3,-1));
  fieldelementsB38.push_back(HexagonCoordinate(3,0));
  PuzzlePiece fieldB38(fieldelementsB38);

  
  std::vector< PuzzlePiece > piecesavailableA41;
  piecesavailableA41.push_back(piece9);
  piecesavailableA41.push_back(piece3);
  piecesavailableA41.push_back(piece8);

  std::vector< PuzzlePiece > piecesavailableB38;
  piecesavailableB38.push_back(piece2);
  piecesavailableB38.push_back(piece3);
  piecesavailableB38.push_back(piece8);
  piecesavailableB38.push_back(piece10);

  
  PuzzleGame gameA41;
  gameA41.field=fieldA41;
  gameA41.piecesavailable=piecesavailableA41;

  PuzzleGame gameB38;
  gameB38.field=fieldB38;
  gameB38.piecesavailable=piecesavailableB38;
  

  PuzzleGame game=gameB38;
  
  std::vector< PuzzleGame > results = PuzzleGameSolver::solve(game);
  std::cout << results.size() << " solution(s) found" << std::endl;

  TFile f("out.root","RECREATE");
  for (unsigned int i=0; i<results.size(); i++){
    TCanvas c(Form("c%d",i),"c",500,500);
    TH2D h("h","",1,-4,4,1,-4,4);
    h.Draw();

    for(unsigned int j=0; j<game.piecesavailable.size();j++)
      results[i].piecesinplace[j].getPuzzlePieceGraph(j+2)->Draw("LF");

    c.Write();
  }
  f.Close();
  return(0);
}
