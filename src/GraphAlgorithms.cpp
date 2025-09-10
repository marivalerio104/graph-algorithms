#include "GraphAlgorithms.hpp"

std::vector<std::pair<int, int>> dijkstra(Graph* graph, int n) {
  std::vector<std::pair<int, int>> paths;  // Array of minimum costs and immediately preceding nodes
  std::vector<bool> completed;             // Completed nodes already chosen as pivots
  paths.push_back({0, 0});                 // Dummy element to make node indices 1-based
  completed.push_back(false);              // Dummy element to make node indices 1-based

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


void colorNode(int n, const std::vector<std::vector<int>> adjacents, 
               std::vector<std::vector<int>>& currentSolution,
               std::vector<std::vector<int>>& bestSolution, 
               int& colorsBest, int& colorsCurrent) {
  // For each possible color
  for(int color = 0; color < int(adjacents.size())-1; color++) {
    // If assigning this color is feasible
    if(areDisjoint(adjacents[n], currentSolution[color])) {
      currentSolution[color].push_back(n);
      // Increment current color count if it is the first time using this color
      if(currentSolution[color].size() == 1) colorsCurrent++;  
    
      if(n == int(adjacents.size())-1) { // Stop condition
        if(colorsBest == 0 || colorsCurrent < colorsBest) {  // If a better solution was found
          bestSolution = currentSolution;
          colorsBest = colorsCurrent;
        }
      // Does not continue if the current solution is worse than the best solution
      } else if((colorsCurrent <= colorsBest && colorsBest != 0) || colorsBest == 0) {
        colorNode(n+1, adjacents, currentSolution, bestSolution, colorsBest, colorsCurrent);
      }
      // Backtrack
      currentSolution[color].pop_back();
      if(currentSolution[color].size() == 0) colorsCurrent--;
    }
  }
}

std::vector<std::vector<int>> graphColoring(Graph* graph) {
  std::vector<std::vector<int>> currentSolution;  // Current color assignment
  int colorsBest = 0, colorsCurrent = 0;          // Tracks the amount of colors used
  std::vector<std::vector<int>> adjacents;
  adjacents.push_back({});                        // Dummy element to make node indices 1-based

  // Initialize adjacency list and current solution vectors
  int n = graph->firstNode();
  while(n) {
    std::vector<int> aux;
    currentSolution.push_back(aux);  // Each color has an initially empty set of nodes
    adjacents.push_back(aux);
    n = graph->nextNode(n);
  }
  // Fill adjacency list: store adjacent nodes for each node
  for(int n = 1; n <= graph->numNodes(); n++) {
    for(int na = 1; na <= graph->numNodes(); na++) {
      if(n != na && graph->areAdjacent(n, na)) {
        adjacents[n].push_back(na);
      }
    } 
  }
  std::vector<std::vector<int>> bestSolution = currentSolution;
  colorNode(1, adjacents, currentSolution, bestSolution, colorsBest, colorsCurrent);
  return bestSolution;
}
