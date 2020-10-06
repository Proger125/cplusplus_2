#include "Iterator.h"
#include "Stack.h"
int main() {
  Stack<int> stack1{1, 2, 3, 4, 5};
  Stack<int> stack2{6, 7, 8, 9};
  stack1.Swap(stack2);
  ContainerIterator<int> *it1 = new ContainerIterator<int>(&stack1);
  ContainerIterator<int> *it2 = new ContainerIterator<int>(&stack2);
  for (it1->First(); !it1->IsDone(); it1->Next()) {
    cout << it1->currentItem().GetValue() << endl;
  }
  cout << endl;
  for (it2->First(); !it2->IsDone(); it2->Next()) {
    cout << it2->currentItem().GetValue() << endl;
  }
  stack2.Push(10);
  cout << stack2.Top().GetValue() << endl;
  system("pause");
  return 0;
}