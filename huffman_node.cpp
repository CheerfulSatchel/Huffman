#include "huffman_node.h"

HuffmanNode::HuffmanNode() {
  freq = -1;
  letter = 0;
  leftChild = 0;
  rightChild = 0;
}

HuffmanNode::HuffmanNode(int freq, char letter) {
  this->freq = freq;
  this->letter = letter;
  leftChild = 0;
  rightChild = 0;
}

HuffmanNode::~HuffmanNode() {
}

