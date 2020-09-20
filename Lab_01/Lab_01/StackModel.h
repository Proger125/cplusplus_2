#pragma once
#include "Observe.h"
#include "Stack.h"

template <typename T>
class StackModel : public Observable{
 private:
  Stack<T> *leftStack;
  Stack<T> *rightStack;
 public:
  void StackConstructor(int type);
  void StackPop(int type);
  void StackPush(int type, int element);
  int StackSize(int type);
  T StackTop(int type);
  void StacksSum();
  void StacksSwap();
  string ToString(int type);
  void StackClear(int type);
  bool StackIsEmpty(int type);
  int SumOfElements(int type);
};
template <typename T>
void StackModel<T>::StackConstructor(int type) {
  if (type == 0) {
    leftStack = new Stack<int>();
  } else {
    rightStack = new Stack<int>();
  }
}
template <typename T>
void StackModel<T>::StackClear(int type) {
  if (type == 0) {
    leftStack->Clear();
  } else {
    rightStack->Clear();
  }
  notifyUpdate(type);
}
template <typename T>
bool StackModel<T>::StackIsEmpty(int type) {
  if (type == 0) {
    return leftStack->IsEmpty();
  }
  return leftStack->IsEmpty();
}
template <typename T>
int StackModel<T>::StackSize(int type) {
  if (type == 0) {
    return leftStack->Size();
  }
  return rightStack->Size();
}
template <typename T>
T StackModel<T>::StackTop(int type) {
  if (type == 0) {
    return leftStack->Top();
  }
  return rightStack->Top();
}
template <typename T>
void StackModel<T>::StackPop(int type) {
  if (type == 0) {
    leftStack->Pop();
  } else {
    rightStack->Pop();
  }
  notifyUpdate(type);
}
template <typename T>
void StackModel<T>::StackPush(int type, int element) {
  if (type == 0) {
    leftStack->Push(element);
  } else {
    rightStack->Push(element);
  }
  notifyUpdate(type);
}
template <typename T>
string StackModel<T>::ToString(int type) {
  string result;
  StackIterator<int, Stack<int>> *it;
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
template <typename T>
void StackModel<T>::StacksSum() {
  *leftStack += *rightStack;
  notifyUpdate(0);
  notifyUpdate(1);
}
template <typename T>
void StackModel<T>::StacksSwap() {
  leftStack->Swap(*rightStack);
  notifyUpdate(0);
  notifyUpdate(1);
}
template <typename T>
int StackModel<T>::SumOfElements(int type) {
  SumVisitor<T, Stack<T>> visitor;
  if (type == 0) {
    leftStack->accept(visitor);
    return visitor.GetSum();
  }
  rightStack->accept(visitor);
  return visitor.GetSum();
}
