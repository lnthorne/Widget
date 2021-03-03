/*
* CPSC 2720 Fall 2018
* Copyright 2018 Dr. Anvik <john.anvik@uleth.ca>
*/

#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <Window.h>

/**
* This class provides a concrete implemenation for Window.
*/
class BaseWindow : public Window {
 public:
  BaseWindow(int w = 10, int h = 10): Window(w, h) {}

  virtual ~BaseWindow() {}

  /**
  * Method does nothing.
  */
  void draw(std::ostream& os) {}
};

#endif  // BASEWINDOW_H
