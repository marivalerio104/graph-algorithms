#include "GraphAlgorithms.hpp"

namespace algorithms {

std::vector<std::pair<int, int>> dijkstra(Graph* graph, int n) {
  std::vector<std::pair<int, int>> paths;  // Array of minimum costs and immediately preceding nodes
  std::vector<bool> completed;             // Completed nodes already chosen as pivots

  for (int i = 0; i < graph->numNodes(); i++) {  // Initialization of the paths
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

  for (int _ = 0; _ < graph->numNodes() - 2; _++) {  // Outer loop
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
  for (int i = 0; i < graph->numNodes(); i++) {
    // Initialize the set of sets, each node has its own set
    std::set<int> aux;
    aux.insert(i);
    cc.push_back(aux);

    // Add all the edges to the heap
    int na = graph->firstAdjacentNode(i);
    while (na != -1) {
      edges.insert({i, na}, graph->weight(i, na));
      na = graph->nextAdjacentNode(i, na);
    }
  }
  
  while (edges.numElements() != 0 && cc.size() > 1) {
    std::pair<int, int> minEdge = edges.remove();
    int sc1 = utils::subset(minEdge.first, cc);
    int sc2 = utils::subset(minEdge.second, cc);

    if (sc1 != sc2) {  // If the nodes are in different subsets
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
  for (int color = 0; color < int(adjacents.size()); color++) {
    // If assigning this color is feasible
    if (utils::areDisjoint(adjacents[n], currentSolution[color])) {
      currentSolution[color].push_back(n);
      // Increment current color count if it is the first time using this color
      if (currentSolution[color].size() == 1) colorsCurrent++;  
    
      if (n == int(adjacents.size()) - 1) { // Stop condition
        if (colorsBest == 0 || colorsCurrent < colorsBest) {  // If a better solution was found
          bestSolution = currentSolution;
          colorsBest = colorsCurrent;
        }
      // Does not continue if the current solution is worse than the best solution
      } else if ((colorsCurrent <= colorsBest && colorsBest != 0) || colorsBest == 0) {
        colorNode(n+1, adjacents, currentSolution, bestSolution, colorsBest, colorsCurrent);
      }
      // Backtrack
      currentSolution[color].pop_back();
      if (currentSolution[color].size() == 0) colorsCurrent--;
    }
  }
}

std::vector<std::vector<int>> graphColoring(Graph* graph) {
  std::vector<std::vector<int>> currentSolution;  // Current color assignment
  int colorsBest = 0, colorsCurrent = 0;          // Tracks the amount of colors used
  std::vector<std::vector<int>> adjacents;

  // Initialize adjacency list and current solution vectors
  int n = graph->firstNode();
  while (n != -1) {
    std::vector<int> aux;
    currentSolution.push_back(aux);  // Each color has an initially empty set of nodes
    adjacents.push_back(aux);
    
    // Fill adjacency list: store adjacent nodes for each node
    int na = graph->firstAdjacentNode(n);
    while (na != -1) {
      adjacents[n].push_back(na);
      na = graph->nextAdjacentNode(n, na);
    }
    n = graph->nextNode(n);
  }
  std::vector<std::vector<int>> bestSolution = currentSolution;
  colorNode(0, adjacents, currentSolution, bestSolution, colorsBest, colorsCurrent);
  return bestSolution;
}


void hamiltonR(int n, std::vector<std::vector<int>>& weights,
               std::vector<std::vector<bool>>& forced, std::set<int>& visited,
               std::vector<int>& currentSolution, std::vector<int>& bestSolution,
               int& currentCost, int& bestCost) {

   std::vector<std::pair<double, int>> bounds;

   for (int i = 0; i < int(weights.size()); i++) { // Se calculan las bounds
      if (weights[v][j] != -1) { // Si existe la arista
         if (forced[v][j] == true) {
            bounds.push_back({utils::getBound(weights, forced), j});
         } else {
            forced[n][i] = true;
            forced[i][n] = true;
            double bound = utils::getBound(weights, forced);

            // Si no existe camino de Hamilton
            if (bound == 0) return;
          
            bounds.push_back({bound, j});
            forced[n][i] = false;
            forced[i][n] = false;
         }
      }
   }
   std::sort(bounds.begin(), bounds.end());

   for (auto va : bounds) {
      // Poda
      if (va.first > bestCost) break;
      
      if (visited.find(va.second) == visited.end()) { // If it is feasible
         currentSolution.push_back(va.second);
         currentCost += weights[v][va.second];
         visited.insert(va.second);
         forced[v][va.second] = true;
         forced[va.second][v] = true;

         if (int(visited.size()) == int(weights.size())) { // Stop condition
            if ((weights[va.second][0] != -1) && (currentCost + weights[va.second][0] < bestCost)) {
              bestCost = currentCost + weights[va.second][0];
              bestSolution = currentSolution;
            }
         } else {
            hamiltonR(va.second, weights, forced, visited, currentSolution, bestSolution, currentCost, bestCost);
         }
         // Rollback
         currentSolution.pop_back();
         currentCost -= weights[v][va.second];
         visited.erase(va.second);
         forced[v][va.second] = false;
         forced[va.second][v] = false;
      }
   }
} 

}
