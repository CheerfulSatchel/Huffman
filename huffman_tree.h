#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <stdio.h>
#include <stdlib.h>

#include <unordered_map>
#include <iostream>
#include <string>

#include "binary_heap.h"

using namespace std;

class HuffmanTree {
 public:
  // Default Constructor
  HuffmanTree();
  ~HuffmanTree();

  // Methods
  void Insert(HuffmanNode* node);
  HuffmanNode* DeleteMin();
  unordered_map<char, int> ReadInputFileToMap(FILE* fp);
  void AddTableToHeap(unordered_map<char, int> frequencyTable);
  void ConstructHuffmanTree();
  void PrintTree(HuffmanNode* head);
  void PrintEncoding(HuffmanNode* head, string s);

  // Getters
  HuffmanNode* get_head_node();

  
 private:
  BinaryHeap* heap_;  
};

#endif
