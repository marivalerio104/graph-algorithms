#include "AlgorithmsUtils.hpp"

int node(Graph* graph, char label) {
  int n = graph->firstNode();

  while(n && (graph->label(n) != label)) {
    n = graph->nextNode(n);
  }
  return n;
}

bool areDisjoint(std::vector<int> v1, std::vector<int> v2) {
  for(int i : v1) {
    for(int j : v2) {
      if(i == j) {
        return false;
      }
    }
  }
  return true;
}

int subset(int x, std::vector<std::set<int>> vector) {
  for(int i = 0; i < int(vector.size()); i++) {
    if(vector[i].find(x) != vector[i].end()) {
      return i;
    }
  }
  return -1;
}
