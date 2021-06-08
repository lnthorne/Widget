/***************************************
* CPSC 2720 Assignment 2
* Date: 15/02/2021
* By: Liam Thorne
* AsciiWindow implementation
****************************************/

#include <iostream>
#include "Widget.h"
#include "Window.h"
#include "Coordinate.h"
#include "AsciiWindow.h"


char** AsciiWindow::allocatingMem() {
  char** temp;

  unsigned int height = getHeight();
  unsigned int width = getWidth();

  temp = new char* [height];
  for(int i = 0; i < height; i++){
    temp[i] = new char [width];
    for(int j = 0; j < width; j++){
      temp[i][j] = ' ';
    }
  }
  return temp;
}



void AsciiWindow::dealocateMem(char** M, unsigned int h) {

  //dealocate mem
  for(int i = 0; i < h; i++){
    delete[] M[i];
    }
  delete[] M;
  M = nullptr;
}



void AsciiWindow::draw(std::ostream& os) {
//getting width and height of the window and vector of widgets in window
  unsigned int height = getHeight();
  unsigned int width = getWidth();
  std::vector<Widget*> contents = getWidgets();

  //allocating implementation
  Block = allocatingMem();


//adding borders
  for(int i = 0; i < height; i++){
    Block[i][0] = '|';
    Block[i][width - 1] = '|';
    for(int j = 0; j < width; j++){
      Block[0][j] = '-';
      Block[height - 1][j] = '-';
    }
  }


  //adding widgets
  if(!contents.empty()) {
  for(auto& it: contents) {//getting the widgets specs from vector
    Coordinate loc = it->getLocation();
    unsigned int w1 = it->getWidth();
    unsigned int h1 = it->getHeight();

    for(int i = loc.y; i < (loc.y + h1); i++){
      for(int j = loc.x; j < (loc.x + w1); j++){
        Coordinate counter(j, i);//coordinates for where to place widget char
        Block[i][j] = it->getAt(counter);
      }
    }
  }
}

//outputting
  for(int i = 0; i < height; i++){
       for(int j = 0; j < width; j++){
           os<< Block[i][j];
       }
       os<< std::endl;
   }

   dealocateMem(Block, height);
}
