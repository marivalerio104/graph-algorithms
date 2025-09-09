#pragma once
#include "GraphCell.hpp"

constexpr int MAX_NODES = 30; // Maximum number of nodes the graph can have

class Graph {
private:
  int counter;   
  char labels[MAX_NODES + 1];   
  GraphCell edges[MAX_NODES + 1][MAX_NODES + 1];

public:
  // Creates a new empty graph.
  Graph();

  // Adds a node with the label to the graph and returns the added node.
  // Requires that the graph is not full.
  int addNode(char label);

  // Removes the node node from the graph.
  // Requires 'n' valid in the graph and with no edges.
  void removeNode(int n);

  // Returns the label of the node in the graph.
  // Requires 'n' valid in the graph.
  char label(int n);

  // Changes the label of the node in the graph.
  // Requires 'n' valid in the graph.
  void modifyLabel(int n, char label);

  // Adds an edge between 'n1' and 'n2' with the specified weight.
  // Requires 'n1' and 'n2' different and valid in the graph.
  void addEdge(int n1, int n2, int weight);

  // Removes the edge between 'n1' and 'n2'.
  // Requires 'n1' and 'n2' different and valid in the graph.
  void removeEdge(int n1, int n2);

  // Returns the weight of the edge between 'n1' and 'n2' in the graph.
  // Requires 'n1' and 'n2' different, adjacent and valid in the graph.
  int weight(int n1, int n2) const;

  // Changes the weight of the edge between 'n1' and 'n2' to the given weight.
  // Requires 'n1' and 'n2' different, adjacent and valid in the graph.
  void modifyWeight(int n1, int n2, int weight);

  // Returns the first node of the graph, returns 0 if the graph is empty.
  int firstNode();

  // Returns the node after 'n', returns 0 if 'n' is the last one.
  // Requires 'n' valid in the graph.
  int nextNode(int n);

  // Returns the first adjacent node of 'n', returns 0 if 'n' has no adjacent nodes.
  // Requires 'n' valid in the graph.
  int firstAdjacentNode(int n);

  // Returns the next adjacent node of 'n1' after 'n2', returns 0 if 'n2' is the last adjacent node of 'n1'.
  // Requires 'n1' and 'n2' different, adjacent and valid in the graph.
  int nextAdjacentNode(int n1, int n2);

  // Returns the number of nodes in the graph.
  int numNodes();

  // Returns true if the nodes are adjacent in the graph; otherwise, returns false.
  // Requires 'n1' and 'n2' different and valid in the graph.
  bool areAdjacent(int n1, int n2);

  // Compares 2 nodes, used for sorting.
  bool operator()(const int n1, const int n2) const;
};
