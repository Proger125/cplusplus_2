#pragma once
#include "Container.h"
template <typename T>
class Stack : public Container<T>{
 public:
  Stack();
  Stack(Element<T>* arr, int size, int capacity);
  Stack(const initializer_list<T>& list);
  Stack(const Stack<T>& stack);
  Stack(Stack<T>&& stack);
  Element<T> Top();
  Element<T> Pop();
  void Push(T element);
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
  this->data = new Element<T>[this->capacity];
  for (int i = 0; i < this->size; i++) {
    this->data[i] = stack.data[i];
  }
}
template <typename T>
Stack<T>::Stack(Stack<T>&& stack) {
  this->size = stack.size;
  this->capacity = stack.capacity;
  this->data = new Element<T>[this->capacity];
  for (int i = 0; i < this->size; i++) {
    this->data[i] = stack.data[i];
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
  this->data = new Element<T>[this->capacity];
  i = 0;
  for (auto it = list.begin(); it != list.end(); it++) {
    this->data[i] = (*it);
    i++;
  }
}
template <typename T>
Element<T> Stack<T>::Top() {
  if (this->size > 0)
  return this->data[this->size - 1];
  Element<T> element(0);
  return element;
}
template <typename T>
Element<T> Stack<T>::Pop() {
  if (this->size > 0) {
    Stack<T> container;
    for (int i = 0; i < this->size; i++) {
      container.data[i] = this->data[i];
    }
    Element<T> element = container.data[this->size - 1];
    this->size = this->size - 1;
    this->data = new Element<T>[this->size];
    for (int i = 0; i < this->size; i++) {
      this->data[i] = container.data[i];
    }
    return element;
  }
  Element<T> element(0);
  return element;
}
template <typename T>
void Stack<T>::Push(T element) {
  if (this->size == this->capacity) {
    Stack<T> container;
    container.size = this->size;
    container.capacity = this->capacity;
    container.data = new Element<T>[container.capacity];
    for (int i = 0; i < this->size; i++) {
      container.data[i] = this->data[i];
    }
    this->capacity *= 1.3;
    this->data = new Element<T>[this->capacity];
    for (int i = 0; i < this->size; i++) {
      this->data[i] = container.data[i];
    }
    this->data[this->size] = element;
    this->size++;
  } else {
    this->data[this->size] = element;
    this->size++;
  }
}