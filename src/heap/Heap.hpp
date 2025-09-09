#pragma once
#include "HeapCell.hpp"

constexpr int MAX_HEAP = 30;  // Maximum number of elements the Heap can hold

class Heap {
private:
  HeapCell vector[MAX_HEAP + 1];  // The array that stores heap elements
  int last;  // Index of the last element currently in the heap

public:
  // Constructor: initializes an empty heap
  Heap();

  // Inserts a new element into the heap
  void insert(std::pair<int, int> edge, int priority);

  // Removes and returns the element with the highest priority
  std::pair<int, int> remove();

  // Returns the current number of elements in the heap
  int numElements();
};
