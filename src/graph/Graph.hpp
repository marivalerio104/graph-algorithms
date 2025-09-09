#pragma once
#include "GraphCell.hpp"

constexpr int MAX_NODES = 30; // Maximum number of nodes the graph can have

class Graph {
private 
   int counter;   
   char labels[MAX_NODES + 1];   
   GraphCell edges[MAX_NODES + 1][MAX_NODES + 1];

public
   /*
   Creates a new empty graph.
   Requires graph not initialized.
   */
   Graph();

   /*
   Adds a node with the label to the graph and returns the added node.
   Requires graph initialized and not full.
   */
   int addNode(char label);

   /*
   Removes the node "v" from the graph.
   Requires graph initialized and not empty, "v" valid in the graph, and isolated.
   */
   void removeNode(int v);

   /*
   Returns the label of the node in the graph.
   Requires graph initialized and not empty, and node valid in the graph.
   */
   char label(int node);

   /*
   Changes the label of the node in the graph.
   Requires graph initialized and not empty, and node valid in the graph.
   */
   void modifyLabel(int node, char label);

   /*
   Adds an edge between v1 and v2 with the weight in the graph.
   Requires graph initialized and not empty, v1 and v2 valid in the graph, v1 different from v2, and no edge exists between v1 and v2.
   */
   void addEdge(int v1, int v2, int weight);

   /*
   Removes the edge between v1 and v2 in the graph.
   Requires graph initialized and not empty, v1 and v2 valid in the graph, v1 different from v2, and an edge exists between v1 and v2.
   */
   void removeEdge(int v1, int v2);

   /*
   Returns the weight of the edge between v1 and v2 in the graph.
   Requires graph initialized and not empty, v1 and v2 valid in the graph, v1 different from v2, and an edge exists between v1 and v2.
   */
   int weight(int v1, int v2) const;

   /*
   Changes the weight of the edge between v1 and v2 in the graph to the given weight.
   Requires graph initialized and not empty, v1 and v2 valid in the graph, v1 different from v2, and an edge exists between v1 and v2.
   */
   void modifyWeight(int v1, int v2, int weight);

   /*
   Returns the first node of the graph; if the graph is empty, returns 0.
   Requires graph initialized.
   */
   int firstNode();

   /*
   Returns the node after "v" in the graph; if "v" is the last node, returns 0.
   Requires graph initialized and not empty, and "v" valid in the graph.
   */
   int nextNode(int v);

   /*
   Returns the first adjacent node of "v" in the graph; if "v" has no adjacent nodes, returns 0.
   Requires graph initialized and not empty, and "v" valid in the graph.
   */
   int firstAdjacentNode(int v);

   /*
   Returns the adjacent node of "v1" after "v2" in the graph; if "v2" is the last adjacent node of "v1", returns 0.
   Requires graph initialized and not empty, v1 and v2 valid in the graph, v1 different from v2, and v1 and v2 are adjacent.
   */
   int nextAdjacentNode(int v1, int v2);

   /*
   Returns the number of nodes in the graph.
   Requires graph initialized.
   */
   int numNodes();

   /*
   Returns true if the nodes are adjacent in the graph; otherwise, returns false.
   Requires graph initialized and not empty, v1 and v2 valid in the graph, and v1 different from v2.
   */
   bool areAdjacent(int v1, int v2);

   // Compares 2 nodes. Used for sorting.
   bool operator()(const int v1, const int v2) const;
};
