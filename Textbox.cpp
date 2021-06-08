/***************************************
* CPSC 2720 Assignment 2
* Date: 15/02/2021
* By: Liam Thorne
* Textbox implementation
****************************************/

#include <string>
#include "Exceptions.h"
#include "Widget.h"
#include "Textbox.h"

//destructor
Textbox::~Textbox() {
  if (contents != nullptr){
    //dealocate mem
    for(int i = 0; i < height; i++){
      delete[] contents[i];
      }
    delete[] contents;
    contents = nullptr;
  }

}

char Textbox::getAt(Coordinate c) {
  //check if the coordinate is within the widget 
    checkOutOfBounds(c);

    return contents[location.y][location.x];
}



void Textbox::setText(const std::string s) {

  if (s.size() > (width * height))
    throw widget_error("String too big");

  int k = 0;
    //storing the string
    contents = new char* [height];
     for(int i = 0; i < height; i++){
       contents[i] = new char [width];
       for(int j = 0; j < width; j++){
         if (k < s.size())
           contents[i][j] = s[k];
          else
            contents[i][j] = ' ';
          k++;
       }
     }
}
