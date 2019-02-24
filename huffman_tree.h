#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include "binary_heap.h"

class HuffmanTree {
 public:
  HuffmanTree();
  ~HuffmanTree();

  void Insert(HuffmanNode* node);
  HuffmanNode* DeleteMin();

 private:
  BinaryHeap* heap_;  
};

#endif
