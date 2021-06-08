/***************************************
* CPSC 2720 Assignment 2
* Date: 15/02/2021
* By: Liam Thorne
* Window implementation(super class)
****************************************/

#include <iostream>
#include <vector>
#include "Window.h"
#include "Widget.h"
#include "Coordinate.h"
#include "Exceptions.h"

//Constructor
//check max and mins
Window::Window(int w, int h) {
  setHeight(h);
  setWidth(w);
}



//Destructor
 Window::~Window() {}


//setHight function
void Window::setHeight(int h) {
  if (h > MAX_HEIGHT || h < 0)
    throw illegal_size_error("illegal size.");

  height = (unsigned int)h;
}



void Window::setWidth(int w) {
  if (w > MAX_WIDTH || w < 0)
    throw illegal_size_error("illegal size.");

  width = (unsigned int)w;
}


 //getWidth func
 //returns width of window
 unsigned int Window::getWidth() {
   return width;
 }



 //getHeight func
 //returns height
 unsigned int Window::getHeight() {
   return height;
 }


 //get the widgets in the window
 //return a vector with all the widgets
std::vector<Widget*> Window::getWidgets() {
  return contents;
}



 //addWidget func
 //check if widget can be placed
 void Window::addWidget(Widget* w) {
   //get coordinates, height and width of widget
   Coordinate loc = w->getLocation();
   unsigned int w1 = w->getWidth();
   unsigned int h1 = w->getHeight();

   //check if widget is in window
   if (loc.x > width || loc.y > height)
    throw widget_operation_failed_error("widget cannot be added");

    //check if widget will fit in window
    else if ((loc.x + w1) > width || (loc.y + h1) > height)
      throw widget_operation_failed_error("widget cannot be added");

    else
      contents.push_back (w);

}



//removeWidget funtion
//check if widget is in vector
void Window::removeWidget(Widget* w) {
  int count;

    //linear search for matching widget
    for(int i = 0; i < contents.size(); i++){
      count = i;
      if (contents[i] == w)
        contents.erase(contents.begin()+count);

      else
        throw widget_operation_failed_error("widget does not exist");
    }
}



//resize window
//throw if too big/small if cuts widget
void Window::resize(unsigned int w, unsigned int h) {
  int wid = w;
  int hei = h;
//check if w/h is legal
  setWidth(wid);
  setHeight(hei);
//check to make sure widget isnt cut
  for(auto& it: contents){
    Coordinate loc = it->getLocation();
    unsigned int w1 = it->getWidth();
    unsigned int h1 = it->getHeight();

    if ((loc.x + w1) > width || (loc.y + h1) > height)
      throw illegal_size_error("Cannot resize");
  }
}
