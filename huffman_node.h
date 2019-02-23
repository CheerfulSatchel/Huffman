#ifndef HUFFMAN_NODE_H

#define HUFFMAN_NODE_H

class HuffmanNode {
 public:
  HuffmanNode();
  HuffmanNode(int freq, char letter);
  ~HuffmanNode();

  //TODO: Set following fields as private and use 'friends' keyword
  int freq;
  char letter;
  HuffmanNode* leftChild;
  HuffmanNode* rightChild;
};

#endif 
