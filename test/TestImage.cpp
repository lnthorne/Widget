/***************************************
* CPSC 2720 Liam Thorne
* Assignment 01 Unit Testing
* Image class
***************************************/

#include <iostream>
#include "Image.h"
#include "Coordinate.h"
#include "gtest/gtest.h"
#include "Exceptions.h"

//Testing default constructor
//Construct image and then call a widget function
//Expecting i1Width = 1, i1Height = 1, i2Throw error
TEST(TestImage, constructor) {
  Coordinate f1;
  Image i1(f1, 4, 1);

  EXPECT_THROW(Image i2(f1, 0, 0), illegal_size_error);
  EXPECT_EQ(i1.getHeight(), 1);
  EXPECT_EQ(i1.getWidth(), 4);
}


//Testing getAt function
//Construct Image then call getAt
//Expecting 'I'
TEST(TestImage, getAtTest) {
  Coordinate f1;
  Image i1(f1, 1, 1);

  EXPECT_EQ(i1.getAt(f1), 'I');
  EXPECT_THROW(i1.getAt(Coordinate(10, 10)), widget_error);
}
//Testing locatedAt func
//Expecting True, False
TEST(TestImage, locatedAtFunc) {
  Coordinate f1(1, 1);
  Image i1(f1, 4, 4);

  EXPECT_TRUE(i1.locatedAt(f1));
  EXPECT_FALSE(i1.locatedAt(Coordinate(10, 10)));
}

//Testing getLocation func
//Expecting location x = 1, y = 1
TEST(TestImage, getLocationFunc) {
  Coordinate f1(2, 1);
  Image i1(f1, 4, 4);

  EXPECT_EQ(i1.getLocation(), f1);
  EXPECT_NE(i1.getLocation(), Coordinate(5, 5));
}
