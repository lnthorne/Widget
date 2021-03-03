/*
* CPSC 2720 Fall 2018
* Copyright 2018 Dr. Anvik <john.anvik@uleth.ca>
*/

#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>

/**
  * Representation of a two-dimensional Cartisian coordinate.
  */
class Coordinate {
 public:
  Coordinate(unsigned int x = 0, unsigned int y = 0) :x{x}, y{y} {}
  virtual ~Coordinate() {}

  /**
  * @return true if the x and y values of c are the same as those of the object, false otherwise.
  */
  bool operator==(const Coordinate& c) const;

  /**
  * @return true if the x or y values of c are different from those of the object, false otherwise.
  */
  bool operator!=(const Coordinate& c) const;

  /**
  * @return an output stream containing a representation of the coordinate in "[x,y]" format.
  */
  friend std::ostream& operator<<(std::ostream& os, const Coordinate& c);

  /** The x-coordinate */
  const unsigned int x;

  /** The y-coordinate */
  const unsigned int y;
};

#endif  // COORDINATE_H
