#include "HexagonCoordinate.h"

#include <iostream>
#include <iomanip>

HexagonCoordinate::HexagonCoordinate(int x, int y)
  :m_x(x),
   m_y(y){
}

void
HexagonCoordinate::translate(int x, int y){
  m_x+=x;
  m_y+=y;
 }

void
HexagonCoordinate::mirror(){
  int x=m_x;
  int y=m_y;
  m_x=x+y;
  m_y=-y;
}

void
HexagonCoordinate::rotate(){
  int x=m_x;
  int y=m_y;
  m_x=x+y;
  m_y=-x;
}

std::pair< double,double >
HexagonCoordinate::makeCarthesian() const{
  return(std::make_pair(m_x+0.5*m_y, sqrt(3)/2.*m_y));
}

TGraph*
HexagonCoordinate::getHexagon(int color) const {
  std::pair< double,double > cart = makeCarthesian();

  TGraph *g = new TGraph();
  g->SetPoint(0, cart.first-0.5, cart.second-1./(2*sqrt(3)));
  g->SetPoint(1, cart.first-0.5, cart.second+1./(2*sqrt(3)));
  g->SetPoint(2, cart.first, cart.second+1./sqrt(3));
  g->SetPoint(3, cart.first+0.5, cart.second+1./(2*sqrt(3)));
  g->SetPoint(4, cart.first+0.5, cart.second-1./(2*sqrt(3)));
  g->SetPoint(5, cart.first, cart.second-1./sqrt(3));
  g->SetPoint(6, cart.first-0.5, cart.second-1./(2*sqrt(3)));
  g->SetFillColor(color);
  return(g);
}

int
HexagonCoordinate::x() const{
  return(m_x);
}

int
HexagonCoordinate::y() const{
  return(m_y);
}

bool
HexagonCoordinate::operator==(HexagonCoordinate const& rhs) {
  return(x()==rhs.x() && y()==rhs.y());
}
