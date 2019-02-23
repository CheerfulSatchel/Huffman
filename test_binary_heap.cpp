#include <iostream>
#include "binary_heap.h"

int main() {
  BinaryHeap heap;

  HuffmanNode* nodeA = new HuffmanNode(2, 'a');
  HuffmanNode* nodeB = new HuffmanNode(1, 'b');

  heap.Insert(nodeA);
  heap.Insert(nodeB);

  heap.Print();

  cout << "The min is: " << heap.FindMin()->freq << endl;

  delete nodeA;
  delete nodeB;
  
  return 0;
}
