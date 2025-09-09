#include "GraphCell.hpp"

Graph::Graph() {
   counter = 0;
}

int Graph::addNode(char etiqueta) {
   counter++;
   labels[counter] = etiqueta;

   // Clear the new row and column in the adjacency matrix
   for(int x = 1; x <= counter; x++) {
      aristas[x][counter].adjacent = false;
      aristas[counter][x].adjacent = false;
   }
   return counter;
}

void Graph::removeNode(int v) {
   for(int x = v; x < counter; x++) {
      labels[x] = labels[x+1]; // Remove the label from the list

      // Shift rows and columns in adjacency matrix to fill the gap
      for(int i=1; i<=counter; i++) {
         aristas[i][x] = aristas[i][x+1];
      }
      for(int j=1; j<=counter; j++) {
         aristas[x][j] = aristas[x+1][j];
      }
   }
   counter--;
}

char Graph::label(int vertice) {
   return labels[vertice];
}

void Graph::modifyLabel(int vertice, char etiqueta) {
   labels[vertice] = etiqueta;
}

void Graph::addEdge(int v1, int v2, int peso) {
   aristas[v1][v2].adjacent = true;
   aristas[v1][v2].peso = peso;
   aristas[v2][v1].adjacent = true;
   aristas[v2][v1].peso = peso;
}

void Graph::removeEdge(int v1, int v2) {
   aristas[v1][v2].adjacent = false;
   aristas[v2][v1].adjacent = false;
}

int Graph::weight(int v1, int v2) const {
   return aristas[v1][v2].peso;
}

void Graph::modifyWeight(int v1, int v2, int peso) {
   aristas[v1][v2].peso = peso;
   aristas[v2][v1].peso = peso;
}

int Graph::firstNode() {
   return (counter != 0) ? 1 : 0;
}

int Graph::nextNode(int v) {
   return (v == counter) ? 0 : v + 1;
}

int Graph::firstAdjacentNode(int v) {
   for(int j = 1; j <= counter; j++) {
      if(aristas[v][j].adjacent == true) {
         return j;
      }
   }
   return 0;  // No adjacent node found
}

int Graph::nextAdjacentNode(int v1, int v2) {
   for(int j = v2 + 1; j <= counter; j++) {
      if(aristas[v1][j].adjacent == true) {
         return j;
      }
   }
   return 0;  // No other adjacent node found
}

int Graph::numNodes() {
   return counter;
}

bool Graph::areAdjacent(int v1, int v2) {
   return aristas[v1][v2].adjacent;
}

bool Graph::operator()(const int v1, const int v2) const { 
   return v1 < v2; 
}
