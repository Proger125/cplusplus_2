#pragma once
#include <iostream>
#include <istream>
#include <ostream>
#include <string>

using namespace std;

template <typename T, typename Q>
class Iterator {
 public:
  Iterator(Q* list1) { list = list1; }
  void First() { index = 0; }
  void Next() { ++index; }
  bool IsDone() { return index == list->size; }
  T currentItem() { return list->array[index]; }

 private:
  Q* list;
  int index;
};

template <typename T>
class MyList {
  friend class Iterator<T, MyList>;

 public:
  MyList();               // has done
  MyList(MyList& list);   // has done, copy constructor
  MyList(MyList&& list);  // has done, move constructor
  MyList(
      const initializer_list<T>& list);  // has done, constructor based on list
  MyList(const int size_);               // has done
  ~MyList();                             // has done
  Iterator<T, MyList>* createIterator() {
    return new Iterator<T, MyList>(this);
  }

  friend ostream& operator<<(ostream& out, MyList<T>& list) {
    Iterator<T, MyList<T>>* it = list.createIterator();
    for (it->First(); !it->IsDone(); it->Next()) {
      out << it->currentItem() << " ";
    }
    delete it;
    return out;
  }

  friend istream& operator>>(istream& in, MyList& list) {
    for (int i = 0; i < list.capacity; i++) {
      in >> list.array[i];
    }
    list.size = list.capacity;
    return in;
  }

  bool operator!=(MyList& list);  // has done
  bool operator==(MyList& list);  // has done

  MyList& operator+(MyList& list);   // has done
  MyList& operator+=(MyList& list);  // has done
  MyList& operator=(MyList& list);   // has done
  MyList& operator=(MyList&& list);  // has done

  bool isEmpty();                    // has done
  int Size();                        // has done
  void Clear();                      // has done
  T Front();                         // has done
  T Back();                          // has done
  void PushFront(const T& element);  // has done
  void PushBack(const T& element);   // has done
  void PopFront();                   // has done
  void PopBack();                    // has done
  void Swap(MyList& list);           // has dones

 private:
  T* array;
  int capacity;
  int size;
};

template <typename T>
MyList<T>::MyList() {
  capacity = 10;
  size = 0;
  array = new T[capacity];
}

template <typename T>
MyList<T>::MyList(MyList& list) {
  if (list.size > size) {
    delete[] array;
    capacity = list.capacity;
    size = list.size;
    array = new T[capacity];
  }
  Iterator<T, MyList>* it = list.createIterator();
  int i = 0;
  for (it->First(); !it->IsDone(); it->Next()) {
    array[i] = it->currentItem();
    i++;
  }
  delete it;
}

template <typename T>
MyList<T>::MyList(MyList&& list) {
  if (list.size_ > size) {
    delete[] array;
    capacity = list.capacity;
    size = list.size;
    array = new T[capacity];
  }
  Iterator<T, MyList>* it = list.createIterator();
  int i = 0;
  for (it->First(); !it->IsDone(); it->Next()) {
    array[i] = it->currentItem();
    i++;
  }
  delete it;
  while (list.size() > 0) {
    list.PopBack();
  }
}
template <typename T>
MyList<T>::MyList(const int size_) {
  array = new T[size_];
  capacity = size_;
  size = 0;
}
template <typename T>
MyList<T>::MyList(const initializer_list<T>& list) {
  size = 0;
  capacity = 10;
  array = new T[capacity];
  for (auto it = list.begin(); it != list.end(); it++) {
    this->PushBack(*it);
  }
}
template <typename T>
MyList<T>::~MyList() {
  delete[] array;
}

template <typename T>
bool MyList<T>::isEmpty() {
  if (size == 0) {
    return 0;
  }
  return 1;
}

template <typename T>
int MyList<T>::Size() {
  return size;
}

template <typename T>
void MyList<T>::Clear() {
  while (!isEmpty()) {
    PopBack();
  }
}

template <typename T>
T MyList<T>::Front() {
  return array[0];
}

template <typename T>
T MyList<T>::Back() {
  return array[size - 1];
}

