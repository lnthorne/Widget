/*
* CPSC 2720 Fall 2018
* Copyright 2018 Dr. Anvik <john.anvik@uleth.ca>
*/

#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include "Widget.h"
#include "Coordinate.h"
#include <vector>

class Window {
 public:
  static const int MAX_WIDTH = 1024;
  static const int MAX_HEIGHT = 1024;

  /**
   * A GUI window.
   * @param w The width of the window (default: 100).
   * @param h The height of the window (default: 100).
   * @throw illegal_size_error Thrown if the width or height is not a positive value or exceeds the maximum values.
   */
   Window(int w = 100, int h = 100);

  /**
  * Destructor for window
  */
  virtual ~Window();

  /**
   * Add a widget to the window
   * @param w the widget to add
   * @exception widget_operation_failed_error Thrown if \a w cannot be placed
   */

  void addWidget(Widget* w);

  /**
  * Remove a widget from the window
  * @param w the widget to removed
  * @exception widget_operation_failed_error Thrown if \a w cannot be removed
  */
  void removeWidget(Widget* w);

  /**
  * @return The width of the window.
  */
  unsigned int getWidth();

  /**
  * @return The height of the window.
  */
  unsigned int getHeight();

  /**
  * @return The widgets in the window.
  */
  std::vector<Widget*> getWidgets();

  /**
  * Resize the window.
  * @throw illegal_size_error Thrown if the new window size will exceed either the maximum width or height
  * or if resizing the window will cutoff a widget.
  */
  void resize(unsigned int w, unsigned int h);

  /**
  * Draw the window.
  */
  virtual void draw(std::ostream& os) = 0;

 private:
  /**
  * Set the height of the window.
  * @param h The new height of the window.
  * @throw illegal_size_error Thrown if the height is not a positive value or exceeds the maximum height.
  */
  void setHeight(int h);

  /**
  * Set the width of the window.
  * @param w The new width of the window.
  * @throw illegal_size_error Thrown if the width is not a positive value or exceeds the maximum width.
  */
  void setWidth(int w);

  /**
  * Width of the window
  */
  unsigned int width;

  /**
  * Height of the window
  */
  unsigned int height;

  /**
  * The widgets in the window
  */
  std::vector<Widget*> contents;


};


#endif // WINDOW_H_INCLUDED
