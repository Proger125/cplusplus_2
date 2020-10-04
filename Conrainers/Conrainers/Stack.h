#pragma once
#include "Container.h"
template <typename T>
class Stack : public Container<T>{
 public:
  Stack();
  Stack(Element<T> *arr, int size, int capacity);
  Stack(const initializer_list<T>& list);
  Stack(const Stack<T>& stack);
  Stack(Stack<T>&& stack);
  Stack(Stack<T>& stack);
};
template <typename T>
Stack<T>::Stack() {
  this->capacity = 10;
  this->size = 0;
  this->data = new Element<T>[this->capacity];
}
template <typename T>
Stack<T>::Stack(Element<T> *arr, int size, int capacity) {
  this->data = arr;
  this->size = size;
  this->capacity = capacity;
}
template <typename T>
Stack<T>::Stack(const Stack<T>& stack) {
  this->size = stack.size;
  this->capacity = stack.capacity;
  this->data = new Element<T>[this->size];
  for (int i = 0; i < this->size; i++) {
    data[i] = stack.data[i];
  }
}
template <typename T>
Stack<T>::Stack(Stack<T>&& stack) {
  this->size = stack.size;
  this->capacity = stack.capacity;
  this->data = new Element<T>[this->size];
  for (int i = 0; i < this->size; i++) {
    data[i] = stack.data[i];
  }
  stack.data = nullptr;
  stack.size = 0;
  stack.capacity = 0;
}
template <typename T>
Stack<T>::Stack(const initializer_list<T>& list) {
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