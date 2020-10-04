#pragma once
#include "Container.h"

// Pattern Iterator

template <typename T>
class Iterator {
  virtual void First() = 0;
  virtual void Next() = 0;
  virtual bool IsDone() = 0;
  virtual Element<T> currentItem() = 0;
};


template <typename T>
class ContainerIterator : public Iterator<T> {
 private:
  Container<T>* container;
  int index;

 public:
  ContainerIterator(Container<T>* container);
  virtual void First();
  virtual void Next();
  virtual bool IsDone();
  virtual Element<T> currentItem();
};
template <typename T>
ContainerIterator<T>::ContainerIterator(Container<T>* container) {
  this->container = container;
  this->index = 0;
}
template <typename T>
void ContainerIterator<T>::First() {
  this->index = 0;
}
template <typename T>
void ContainerIterator<T>::Next() {
  this->index++;
}
template <typename T>
bool ContainerIterator<T>::IsDone() {
  return index == container->Size();
}
template <typename T>
Element<T> ContainerIterator<T>::currentItem() {
  return container->GetElement(index);
}