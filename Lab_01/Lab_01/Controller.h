#pragma once
#include "StackModel.h"
#include "Screen.h"

class Controller {
 private:
  StackModel *model;
  Screen *screen;
 public:
  Controller(StackModel *model, Screen* screen);
  void ButtonClick(int clickType);
};
