/*
* CPSC 2720 Fall 2018
* Copyright 2018 Dr. Anvik <john.anvik@uleth.ca>
*/

#ifndef ASCIIWINDOW_H
#define ASCIIWINDOW_H

#include <Window.h>
#include <iostream>


class AsciiWindow : public Window {
 public:
  AsciiWindow(int w, int h): Window(w, h) {}
  virtual ~AsciiWindow() {}

  /**
   Draws a representation of the window and its contents using ASCII symbols.
   An example of an empty 4x4 window is as follows:
   \verbatim
    +----+
    |    |
    |    |
    |    |
    |    |
    +----+
   \endverbatim
  */
  void draw(std::ostream& os);

private:
  char** Block; //specify where the element is
  char** allocatingMem();
  void dealocateMem(char**, unsigned int);
};

#endif  // ASCIIWINDOW_H
