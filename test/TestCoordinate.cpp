/***************************************
* CPSC 2720 Liam Thorne
* Assignment 01 Unit Testing
* Coordinate class
***************************************/

#include <iostream>
#include <sstream>
#include "Coordinate.h"
#include "gtest/gtest.h"

//Testing constructor
//Expecting 0,0
//check
TEST(TestCoordinate, constructor) {
  Coordinate f1;
  Coordinate f2(3, 2);

  EXPECT_EQ(f1.x, 0);
  EXPECT_EQ(f1.y, 0);
  EXPECT_EQ(f2.x, 3);
  EXPECT_EQ(f2.y, 2);
}

//Testing != operator
//Expecting false
TEST(TestCoordinate, notEqual) {
  Coordinate f1;
  Coordinate f2;
  Coordinate f3(2, 1);


  EXPECT_FALSE(f1 != f2);
  EXPECT_TRUE(f3 != f1);
}

//Testing == operator
//Expecting true
TEST(TestCoordinate, equal) {
  Coordinate f1;
  Coordinate f2;
  Coordinate f3(5, 6);

  EXPECT_TRUE(f1 == f2);
  EXPECT_FALSE(f1 == f3);
}

//Testing the ostream
//Expecting "[0,0]"
TEST(TestCoordinate, Ostream) {
  std::ostringstream ss;
  Coordinate f1;
  Coordinate f2(2, 3);

  ss << f1;
  EXPECT_EQ("[0,0]", ss.str());
  ss.str("");

  ss << f2;
  EXPECT_EQ("[2,3]", ss.str());
}
