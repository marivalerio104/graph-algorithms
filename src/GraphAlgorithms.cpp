#include "GraphAlgorithms.hpp"

std::vector<std::pair<int, int>> dijkstra(Graph* graph, int n) {
  std::vector<std::pair<int, int>> paths;  // Array of minimum costs and immediately preceding nodes
  std::vector<bool> completed;             // Completed nodes already chosen as pivots
  paths.push_back({0, 0});
  completed.push_back(false);

  for (int i = 1; i <= graph->numNodes(); i++) {  // Initialization of the paths
    if (i != n) {
      completed.push_back(false);

      if (graph->areAdjacent(n, i)) {
        paths.push_back({graph->weight(n, i), n});
      } else {
        paths.push_back({INF, n});  // If they are not adjacent, the distance is infinity
      }
    } else {
      paths.push_back({0, n});
      completed.push_back(true);
    }
  }

  for (int _ = 1; _ <= graph->numNodes() - 2; _++) {  // Outer loop
    int minCost = INF, pivot = 0;

    for (int i = 0; i < graph->numNodes(); i++) {  // Find the pivot
      if (!completed[i] && paths[i].first < minCost) {  // If it finds an edge with a lower cost
        minCost = paths[i].first;
        pivot = i;
      }
    }
    completed[pivot] = true;

    for (int i = 0; i < graph->numNodes(); i++) {  // Check if a path can be shortened using the pivot
      if (!completed[i] && graph->areAdjacent(i, pivot)) {
        if (paths[i].first > paths[pivot].first + graph->weight(i, pivot)) {
          paths[i] = {paths[pivot].first + graph->weight(i, pivot), pivot};
        }
      }
    }
  }
  return paths;
}
