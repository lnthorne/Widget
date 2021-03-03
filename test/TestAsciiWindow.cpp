/*
* CPSC 2720 Fall 2018
* Copyright 2018 Dr. Anvik <john.anvik@uleth.ca>
*/

#include <iostream>
#include <fstream>
#include "AsciiWindow.h"
#include "Textbox.h"
#include "Image.h"
#include "gtest/gtest.h"

TEST(TestAsciiWindow, empty) {
  std::ofstream output("asciiWindow_empty.txt");
  if (output.is_open()) {
    Window* win = new AsciiWindow(10, 10);
    win->draw(output);
    delete win;
  }
  output.close();
}

TEST(TestAsciiWindow, widgets) {
  std::ofstream output("asciiWindow_widgets.txt");

  if (output.is_open()) {
    Window* win = new AsciiWindow(10, 10);

    Textbox* t = new Textbox(Coordinate(1, 1), 1, 7);
    t->setText("Textbox");
    win->addWidget(t);

    Image* i = new Image(Coordinate(5, 5), 4, 4);
    win->addWidget(i);

    win->draw(output);

    delete i;
    delete t;
    delete win;
  } else {
    std::cerr << "Problem writing to file" << std::endl;
  }
  output.close();
}

TEST(TestAsciiWindow, widgetsReverseAdd) {
  std::ofstream output("asciiWindow_widgets_reverse.txt");
  if (output.is_open()) {
    Window* win = new AsciiWindow(10, 10);

    Image* i = new Image(Coordinate(5, 5), 4, 4);
    win->addWidget(i);

    Textbox* t = new Textbox(Coordinate(1, 1), 1, 7);
    t->setText("Textbox");
    win->addWidget(t);

    win->draw(output);

    delete i;
    delete t;
    delete win;
  } else {
    std::cerr << "Problem writing to file" << std::endl;
  }
  output.close();
}

TEST(TestAsciiWindow, widgetOffset) {
  Window* win = new AsciiWindow(2, 2);

  Textbox* t = new Textbox(Coordinate(0, 0), 1, 1);
  t->setText("T");
  win->addWidget(t);

  Image* i = new Image(Coordinate(1, 1), 1, 1);
  win->addWidget(i);

  win->draw(std::cout);

  delete i;
  delete t;
  delete win;
}

TEST(TestAsciiWindow, widgetOffset2) {
  Window* win = new AsciiWindow(2, 2);


  Image* i = new Image(Coordinate(1, 1), 1, 1);
  win->addWidget(i);

  Textbox* t = new Textbox(Coordinate(0, 0), 1, 1);
  t->setText("T");
  win->addWidget(t);

  win->draw(std::cout);

  delete i;
  delete t;
  delete win;
}
