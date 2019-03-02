/** Template code based off of https://aaronbloomfield.github.io/pdr/labs/lab10/inlab-skeleton.cpp.
 *
 * The template code reads in the input files. 
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

#include "huffman_tree.h"

using namespace std;

void RecreateTree(HuffmanNode* root, string character, string prefix);

int main(int argc, char** argv) {
  if (argc != 2) {
    cout << "Missing input file name!" << endl;
    exit(1);
  }

  ifstream file(argv[1], ifstream::binary);

  HuffmanNode* root = new HuffmanNode(0, '-');
  HuffmanNode* itr = root;
  
  while (true) {
    string character, prefix;
    file >> character;

    if ((character[0] == '-') && (character.length() > 1)) break;

    if (character == "space") character = " ";

    file >> prefix;

    cout << "character '" << character << "' has prefix code '"
	 << prefix << "'" << endl;

    RecreateTree(itr, character, prefix);
    itr = root;
  }

  HuffmanTree tree;
  tree.Insert(root);

  tree.PrintTree(root);
  
  stringstream sstm;
  while (true) {
    string bits;
    file >> bits;

    if (bits[0] == '-') break;

    sstm << bits;
  }

  string allbits = sstm.str();

  cout << "All the bits: " << allbits << endl;

  file.close();
  
  return 0;
}

void RecreateTree(HuffmanNode* root, string character, string prefix) {
  HuffmanNode* currentNode = root;

  char letter = character.c_str()[0];
  const char* prefixes = prefix.c_str();

  int i;
  for (i=0; i<prefix.size(); ++i) {
    if (prefixes[i] == '0') {
      if (currentNode->leftChild) {
	currentNode = currentNode->leftChild;
      } else {
        HuffmanNode* left;
	// Internal '-' node
	if (i+1 < prefix.size()) {
	  left = new HuffmanNode(0, '-');
	} else {
	  // Child <letter> node
	  left = new HuffmanNode(0, letter);
	}

	currentNode->leftChild = left;
	currentNode = currentNode->leftChild;
      }
    } else if (prefixes[i] == '1') {
      if (currentNode->rightChild) {
	currentNode = currentNode->rightChild;
      } else {
	HuffmanNode* right;
	// Internal '-' node
	if (i+1 < prefix.size()) {
	  right = new HuffmanNode(0, '-');
	} else {
	  // Child <letter> node
	  right = new HuffmanNode(0, letter);
	}

	currentNode->rightChild = right;
	currentNode = currentNode->rightChild;
      }
    } else {
      throw "Unsupported character found!!!";
    }
  }
}
