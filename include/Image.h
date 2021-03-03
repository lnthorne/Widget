/*
* CPSC 2720 Fall 2018
* Copyright 2018 Dr. Anvik <john.anvik@uleth.ca>
*/

#ifndef IMAGE_H
#define IMAGE_H

#include <Widget.h>

class Image : public Widget {
 public:
  /**
  * Constructor of a image.
  */
  Image(Coordinate c, unsigned int w, unsigned int h) : Widget{c, w, h} {}

  virtual ~Image() {}

  /**
  * @return Returns 'I' as the representation of an image.
  * @throw widget_err if \a c is outside the bounds of the image, where \a c is relative to the image not the containing window.
  */
  char getAt(Coordinate c);
};

#endif  // IMAGE_H
