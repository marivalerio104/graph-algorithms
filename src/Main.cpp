#include <iostream>
#include <string>
#include "AlgorithmsUtils.hpp"
#include "GraphAlgorithms.hpp"

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
void dijkstra(Graph* graph);

int main() {
  Graph* graph = new Graph();
  int option = 0, subOption;

  // Graph for testing
  int A = graph->addNode('A');
  int B = graph->addNode('B');
  int C = graph->addNode('C');
  int D = graph->addNode('D');
  int E = graph->addNode('E');
  int F = graph->addNode('F');
  graph->addNode('G');
  graph->addEdge(A, B, 4);
  graph->addEdge(A, C, 2);
  graph->addEdge(B, C, 1);
  graph->addEdge(B, D, 5);
  graph->addEdge(C, D, 8);
  graph->addEdge(C, E, 10);
  graph->addEdge(D, E, 2);
  graph->addEdge(D, F, 6);
  graph->addEdge(E, F, 3);

  std::cout << "Character graph created." << std::endl
            << "Do not add more than 30 nodes, do not use duplicate labels, and weights must be greater than 0." << std::endl;

  while (option != 14) {
    std::cout << "\nEnter the number of the action you want to perform on the graph:" << std::endl
              << " 1. Add node" << std::endl
              << " 2. Remove node" << std::endl
              << " 3. Modify label" << std::endl
              << " 4. Add edge" << std::endl
              << " 5. Remove edge" << std::endl
              << " 6. Get edge weight" << std::endl
              << " 7. Modify edge weight" << std::endl
              << " 8. First node" << std::endl
              << " 9. Next node" << std::endl
              << "10. First adjacent node" << std::endl
              << "11. Next adjacent node" << std::endl
              << "12. Number of nodes" << std::endl
              << "13. Graph algorithms" << std::endl
              << "14. Exit program" << std::endl;

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
      else if (option == 13) {
        std::cout << "\nAlgorithms:" << std::endl
                  << "1. Dijkstra: finds the shortest path from one node to all the others" << std::endl
                  << "2. Floyd: finds the shortest path between every pair of nodes" << std::endl
                  << "3. Kruskal: finds the minimum cost spanning tree" << std::endl
                  << "4. Color a graph using the smallest number of colors possible" << std::endl
                  << "5. Lowest cost Hamiltonian circuit (using branch and bound)" << std::endl
                  << "6. Back" << std::endl;
        
        std::cin >> subOption;

        if (subOption == 1) dijkstra(graph);
      }
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

void dijkstra(Graph* graph) {
  char label;
  std::cout << "\nEnter the label of the node from which you want to obtain the shortest paths: ";
  std::cin >> label;
  int n = node(graph, label);
  auto result = dijkstra(graph, n);

  for (int i = 1; i <= graph->numNodes(); i++) {
    if (i == n) continue;
    
    std::cout << "\nPath from '" << graph->label(n) << "' to '" << graph->label(i) << "' ";
    
    if (result[i].first < INF) {
      std::string path = "";
      std::cout << "(cost: " << result[i].first << "):" << std::endl;
      int j = i;

      while(j != n) {
        path.insert(0, 1, graph->label(j));
        path = " -> " + path;
        j = result[j].second;
      }
      path.insert(0, 1, graph->label(j));
      std::cout << path << std::endl;

    } else {
      std::cout << "does not exist" << std::endl;
    }
  }
}
