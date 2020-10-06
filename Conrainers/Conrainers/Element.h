#pragma once
#include <iostream>
template <typename T>
class Element;

// Pattern Visitor
template <typename T>
class Visitor {
  virtual void visit(Element<T> element) = 0;
};
template <typename T>


class SumVisitor : public Visitor<T> {
 private:
  T sum;

 public:
  SumVisitor();
  T GetSum();
  virtual void visit(Element<T> element);
};
template <typename T>
SumVisitor<T>::SumVisitor() {
  sum = 0;
}
template <typename T>
T SumVisitor<T>::GetSum() {
  return this->sum;
}
template <typename T>
void SumVisitor<T>::visit(Element<T> element) {
  sum += element.GetValue();
}


template<typename T>
class Element {
 private:
  T value;

 public:
  Element();
  Element(T value);
  T GetValue();
  void SetValue(T value);
  void accept(SumVisitor<T>& visitor) { visitor.visit(*this);}


  bool operator==(const Element<T>& element);
  bool operator!=(const Element<T>& element);
  
  
  Element<T> operator=(const Element<T>& element);
};
template <typename T>
Element<T>::Element() {
  this->value = 0;
}
template <typename T>
Element<T>::Element(T value) {
  this->value = value;
}
template <typename T>
T Element<T>::GetValue() {
  return this->value;
}
template <typename T>
void Element<T>::SetValue(T value) {
  this->value = value;
}
template <typename T>
bool Element<T>::operator==(const Element<T>& element) {
  if (this->value == element.value) {
    return true;
  }
  return false;
}
template <typename T>
bool Element<T>::operator!=(const Element<T>& element) {
  if (this->value == element.value) {
    return false;
  }
  return true;
}
template<typename T>
Element<T> Element<T>::operator=(const Element<T>& element) {
  this->value = element.value;
  return *this;
}