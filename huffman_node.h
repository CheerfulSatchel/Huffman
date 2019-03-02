#ifndef HUFFMAN_NODE_H

#define HUFFMAN_NODE_H

class HuffmanNode {
 public:
  HuffmanNode();
  HuffmanNode(int freq, char letter);
  ~HuffmanNode();

 private:
  int freq;
  char letter;
  HuffmanNode* leftChild;
  HuffmanNode* rightChild;

  friend class HuffmanTree;
  friend class BinaryHeap;
};

#endif 
