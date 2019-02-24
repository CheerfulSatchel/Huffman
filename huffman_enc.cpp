#include <iostream>
#include <unordered_map>
#include <stdio.h>
#include <stdlib.h>

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

  unordered_map<char, int> frequencyTable;

  char cItr;
  while ((cItr = fgetc(fp)) != EOF) {
    unordered_map<char, int>::const_iterator mapItr = frequencyTable.find(cItr);

    // Initial insertion 
    if (mapItr == frequencyTable.end()) {
      cout << "Insertin new: " << cItr << endl;
      frequencyTable.insert(pair<char, int>(cItr, 1));
    } else { // Increment character frequency if already in the table
      frequencyTable.at(cItr) += 1;
    }

    cout << "Yee: " << cItr << ", ";
  }

  unordered_map<char, int>::const_iterator itr;
  
  for (itr = frequencyTable.begin(); itr != frequencyTable.end(); ++itr) {
    cout << itr->first << " : " << itr->second << endl;
  }
  

  HuffmanNode* nodeA = new HuffmanNode();
  HuffmanNode* nodeB = new HuffmanNode();

  nodeA->leftChild = nodeB;

  std::cout << "It's ovah " << nodeA->leftChild->freq << std::endl;

  delete nodeB;
  delete nodeA;

  return 0;
}
