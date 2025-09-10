#pragma once
#include "graph/Graph.hpp"
#include <set>
#include <vector>

// Returns the first node in the graph with the specified label, returns 0 if there is no node with the label
int node(Graph* graph, char label);

// Returns the index of the subset of 'x'
int subset(int x, std::vector<std::set<int>> vector);
