#include "StackModel.h"
void StackModel::StackConstructor(int type) {
  if (type == 0) {
    leftStack = new Stack<int>();
  } else {
    rightStack = new Stack<int>();
  }
}
void StackModel::StackClear(int type) {
  if (type == 0) {
    leftStack->Clear();
  } else {
    rightStack->Clear();
  }
  notifyUpdate(type);
}
bool StackModel::StackIsEmpty(int type) {
  if (type == 0) {
    return leftStack->IsEmpty();
  }
  return leftStack->IsEmpty();
}
int StackModel::StackSize(int type) {
  if (type == 0) {
    return leftStack->Size();
  }
  return rightStack->Size();
}
int StackModel::StackTop(int type) {
  if (type == 0) {
    return leftStack->Top();
  }
  return rightStack->Top();
}
void StackModel::StackPop(int type) {
  if (type == 0) {
    leftStack->Pop();
  } else {
    rightStack->Pop();
  }
  notifyUpdate(type);
}
void StackModel::StackPush(int type, int element) {
  if (type == 0) {
    leftStack->Push(element);
  } else {
    rightStack->Push(element);
  }
  notifyUpdate(type);
}
string StackModel::ToString(int type) {
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
void StackModel::StacksSum() {
  *leftStack += *rightStack;
  notifyUpdate(0);
  notifyUpdate(1);
}
void StackModel::StacksSwap() {
  leftStack->Swap(*rightStack);
  notifyUpdate(0);
  notifyUpdate(1);
}