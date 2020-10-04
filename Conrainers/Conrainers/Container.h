#pragma once
#include "Element.h"
using namespace std;

template <typename T>
class Container {
 protected:
  Element<T>* data;
  int size;
  int capacity;

 public:
  Container();
  Container(Element<T>* arr, int size, int capacity);
  Container(const initializer_list<T>& list);
  Container(Container& container);
  Container(Container&& container);
  ~Container();
  virtual int Size();
  virtual bool IsEmpty();
  virtual void Clear();
  virtual Element<T> GetElement(int index);


  virtual bool operator==(const Container<T>& container);
  virtual bool operator!=(const Container<T>& container);

  virtual Container<T> operator=(const Container<T>& container);
  virtual Container<T> operator=(Container<T>&& container);

  virtual Container<T> operator+(const Container<T>& container);
  virtual Container<T> operator+=(const Container<T>& container);
};

template <typename T>
Container<T>::Container() {
  size = 0;
  capacity = 10;
  data = new Element<T>[capacity];
}
template <typename T>
Container<T>::Container(Element<T>* arr, int size, int capapcity) {
  data = arr;
  this->size = size;
  this->capacity = capacity;
}
template <typename T>
Container<T>::Container(const initializer_list<T>& list) {
  int i = 0;
  for (auto it = list.begin(); it != list.end(); it++) {
    i++;
  }
  this->size = i;
  this->capacity = this->size * 1.2;
  this->data = new Element<T>[this->size];
  i = 0;
  for (auto it = list.begin(); it != list.end(); it++) {
    data[i] = (*it);
    i++;
  }
}
template <typename T>
Container<T>::Container(Container& container) {
  size = container.size;
  capacity = container.capacity;
  this->data = new Element<T>[this->size];
  for (int i = 0; i < this->size; i++) {
    data[i] = container.data[i];
  }
}
template <typename T>
Container<T>::Container(Container&& container) {
  size = container.size;
  capacity = container.capacity;
  this->data = new Element<T>[this->size];
  for (int i = 0; i < this->size; i++) {
    data[i] = container.data[i];
  }
  container.data = nullptr;
  container.size = 0;
  container.capacity = 0;
}
template <typename T>
Container<T>::~Container() {
  delete[] data;
}
template <typename T>
int Container<T>::Size() {
  return this->size;
}
template <typename T>
bool Container<T>::IsEmpty() {
  if (size == 0) {
    return true;
  }
  return false;
}
template <typename T>
void Container<T>::Clear() {
  this->data = nullptr;
  this->size = 0;
  this->capacity = 0;
}
template <typename T>
Element<T> Container<T>::GetElement(int index) {
  return data[index];
}
template <typename T>
bool Container<T>::operator==(const Container<T>& container) {
  if (this->size != container.size) {
    return false;
  } else {
    for (int i = 0; i < this->size; i++) {
      if (this->data[i] != container.data[i]) {
        return false;
      }
    }
    return true;
  }
}
template <typename T>
bool Container<T>::operator!=(const Container<T>& container) {
  if (this->size != container.size) {
    return true;
  } else {
    for (int i = 0; i < size; i++) {
      if (this->data[i] != container.data[i]) {
        return true;
      }
    }
    return false;
  }
}
template <typename T>
Container<T> Container<T>::operator=(const Container<T>& container) {
  this->size = container.size;
  this->capacity = container.capacity;
  this->data = new Element<T>[this->size];
  for (int i = 0; i < this->size; i++) {
    data[i] = container.data[i];
  }
  return *this;
}
template <typename T>
Container<T> Container<T>::operator=(Container<T>&& container) {
  this->size = container.size;
  this->capacity = container.capacity;
  this->data = new Element<T>[this->size];
  for (int i = 0; i < this->size; i++) {
    data[i] = container.data[i];
  }
  container.data = nullptr;
  container.size = 0;
  container.capacity = 0;
  return *this;
}
template <typename T>
Container<T> Container<T>::operator+(const Container<T>& container) {
  Element<T>* arr = new Element<T>[this->size];
  int size = this->size;
  for (int i = 0; i < this->size; i++) {
    arr[i] = this->data[i];
  }
  this->size = this->size + container.size;
  this->capacity = this->capacity + container.capacity;
  this->data = new Element<T>[this->size];
  for (int i = 0; i < size; i++) {
    this->data[i] = arr[i];
  }
  for (int i = size; i < this->size; i++) {
    this->data[i] = container.data[i - size];
  }
  return *this;
}
template <typename T>
Container<T> Container<T>::operator+=(const Container<T>& container) {
  Element<T>* arr = new Element<T>[this->size];
  int size = this->size;
  for (int i = 0; i < this->size; i++) {
    arr[i] = this->data[i];
  }
  this->size = this->size + container.size;
  this->capacity = this->capacity + container.capacity;
  this->data = new Element<T>[this->size];
  for (int i = 0; i < size; i++) {
    this->data[i] = arr[i];
  }
  for (int i = size; i < this->size; i++) {
    this->data[i] = container.data[i - size];
  }
  return *this;
}