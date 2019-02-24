#include <iostream>

#include "huffman_tree.h"

int main(int argc, char **argv) {

  if (argc != 2) {
    cout << "Please specify input file name" << endl;
    exit(1);
  }

  FILE* fp = fopen(argv[1], "r");
  if (!fp) {
    cout << "File '" << argv[1] << "' not found!!" << endl;
  }

  HuffmanTree tree;

  unordered_map<char, int> frequencyTable = tree.ReadInputFileToMap(fp);

  fclose(fp);

  tree.AddTableToHeap(frequencyTable);

  tree.ConstructHuffmanTree();
  
  HuffmanNode* head = tree.get_head_node();

  tree.PrintTree(head);

  return 0;
}
