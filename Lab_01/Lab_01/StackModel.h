#pragma once
#include "Stack.h"
#include "Observe.h"

class StackModel : public Observable{
 private:
  Stack<int> *leftStack;
  Stack<int> *rightStack;

 public:
  void StackConstructor(int type);
  void StackPop(int type);
  void StackPush(int type, int element);
  int StackSize(int type);
  int StackTop(int type);
  void StacksSum();
  void StacksSwap();
  string ToString(int type);
  void StackClear(int type);
  bool StackIsEmpty(int type);
};
