#include "Graph.hpp"

Graph::Graph() { counter = 0; }

int Graph::addNode(char label) {
  labels[counter] = label;
  
  // Clear the new row and column in the adjacency matrix
  for (int i = 0; i <= counter; i++) {
    edges[i][counter].adjacent = false;
    edges[counter][i].adjacent = false;
  }
  counter++;
  return counter - 1;
}

void Graph::removeNode(int n) {
  counter--;

  for (int i = n; i < counter; i++) {
    labels[i] = labels[i+1];  // Remove the label from the list

    // Shift the columns in the adjacency matrix to fill the gap
    for (int j = 0; j < counter; j++) {
      edges[i][j] = edges[i+1][j];
    }
  }

  // Shift the rows in the adjacency matrix to fill the gap
  for (int i = n; i < counter; i++) {
    for (int j = 0; j < counter; j++) {
      edges[j][i] = edges[j][i+1];
    }
  }
}

char Graph::label(int n) { return labels[n]; }
void Graph::modifyLabel(int n, char label) { labels[n] = label; }

void Graph::addEdge(int n1, int n2, int weight) {
  edges[n1][n2].adjacent = true;
  edges[n1][n2].weight = weight;
  edges[n2][n1].adjacent = true;
  edges[n2][n1].weight = weight;
}

void Graph::removeEdge(int n1, int n2) {
  edges[n1][n2].adjacent = false;
  edges[n2][n1].adjacent = false;
}

int Graph::weight(int n1, int n2) const { return edges[n1][n2].weight; }

void Graph::modifyWeight(int n1, int n2, int weight) {
  edges[n1][n2].weight = weight;
  edges[n2][n1].weight = weight;
}

int Graph::firstNode() { 
  return (counter == 0) ? -1 : 0;
}

int Graph::nextNode(int n) { 
  return (n == counter-1) ? -1 : n + 1; 
}

int Graph::firstAdjacentNode(int n) {
  for (int j = 0; j < counter; j++) {
    if (edges[n][j].adjacent == true) {
      return j;
    }
  }
  return -1;  // No adjacent node found
}

int Graph::nextAdjacentNode(int n1, int n2) {
  for (int i = n2 + 1; i < counter; i++) {
    if (edges[n1][i].adjacent == true) {
      return i;
    }
  }
  return -1;  // No other adjacent node found
}

int Graph::numNodes() { return counter; }

bool Graph::areAdjacent(int n1, int n2) { return edges[n1][n2].adjacent; }

bool Graph::operator()(const int n1, const int n2) const { return n1 < n2; }
