/***

 Based on Professor Aaron Bloomfield's interface.

 See https://aaronbloomfield.github.io/pdr/slides/code/10-heaps-huffman/binary_heap.h.html

 C++ implementation is different.

***/

#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
using namespace std;

class BinaryHeap {
 public:
 // Default constructor
  BinaryHeap();
  BinaryHeap(vector<int> vec);

  ~BinaryHeap();
  
  // Methods
  void Insert(int x);
  int FindMin();
  int DeleteMin();
  void MakeEmpty();
  bool IsEmpty();
  void Print();

  // Getters
  unsigned int heap_size();
  vector<int> heap();

 private:
  vector<int> heap_;

  void PercolateUp(int hole);
  void PercolateDown(int hole);
};

#endif
