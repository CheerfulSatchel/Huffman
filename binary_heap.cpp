#include <iostream>

#include "binary_heap.h"

BinaryHeap::BinaryHeap() {
  heap_.push_back(0);
}

BinaryHeap::BinaryHeap(vector<int> vec) {
  int i;
  for (i = 0; i < vec.size(); i++) {
    Insert(vec[i]);
  }
}

BinaryHeap::~BinaryHeap() {
}

void BinaryHeap::Insert(int x) {
  // Write value to end of heap
  heap_.push_back(x);

  PercolateUp(heap_size());

}

int BinaryHeap::FindMin() {
  if (heap_size() == 0) {
    throw "Nothing to call findMin() on!!";
  }
  return heap_[1];
}

int BinaryHeap::DeleteMin() {
  if (heap_size() == 0) {
    throw "Nothing to call deleteMin() on!!";
  }

  int deletedMin = heap_[1];

  // Replace min value with last value in the heap
  heap_[1] = heap_[heap_size()];
  
  // Remove last value from heap
  heap_.pop_back();

  // Percolate value down from index of minimum value
  PercolateDown(1);

  return deletedMin;
}

unsigned int BinaryHeap::heap_size() {
  // Subtract 1 to account for sentinel value at start
  return heap_.size()-1;
}

vector<int> BinaryHeap::heap() {
  return heap_;
}

void BinaryHeap::MakeEmpty() {
  heap_.resize(1);
}

bool BinaryHeap::IsEmpty() {
  return heap_size() == 1;
}

void BinaryHeap::Print() {
  int i;
  for (i = 1; i <= heap_size(); i++) {
    cout << heap_[i] << " ";
  }
  cout << endl;
}

// Hole is the start index to percolate upwards
void BinaryHeap::PercolateUp(int hole) {
  while (hole >= 1) {
    if (heap_[hole] < heap_[hole/2]) {
      int temp = heap_[hole];
      heap_[hole] = heap_[hole/2];
      heap_[hole/2] = temp;
      hole = hole/2;
    } else {
      break;
    }
  }
}

// Hole is the start index to percholate downwards
void BinaryHeap::PercolateDown(int hole) {
  while (hole <= heap_size() && hole * 2 <= heap_size()) {
    int compareIdx;

    if (heap_[hole*2 + 1] < heap_[hole*2]) {
      compareIdx = hole*2 + 1;
    } else {
      compareIdx = hole*2;
    }

    if(heap_[hole] > heap_[compareIdx]) {
      int temp = heap_[hole];
      heap_[hole] = heap_[compareIdx];
      heap_[compareIdx] = temp;
      hole = compareIdx;
    } else {
      break;
    }
  }
  
}



