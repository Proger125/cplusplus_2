#pragma once
#include <vector>

using namespace std;

class Observer {
 public:
  virtual void update(int type) = 0;
};
class Observable {
 public:
  void addObserver(Observer* observer) { observers.push_back(observer); }
  void notifyUpdate(int type) {
    int size = observers.size();
    for (int i = 0; i < size; i++) {
      observers[i]->update(type);
    }
  }

 private:
  vector<Observer*> observers;
};