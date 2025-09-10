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

std::vector<std::pair<int, int>> kruskal(Graph* graph) {
  Heap edges;                            // Edges ordered
  std::vector<std::set<int>> cc;         // Set of sets
  std::vector<std::pair<int, int>> mst;  // Edges in the minimum cost spanning tree

  // Initialization
  for(int i = 1; i <= graph->numNodes(); i++) {
    // Initialize the set of sets, each node has its own set
    std::set<int> aux;
    aux.insert(i);
    cc.push_back(aux);

    // Add all the edges to the heap
    for(int j = i+1; j <= graph->numNodes(); j++) {
      if(graph->areAdjacent(i, j)) {
        edges.insert({i, j}, graph->weight(i, j));
      }
    }
  }
  
  while(edges.numElements() != 0 && cc.size() > 1) {
    std::pair<int, int> minEdge = edges.remove();
    int sc1 = subset(minEdge.first, cc);
    int sc2 = subset(minEdge.second, cc);

    if(sc1 != sc2) {  // If the nodes are in different subsets
      cc[sc1].insert(cc[sc2].begin(), cc[sc2].end());  // The subsets are joined
      cc.erase(cc.begin() + sc2);
      mst.push_back({minEdge.first, minEdge.second});  // Add the edge to the tree
    }
  }
  return mst;
}
