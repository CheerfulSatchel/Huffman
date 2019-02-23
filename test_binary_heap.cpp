#include <iostream>
#include "binary_heap.h"

int main() {
  BinaryHeap heap;

  HuffmanNode* nodeA = new HuffmanNode();

  heap.Insert(nodeA);

  heap.Print();

  cout << "The min is: " << heap.FindMin()->freq << endl;

  delete nodeA;
  
  return 0;
}
