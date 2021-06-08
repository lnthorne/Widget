/***************************************
* CPSC 2720 Assignment 2
* Date: 15/02/2021
* By: Liam Thorne
* Coordinate implementation
****************************************/

#include <iostream>
#include "Coordinate.h"

bool Coordinate::operator == (const Coordinate& c) const {
  if (x == c.x && y == c.y)
    return true;

  return false;
}

bool Coordinate::operator != (const Coordinate& c) const {
  if (x != c.x || y != c.y)
    return true;

  return false;
}

std::ostream& operator << (std::ostream& os, const Coordinate& c) {
  os << "[" << c.x << "," << c.y << "]";
  return os;
}
