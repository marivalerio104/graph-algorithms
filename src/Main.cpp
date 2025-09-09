#include <iostream>
#include "AlgorithmsUtils.hpp"

// Forward declarations
void addNode(Graph* graph);
void removeNode(Graph* graph);
void modifyLabel(Graph* graph);
void addEdge(Graph* graph);
void removeEdge(Graph* graph);
void getWeight(Graph* graph);
void modifyWeight(Graph* graph);
void firstNode(Graph* graph);
void nextNode(Graph* graph);
void firstAdjacentNode(Graph* graph);
void nextAdjacentNode(Graph* graph);
void numNodes(Graph* graph);

int main() {
  Graph* graph = new Graph();

  std::cout << "Character graph created.\n"
            << "Do not add more than 30 nodes, do not use duplicate labels, and weights must be greater than 0." << std::endl;

  int option = 0;

  while (option != 13) {
    std::cout << "\nEnter the number of the action you want to perform on the graph:"
              << "\n  1. Add node"
              << "\n  2. Remove node"
              << "\n  3. Modify label"
              << "\n  4. Add edge"
              << "\n  5. Remove edge"
              << "\n  6. Get edge weight"
              << "\n  7. Modify edge weight"
              << "\n  8. First node"
              << "\n  9. Next node"
              << "\n 10. First adjacent node"
              << "\n 11. Next adjacent node"
              << "\n 12. Number of nodes"
              << "\n 13. Exit program" << std::endl;

      std::cin >> option;

      if (option == 1) addNode(graph);
      else if (option == 2) removeNode(graph);
      else if (option == 3) modifyLabel(graph);
      else if (option == 4) addEdge(graph);
      else if (option == 5) removeEdge(graph);
      else if (option == 6) getWeight(graph);
      else if (option == 7) modifyWeight(graph);
      else if (option == 8) firstNode(graph);
      else if (option == 9) nextNode(graph);
      else if (option == 10) firstAdjacentNode(graph);
      else if (option == 11) nextAdjacentNode(graph);
      else if (option == 12) numNodes(graph);
  }
}

// ---------- Functions ----------

void addNode(Graph* graph) {
  char label;
  std::cout << "\nEnter the label of the new node: ";
  std::cin >> label;
  graph->addNode(label);
  std::cout << "\nNode with label '" << label << "' added." << std::endl;
}

void removeNode(Graph* graph) {
  char label;
  std::cout << "\nEnter the label of the node to remove: ";
  std::cin >> label;
  int n = node(graph, label);
  graph->removeNode(n);
  std::cout << "\nNode with label '" << label << "' removed." << std::endl;
}

void modifyLabel(Graph* graph) {
  char label, newLabel;
  std::cout << "\nEnter the label of the node you want to modify: ";
  std::cin >> label;
  int n = node(graph, label);
  std::cout << "Enter the new label of the node: ";
  std::cin >> newLabel;
  graph->modifyLabel(n, newLabel);
  std::cout << "\nLabel '" << label << "' modified to '" << newLabel << "'." << std::endl;
}

void addEdge(Graph* graph) {
  char label;
  std::cout << "\nEnter the label of the first node: ";
  std::cin >> label;
  int n1 = node(graph, label);
  std::cout << "Enter the label of the second node: ";
  std::cin >> label;
  int n2 = node(graph, label);
  std::cout << "Enter the weight of the new edge: ";
  int weight;
  std::cin >> weight;
  graph->addEdge(n1, n2, weight);
  std::cout << "\nEdge with weight " << weight << " added." << std::endl;
}

void removeEdge(Graph* graph) {
  char label;
  std::cout << "\nEnter the label of the first node: ";
  std::cin >> label;
  int n1 = node(graph, label);
  std::cout << "Enter the label of the second node: ";
  std::cin >> label;
  int n2 = node(graph, label);
  graph->removeEdge(n1, n2);
  std::cout << "\nEdge removed." << std::endl;
}

void getWeight(Graph* graph) {
  char label;
  std::cout << "\nEnter the label of the first node: ";
  std::cin >> label;
  int n1 = node(graph, label);
  std::cout << "Enter the label of the second node: ";
  std::cin >> label;
  int n2 = node(graph, label);
  std::cout << "\nThe weight of the edge is " << graph->weight(n1, n2) << "." << std::endl;
}

void modifyWeight(Graph* graph) {
  char label;
  std::cout << "\nEnter the label of the first node: ";
  std::cin >> label;
  int n1 = node(graph, label);
  std::cout << "Enter the label of the second node: ";
  std::cin >> label;
  int n2 = node(graph, label);
  std::cout << "Enter the new weight of the edge: ";
  int weight;
  std::cin >> weight;
  graph->modifyWeight(n1, n2, weight);
  std::cout << "\nEdge weight modified to " << weight << "." << std::endl;
}

void firstNode(Graph* graph) {
  int n1 = graph->firstNode();
  if (n1) {
    std::cout << "\nThe label of the first node is '" << graph->label(n1) << "'." << std::endl;
  } else {
    std::cout << "\nThe graph is empty." << std::endl;
  }
}

void nextNode(Graph* graph) {
  char label;
  std::cout << "\nEnter the label of the node: ";
  std::cin >> label;
  int n = node(graph, label);
  n = graph->nextNode(n);
  if (n) {
    std::cout << "The label of the next node next to '" << label << "' is '" << graph->label(n) << "'." << std::endl;
  } else {
    std::cout << "\nThe graph has no more nodes." << std::endl;
  }
}

void firstAdjacentNode(Graph* graph) {
  char label;
  std::cout << "\nEnter the label of the node: ";
  std::cin >> label;
  int n = node(graph, label);
  n = graph->firstAdjacentNode(n);
  if (n) {
    std::cout << "\nThe label of the first adjacent node is '" << graph->label(n) << "'." << std::endl;
  } else {
    std::cout << "\nThe node has no adjacent nodes." << std::endl;
  }
}

void nextAdjacentNode(Graph* graph) {
  char label;
  std::cout << "\nEnter the label of the node: ";
  std::cin >> label;
  int n1 = node(graph, label);
  std::cout << "Enter the label of the adjacent node: ";
  std::cin >> label;
  int n2 = node(graph, label);
  n1 = graph->nextAdjacentNode(n1, n2);
  if (n1) {
    std::cout << "\nThe label of the next adjacent node is '" << graph->label(n1) << "'." << std::endl;
  } else {
    std::cout << "\nThe node has no more adjacent nodes." << std::endl;
  }
}

void numNodes(Graph* graph) {
  std::cout << "\nThe graph has " << graph->numNodes() << " nodes." << std::endl;
}
