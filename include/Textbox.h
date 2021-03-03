/*
* CPSC 2720 Fall 2018
* Copyright 2018 Dr. Anvik <john.anvik@uleth.ca>
*/

#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <Widget.h>
#include <string>
#include "Exceptions.h"

class Textbox : public Widget {
 public:
  /**
  * Constructor of a textbox.
  */
  Textbox(Coordinate c, unsigned int w, unsigned int h): Widget{c, w, h}
   {contents = nullptr;}

  virtual ~Textbox();

  /**
  * @return The letter of the string at \a c, or a space. Note that \a c is relative to the widget, not the containing window.
  * @throw widget_err if \a c is outside the bounds of the textbox, where \a c is relative to the textbox not the containing window.
  */
  char getAt(Coordinate c);

  /**
  * Set the string of the textbox
  * @throw widget_error Thrown if the text cannot fit in the textbox.
  */
  void setText(const std::string s);

 private:
  char** contents;
};

#endif  // TEXTBOX_H
