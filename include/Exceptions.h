/*
* CPSC 2720 Fall 2018
* Copyright 2018 Dr. Anvik <john.anvik@uleth.ca>
*/

#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <stdexcept>

/**
* Exception for a window size greater than the maximum allowed
* or changing the size will cutoff a widget.
*/
class illegal_size_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit illegal_size_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* Exception for when an operation on a widget fails.
*/
class widget_operation_failed_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit widget_operation_failed_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* Exception for when there is a problem with a widget.
*/
class widget_error: public std::runtime_error {
 public:
  /**
  * @param errMessage An error message.
  */
  explicit widget_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

#endif  // EXCEPTIONS_H_INCLUDED
