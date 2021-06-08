/***************************************
* CPSC 2720 Assignment 2
* Date: 15/02/2021
* By: Liam Thorne
* Widget implementation(super class)
****************************************/

#include <iostream>
#include "Widget.h"
#include "Coordinate.h"
#include "Exceptions.h"

Widget::Widget(Coordinate c, unsigned int w, unsigned int h): width {w}, height {h}, location {c} {
  if (width == 0 || height == 0)
    throw illegal_size_error("illegal size");
}

//get width of widget
unsigned int Widget::getWidth() {
  return width;
}

//get height of widget
unsigned int Widget::getHeight() {
  return height;
}

//get location of widget
Coordinate Widget::getLocation() {
  return location;
}

bool Widget::locatedAt(Coordinate c) {
  if (location.x == c.x && location.y == c.y)
    return true;

  return false;
}

//check if coordinates are in widget
void Widget::checkOutOfBounds(Coordinate c) {

  if (c.x < location.x || c.x >= (location.x + width))
    throw widget_error("No widget here 1");

  else if (c.y < location.y || c.y >= (location.y + height))
    throw widget_error("No widget here 2");
}
