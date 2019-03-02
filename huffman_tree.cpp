#include "huffman_tree.h"

HuffmanTree::HuffmanTree() {
  heap_ = new BinaryHeap();
}

HuffmanTree::~HuffmanTree() {  
  delete heap_;
}

void HuffmanTree::Insert(HuffmanNode* node) {
  heap_->Insert(node);
}

HuffmanNode* HuffmanTree::DeleteMin() {
  return heap_->DeleteMin();
}

unordered_map<char, int> HuffmanTree::ReadInputFileToMap(FILE* fp) {
  unordered_map<char, int> frequencyTable;

  char cItr;
  while ((cItr = fgetc(fp)) != EOF) {
    cout << cItr << " and .... " << endl;
    
    unordered_map<char, int>::const_iterator mapItr = frequencyTable.find(cItr);

    if (mapItr == frequencyTable.end()) {
      // First insertion of character
      frequencyTable.insert(pair<char, int>(cItr, 1));
    } else {
      // Subsequent insertions of character increment count
      frequencyTable.at(cItr) += 1;
    }

    cout << cItr;
  }

  return frequencyTable;
  
}

void HuffmanTree::AddTableToHeap(unordered_map<char, int> frequencyTable) {
  unordered_map<char, int>::const_iterator itr;

  for (itr = frequencyTable.begin(); itr != frequencyTable.end(); ++itr) {
    char letter  = itr->first;
    int freq = itr->second;

    cout << "Inserting " << letter << " : " << freq << endl; 
    HuffmanNode* node = new HuffmanNode(freq, letter);
    Insert(node);
  }
}

void HuffmanTree::ConstructHuffmanTree() {
  int heap_size = heap_->heap_size();

  heap_->Print();

  while (heap_size > 1) {
    HuffmanNode* nodeA = heap_->DeleteMin();
    HuffmanNode* nodeB = heap_->DeleteMin();

    cout << "Left child: " << nodeA->letter << endl;

    int totalFreq = nodeA->freq + nodeB->freq;

    HuffmanNode* combined = new HuffmanNode(totalFreq, '-');

    combined->leftChild = nodeA;
    combined->rightChild = nodeB;

    heap_->Insert(combined);

    heap_size = heap_->heap_size();
  }
}

void HuffmanTree::ReconstructHuffmanTree(string character, string prefix) {
  HuffmanNode* currentNode = get_head_node();

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

char HuffmanTree::DecodeTree(string bits) {
  const char* bitsies = bits.c_str();

  HuffmanNode* root = get_head_node();
  
  int i;
  for (i=0; i<bits.size(); ++i) {
    if (bitsies[i] == '0') {
      root = root->leftChild;
    } else if (bitsies[i] == '1') {
      root = root->rightChild;
    } else {
      throw "Invalid character found!!!";
    }
  }

  return root->letter;
}

// Prints tree in-order
void HuffmanTree::PrintTree(HuffmanNode* head) {
  if (!head) {
    return;
  }
  
  PrintTree(head->leftChild);

  cout << "Value: " << head->freq << " : " << head->letter << endl;

  PrintTree(head->rightChild);
}

void HuffmanTree::PrintEncoding(HuffmanNode* head, string s) {
  if (!head) {
    return;
  }

  if (!head->leftChild && !head->rightChild) {
    cout << "Pairing is " << head->letter << " : " << s << endl;
    return;
  }

  if (head->leftChild) {
     PrintEncoding(head->leftChild, s + "0");
  }

  if (head->rightChild) {
    PrintEncoding(head->rightChild, s + "1");
  }
}

HuffmanNode* HuffmanTree::get_head_node() {
  return heap_->FindMin();
}
