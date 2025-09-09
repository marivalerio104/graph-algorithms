#pragma once
#include "utility"

struct HeapCell {
  std::pair<int, int> edge;  // Pair of edges
  int priority;
};
