#include "AlgorithmsUtils.hpp"

namespace utils {

int node(Graph* graph, char label) {
  int n = graph->firstNode();

  while(n != -1 && (graph->label(n) != label)) {
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

double getBound(std::vector<std::vector<int>> weights, std::vector<std::vector<bool>> forced) {
  double bound = 0;

  // Iterate over each node in the graph
  for (int i = 0; i < int(weights.size()); i++) {
    int counter = 0;  // Number of forced edges found for this node
    std::array<int, 2> smallest = {-1, -1}; // Store the two smallest non-forced edges

    // Explore all edges from node i
    for (int j = 0; j < int(weights.size()); j++) {
      if (forced[i][j] == true) {  // If the edge (i, j) is mandatory
        bound += weights[i][j];  // Add its weight to the bound
        counter++;

        // If the node already has 2 forced edges, no need to search further
        if (counter == 2) break;
        
      } else if (weights[i][j] != -1) {  // If the edge is not forced
        if (smallest[1] == -1) {  // First candidate edge found
          smallest[1] = j;
        // Found a smaller edge than the current smallest  
        } else if (weights[i][j] < weights[i][smallest[1]]) {
          smallest[0] = smallest[1];
          smallest[1] = j;
        } else if ((smallest[0] == -1) || (weights[i][j] < weights[i][smallest[0]])) {
          smallest[0] = j;
        }
      }
    }
    // Each node must end up with 2 edges; otherwise, return 0 (invalid bound)
    if ((smallest[1] == -1 && counter != 2) || (smallest[0] == -1 && counter == 0)) {
      return 0;
    }
    // If less than 2 forced edges were found, add the smallest edges
    for (int x = counter; x < 2; x++) {
      bound += weights[i][smallest[x]];
    }
  }
  // Each edge was counted twice (once from each node), so divide by 2
  return bound / 2;
}

}
