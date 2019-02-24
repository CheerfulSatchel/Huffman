#include <iostream>
#include "binary_heap.h"

int main() {
  BinaryHeap heap;

  HuffmanNode* nodeA = new HuffmanNode(2, 'd');
  HuffmanNode* nodeB = new HuffmanNode(1, 'b');
  HuffmanNode* nodeC = new HuffmanNode(3, 'a');
  HuffmanNode* nodeD = new HuffmanNode(1, 'c');

  heap.Insert(nodeA);
  heap.Insert(nodeB);
  heap.Insert(nodeC);
  heap.Insert(nodeD);

  heap.Print();

  cout << "The min is: " << heap.FindMin()->freq << endl;

  delete nodeA;
  delete nodeB;
  delete nodeC;
  delete nodeD;
  
  return 0;
}