template <typename T>
void MyList<T>::PushFront(const T& element) {
  if (size == capacity) {
    capacity *= 2;
    T* new_array = new T[capacity];
    for (int i = 0; i < size; ++i) {
      new_array[i] = array[i];
    }
    delete[] array;
    array = new T[capacity];
    for (int i = 0; i < size; ++i) {
      array[i + 1] = new_array[i];
    }
    array[0] = element;
    ++size;
  } else {
    for (int i = size - 1; i >= 0; --i) {
      array[i + 1] = array[i];
    }
    array[0] = element;
    ++size;
  }
}

template <typename T>
void MyList<T>::PushBack(const T& element) {
  if (size == capacity) {
    capacity *= 2;
    T* new_array = new T[capacity];
    for (int i = 0; i < size; ++i) {
      new_array[i] = array[i];
    }
    delete[] array;
    array = new T[capacity];
    for (int i = 0; i < size; ++i) {
      array[i] = new_array[i];
    }
    delete[] new_array;
    array[size] = element;
    ++size;
  } else {
    array[size] = element;
    ++size;
  }
}

template <typename T>
void MyList<T>::PopFront() {
  capacity += 1;
  T* new_array = new T[capacity];
  for (int i = 0; i < size; ++i) {
    new_array[i] = array[i + 1];
  }
  delete[] array;
  array = new T[capacity];
  for (int i = 0; i < size; ++i) {
    array[i] = new_array[i];
  }
  --size;
}

template <typename T>
void MyList<T>::PopBack() {
  capacity += 1;
  T* new_array = new T[capacity];
  for (int i = 0; i < size - 1; ++i) {
    new_array[i] = array[i];
  }
  delete[] array;
  array = new T[capacity];
  for (int i = 0; i < size; ++i) {
    array[i] = new_array[i];
  }
  --size;
}

template <typename T>
void MyList<T>::Swap(MyList<T>& list) {
  MyList<T> tmp = list;
  list.Clear();
  Iterator<T, MyList>* it = this->createIterator();
  for (it->First(); !it->IsDone(); it->Next()) {
    list.PushBack(it->currentItem());
  }
  this->Clear();
  it = tmp.createIterator();
  for (it->First(); !it->IsDone(); it->Next()) {
    this->PushBack(it->currentItem());
  }
}

template <typename T>
bool MyList<T>::operator==(MyList<T>& list) {
  Iterator<T, MyList>* it1 = this->createIterator();
  Iterator<T, MyList>* it2 = list.createIterator();
  for (it1->First(), it2->First(); !it1->IsDone(); it1->Next(), it2->Next()) {
    if (it1->currentItem() != it2->currentItem()) {
      break;
    }
  }
  bool answer = it1->IsDone() && it2->IsDone();
  delete it1;
  delete it2;
  return answer;
}

template <typename T>
bool MyList<T>::operator!=(MyList& list) {
  if (*this == list) {
    return false;
  }
  return true;
}

template <typename T>
MyList<T>& MyList<T>::operator+(MyList& list) {
  Iterator<T, MyList>* it = list.createIterator();
  for (it->First(); !it->IsDone(); it->Next()) {
    this->PushBack(it->currentItem());
  }
  delete it;
  return *this;
}

template <typename T>
MyList<T>& MyList<T>::operator+=(MyList& list) {
  Iterator<T, MyList>* it = list.createIterator();
  for (it->First(); !it->IsDone(); it->Next()) {
    this->PushBack(it->currentItem());
  }
  delete it;
  return *this;
}

template <typename T>
MyList<T>& MyList<T>::operator=(MyList& list) {
  if (list.size > size) {
    delete[] array;
    capacity = list.capacity;
    size = list.size;
    array = new T[capacity];
  }
  Iterator<T, MyList>* it = list.createIterator();
  int i = 0;
  for (it->First(); !it->IsDone(); it->Next()) {
    array[i] = it->currentItem();
  }
  delete it;
  return *this;
}

template <typename T>
MyList<T>& MyList<T>::operator=(MyList&& list) {
  if (list.size > size) {
    delete[] array;
    capacity = list.capacity;
    size = list.size;
    array = new T[capacity];
  }
  Iterator<T, MyList>* it = list.createIterator();
  int i = 0;
  for (it->First(); !it->IsDone(); it->Next()) {
    array[i] = it->currentItem();
  }
  while (!list.isEmpty()) {
    list.PopBack();
  }
  delete it;
  return *this;
}
