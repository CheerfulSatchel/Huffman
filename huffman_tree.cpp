#include "huffman_tree.h"

HuffmanTree::HuffmanTree() {
  heap_ = new BinaryHeap();
}

HuffmanTree::~HuffmanTree() {
  delete heap_;
}

void HuffmanTree::Insert(HuffmanNode* node) {
  heap_->Insert(node);
}

HuffmanNode* HuffmanTree::DeleteMin() {
  return heap_->DeleteMin();
}


