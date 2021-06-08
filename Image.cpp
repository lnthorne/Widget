/***************************************
* CPSC 2720 Assignment 2
* Date: 15/02/2021
* By: Liam Thorne
* Image implementation
****************************************/

#include <iostream>
#include "Exceptions.h"
#include "Coordinate.h"
#include "Widget.h"
#include "Image.h"


//getAt image function
//return "I"
char Image::getAt(Coordinate c) {
//check if coordinate is in the widget 
  checkOutOfBounds(c);

  return 'I';

}
