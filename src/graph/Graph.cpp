#include "Graph.hpp"

Graph::Graph() { counter = 0; }

int Graph::addNode(char label) {
  counter++;
  labels[counter] = label;

  // Clear the new row and column in the adjacency matrix
  for(int x = 1; x <= counter; x++) {
    edges[x][counter].adjacent = false;
    edges[counter][x].adjacent = false;
  }
  return counter;
}

void Graph::removeNode(int v) {
  for(int x = v; x < counter; x++) {
    labels[x] = labels[x+1];  // Remove the label from the list

    // Shift rows and columns in adjacency matrix to fill the gap
    for(int i=1; i<=counter; i++) {
      edges[i][x] = edges[i][x+1];
    }
    for(int j=1; j<=counter; j++) {
      edges[x][j] = edges[x+1][j];
    }
  }
  counter--;
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
  return (counter != 0) ? 1 : 0; 
}

int Graph::nextNode(int v) { 
  return (v == counter) ? 0 : v + 1; 
}

int Graph::firstAdjacentNode(int v) {
  for(int j = 1; j <= counter; j++) {
    if(edges[v][j].adjacent == true) {
      return j;
    }
  }
  return 0;  // No adjacent n found
}

int Graph::nextAdjacentNode(int n1, int n2) {
  for(int j = n2 + 1; j <= counter; j++) {
    if(edges[n1][j].adjacent == true) {
      return j;
    }
  }
  return 0;  // No other adjacent n found
}

int Graph::numNodes() { return counter; }

bool Graph::areAdjacent(int n1, int n2) { return edges[n1][n2].adjacent; }

bool Graph::operator()(const int n1, const int n2) const { return n1 < n2; }
