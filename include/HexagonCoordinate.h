/*
 * class for fit objects
 */

#ifndef HexagonCoordinate_
#define HexagonCoordinate_

#include "TGraph.h"
#include <utility>
#include <vector> 

class HexagonCoordinate {
 public:
  HexagonCoordinate(int x, int y);

  void translate(int x, int y);
  void mirror();
  void rotate();

  int x() const;
  int y() const;
  
  TGraph* getHexagon(int color) const;
  std::pair< double,double > makeCarthesian() const;    

  bool operator==(HexagonCoordinate const& rhs);
   
 protected:
  int m_x;
  int m_y;
};
#endif /* HexagonCoordinate_ */
