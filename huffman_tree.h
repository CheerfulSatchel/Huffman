#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include "binary_tree.h"

class HuffmanTree {
 public:
  HuffmanTree();
  ~HuffmanTree();

  void Insert(HuffmanNode* node);
  HuffmanNode* DeleteMin();

 private:
  BinaryHeap* heap_;  
}

#endif HUFFMAN_TREE_H
