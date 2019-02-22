#ifndef HUFFMAN_NODE_H

#define HUFFMAN_NODE_H

class HuffmanNode {
 public:
  HuffmanNode();
  ~HuffmanNode();

  //TODO: Set following fields as private and use 'friends' keyword
  int freq;
  char c;
  HuffmanNode* leftChild;
  HuffmanNode* rightChild;
};

#endif 
