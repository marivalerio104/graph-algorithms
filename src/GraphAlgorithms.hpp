#pragma once
#include "graph/Graph.hpp"
#include <climits>
#include <utility>
#include <vector>
#define INF INT_MAX

// Returns an array of pairs with the minimum cost and the immediately preceding node 
// of the shortest path between 'n' and all other nodes in the graph. 
// Requires 'n' valid in the graph.
std::vector<std::pair<int, int>> dijkstra(Graph* graph, int n);
