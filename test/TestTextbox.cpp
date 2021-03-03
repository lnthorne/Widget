/***************************************
* CPSC 2720 Liam Thorne
* Assignment 01 Unit Testing
* Textbox class
***************************************/
#include <iostream>
#include "Textbox.h"
#include "Coordinate.h"
#include "Exceptions.h"
#include "gtest/gtest.h"

//Testing default constructor
//Construct Textbox and then call a widget function
//Expected Width = 2, Height = 2
TEST(TestTextbox, constructor) {
  Coordinate f1;
  Textbox t1(f1, 2, 2);

  EXPECT_THROW(Textbox t2(f1, 0, 0), illegal_size_error);
  EXPECT_EQ(t1.getWidth(), 2);
  EXPECT_EQ(t1.getHeight(), 2);
}

//Testing setText function
TEST(TestTextbox, setText) {
  Coordinate f1(1, 1);
  Textbox t1(f1, 1, 4);

  EXPECT_NO_THROW(t1.setText("Liam"));
  EXPECT_THROW(t1.setText("Hello my name is"), widget_error);
}

//Testing getAt function
TEST(TestTextbox, getAt) {
  Coordinate f1(0, 0);
  Textbox t1(f1, 2, 7);
  Textbox t2(f1, 1, 7);
  Textbox t3(f1, 1, 1);

  t1.setText("Textbox");
  EXPECT_EQ(t1.getAt(Coordinate(0, 0)), 'T');
  EXPECT_THROW(t1.getAt(Coordinate(3, 3)), widget_error);

  t2.setText("Textbox");
  EXPECT_EQ(t2.getAt(f1), 'T');

  t3.setText(" ");
  EXPECT_EQ(t3.getAt(f1), ' ');
}

TEST(TestTextbox, locatedAtFunc) {
  Coordinate f1(1, 1);
  Textbox t1(f1, 1, 7);

  EXPECT_TRUE(t1.locatedAt(f1));
  EXPECT_FALSE(t1.locatedAt(Coordinate(4, 4)));
}

TEST(TestTextbox, getLocationFunc) {
  Coordinate f1(2, 1);
  Textbox t1(f1, 1, 7);

  EXPECT_EQ(t1.getLocation(), f1);
}
