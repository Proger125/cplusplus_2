#include "Controller.h"
void Controller::StackConstructor(int type) {
  if (type == 0) {
    leftStack = new Stack<int>();
  }
  rightStack = new Stack<int>();
}
void Controller::StackClear(int type) {
  if (type == 0) {
    leftStack->Clear();
  }
  rightStack->Clear();
}
bool Controller::StackIsEmpty(int type) {
  if (type == 0) {
    return leftStack->IsEmpty();
  }
  return leftStack->IsEmpty();
}
int Controller::StackSize(int type) {
  if (type == 0) {
    return leftStack->Size();
  }
  return rightStack->Size();
}
int Controller::StackTop(int type) {
  if (type == 0) {
    return leftStack->Top();
  }
  return rightStack->Top();
}
void Controller::StackPop(int type) {
  if (type == 0) {
    leftStack->Pop();
  }
  rightStack->Pop();
}
void Controller::StackPush(int type, int element) {
  if (type == 0) {
    leftStack->Push(element);
  }
  rightStack->Push(element);
}
string Controller::ToString(int type) {
  string result;
  StackIterator<int, Stack<int> > *it;
  if (type == 0) {
    it = this->leftStack->createIterator();
  } else {
    it = this->rightStack->createIterator();
  }
  for (it->First(); !it->IsDone(); it->Next()) {
    string item = to_string(it->currentItem());
    result += item + " ";
  }
  return result;
}
void Controller::StacksSum() { *leftStack = *leftStack + *rightStack; }
void Controller::StacksSwap() { leftStack->Swap(*rightStack); }