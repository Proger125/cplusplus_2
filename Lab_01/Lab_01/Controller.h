#pragma once
#include "Stack.h"
class Controller {
 private:
  Stack<int> *leftStack;
  Stack<int> *rightStack;

 public:
  void StackConstructor(int type);
  void StackClear(int type);
  bool StackIsEmpty(int type);
  int StackSize(int type);
  int StackTop(int type);
  void StackPop(int type);
  void StackPush(int type, int element);
  string ToString(int type);
  void StacksSum();
  void StacksSwap();
};
