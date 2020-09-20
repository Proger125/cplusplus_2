#pragma once
#include "StackModel.h"
#include "Screen.h"

class Controller {
 private:
  StackModel<int> *model;
  Screen *screen;
 public:
  Controller(StackModel<int> *model, Screen* screen);
  void ButtonClick(int clickType);
};
