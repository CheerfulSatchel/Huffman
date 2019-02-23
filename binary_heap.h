/***

 Based on Professor Aaron Bloomfield's interface.

 See https://aaronbloomfield.github.io/pdr/slides/code/10-heaps-huffman/binary_heap.h.html

 C++ implementation is different.

***/

#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
#include "huffman_node.h"

using namespace std;

class BinaryHeap {
 public:
 // Default constructor
  BinaryHeap();
  BinaryHeap(vector<HuffmanNode*> vec);

  ~BinaryHeap();
  
  // Methods
  void Insert(HuffmanNode* node);
  HuffmanNode* FindMin();
  HuffmanNode* DeleteMin();
  void MakeEmpty();
  bool IsEmpty();
  void Print();

  // Getters
  unsigned int heap_size();
  vector<HuffmanNode*> heap();

 private:
  vector<HuffmanNode*> heap_;

  void PercolateUp(int hole);
  void PercolateDown(int hole);
};

#endif
