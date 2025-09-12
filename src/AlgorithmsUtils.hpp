#pragma once
#include "graph/Graph.hpp"
#include <array>
#include <set>
#include <vector>

namespace utils {

// Returns the first node in the graph with the specified label, returns 0 if there is no node with the label
int node(Graph* graph, char label);

// Returns true if the two vectors are disjoint; otherwise, returns false
bool areDisjoint(std::vector<int> v1, std::vector<int> v2);

// Returns the index of the subset of 'x'
int subset(int x, std::vector<std::set<int>> vector);

// Returns the lower bound for Hamilton
double getBound(std::vector<std::vector<int>> weights, std::vector<std::vector<bool>> forced);

}