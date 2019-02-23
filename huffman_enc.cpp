#include <iostream>
#include "huffman_node.h"

int main() {

  std::cout << "hayy" << std::endl;

  HuffmanNode* nodeA = new HuffmanNode();
  HuffmanNode* nodeB = new HuffmanNode();

  nodeA->leftChild = nodeB;

  std::cout << "It's ovah " << nodeA->leftChild->freq << std::endl;

  delete nodeB;
  delete nodeA;

  return 0;
}
