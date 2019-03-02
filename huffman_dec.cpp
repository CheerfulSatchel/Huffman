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

int main(int argc, char** argv) {
  if (argc != 2) {
    cout << "Missing input file name!" << endl;
    exit(1);
  }

  ifstream file(argv[1], ifstream::binary);

  HuffmanNode* root = new HuffmanNode(0, '-');

  HuffmanTree tree;

  tree.Insert(root);
  
  HuffmanNode* itr = root;
  
  while (true) {
    string character, prefix;
    file >> character;

    if ((character[0] == '-') && (character.length() > 1)) break;

    if (character == "space") character = " ";

    file >> prefix;

    cout << "character '" << character << "' has prefix code '"
	 << prefix << "'" << endl;

    tree.ReconstructHuffmanTree(character, prefix);
    itr = root;
  }
  
  tree.Insert(root);

  tree.PrintTree(root);

  string decoded = "";
  
  while (true) {
    string bits;
    file >> bits;

    if (bits[0] == '-') break;

    char c = tree.DecodeTree(bits);

    decoded += c;
  }

  cout << decoded << endl;
 
  file.close();
  
  return 0;
}
