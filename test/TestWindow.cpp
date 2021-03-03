/***************************************
* CPSC 2720 Liam Thorne
* Assignment 01 Unit Testing
* Window class
***************************************/

#include <iostream>
#include <vector>
#include "Window.h"
#include "AsciiWindow.h"
#include "Image.h"
#include "Coordinate.h"
#include "Widget.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

//Testing constructor
TEST(TestWindow, constructor) {
  AsciiWindow win(10, 10);

  EXPECT_EQ(win.getWidth(), 10);
  EXPECT_EQ(win.getHeight(), 10);

  EXPECT_THROW(AsciiWindow win2(-1, -1), illegal_size_error);
  EXPECT_THROW(AsciiWindow win3(1025, 1025), illegal_size_error);
  EXPECT_NO_THROW(AsciiWindow win4(1024, 1024));
}

//Testing add widget
TEST(TestWindow, addWidgetFunc) {
  AsciiWindow win(10, 10);
  Widget* f1 = new Image(Coordinate(20, 0), 4, 4);
  Widget* f2 = new Image(Coordinate(1, 1), 4, 4);
  Widget* f3 = new Image(Coordinate(1, 1), 5, 12);

  EXPECT_THROW(win.addWidget(f1), widget_operation_failed_error);
  EXPECT_THROW(win.addWidget(f3), widget_operation_failed_error);
  EXPECT_NO_THROW(win.addWidget(f2));

  delete f1;
  delete f2;
  delete f3;
}

//Testing removeWidget
TEST(TestWindow, removeWidgetFunc) {
  AsciiWindow win(10, 10);
  Widget* f1 = new Image(Coordinate(20, 0), 4, 4);
  Widget* f2 = new Image(Coordinate(1, 1), 4, 4);

  win.addWidget(f2);
  EXPECT_THROW(win.removeWidget(f1), widget_operation_failed_error);
  EXPECT_NO_THROW(win.removeWidget(f2));

  delete f1;
  delete f2;
}

//Testing getWidgets
TEST(TestWindow, getWidgetsFunc) {
  AsciiWindow win(20, 20);
  Widget* f1 = new Image(Coordinate(10, 10), 4, 4);
  Widget* f2 = new Image(Coordinate(1, 1), 4, 4);
  std::vector<Widget*> wig;

  wig.push_back(f1);
  wig.push_back(f2);

  win.addWidget(f1);
  win.addWidget(f2);

  EXPECT_EQ(win.getWidgets(), wig);

  delete f1;
  delete f2;
}

//Testing reSize
TEST(TestWindow, resizeFunc) {
  AsciiWindow win(10, 10);
  Widget* f1 = new Image(Coordinate(3, 3), 4, 4);

  win.addWidget(f1);
  EXPECT_THROW(win.resize(1025, 1025), illegal_size_error);
  EXPECT_NO_THROW(win.resize(1024, 1024));
  EXPECT_NO_THROW(win.resize(20, 20));
  EXPECT_THROW(win.resize(2, 2), illegal_size_error);

  delete f1;
}
