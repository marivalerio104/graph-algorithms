#include <iostream>
#include <string>
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
void dijkstraMenu(Graph* graph);
void kruskalMenu(Graph* graph);
void graphColoringMenu(Graph* graph);
void hamiltonMenu(Graph* graph);

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
  // graph->addNode('G');
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
      else if (option == 12) std::cout << "\nThe graph has " << graph->numNodes() << " nodes." << std::endl;
      else if (option == 13) {
        std::cout << "\nAlgorithms:" << std::endl
                  << "1. Dijkstra: finds the shortest path from one node to all the others" << std::endl
                  << "2. Kruskal: finds the minimum cost spanning tree" << std::endl
                  << "3. Graph coloring: color a graph so that no two adjacent nodes share the same color." << std::endl
                  << "4. Lowest cost Hamiltonian circuit (using branch and bound)" << std::endl
                  << "5. Back" << std::endl;
        
        std::cin >> subOption;

        if (subOption == 1) dijkstraMenu(graph);
        else if (subOption == 2) kruskalMenu(graph);
        else if (subOption == 3) graphColoringMenu(graph);
        else if (subOption == 4) hamiltonMenu(graph);
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
  int n = utils::node(graph, label);
  graph->removeNode(n);
  std::cout << "\nNode with label '" << label << "' removed." << std::endl;
}

void modifyLabel(Graph* graph) {
  char label, newLabel;
  std::cout << "\nEnter the label of the node you want to modify: ";
  std::cin >> label;
  int n = utils::node(graph, label);
  std::cout << "Enter the new label of the node: ";
  std::cin >> newLabel;
  graph->modifyLabel(n, newLabel);
  std::cout << "\nLabel '" << label << "' modified to '" << newLabel << "'." << std::endl;
}

void addEdge(Graph* graph) {
  char label;
  std::cout << "\nEnter the label of the first node: ";
  std::cin >> label;
  int n1 = utils::node(graph, label);
  std::cout << "Enter the label of the second node: ";
  std::cin >> label;
  int n2 = utils::node(graph, label);
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
  int n1 = utils::node(graph, label);
  std::cout << "Enter the label of the second node: ";
  std::cin >> label;
  int n2 = utils::node(graph, label);
  graph->removeEdge(n1, n2);
  std::cout << "\nEdge removed." << std::endl;
}

void getWeight(Graph* graph) {
  char label;
  std::cout << "\nEnter the label of the first node: ";
  std::cin >> label;
  int n1 = utils::node(graph, label);
  std::cout << "Enter the label of the second node: ";
  std::cin >> label;
  int n2 = utils::node(graph, label);
  std::cout << "\nThe weight of the edge is " << graph->weight(n1, n2) << "." << std::endl;
}

void modifyWeight(Graph* graph) {
  char label;
  std::cout << "\nEnter the label of the first node: ";
  std::cin >> label;
  int n1 = utils::node(graph, label);
  std::cout << "Enter the label of the second node: ";
  std::cin >> label;
  int n2 = utils::node(graph, label);
  std::cout << "Enter the new weight of the edge: ";
  int weight;
  std::cin >> weight;
  graph->modifyWeight(n1, n2, weight);
  std::cout << "\nEdge weight modified to " << weight << "." << std::endl;
}

void firstNode(Graph* graph) {
  int n = graph->firstNode();
  if (n != -1) {
    std::cout << "\nThe label of the first node is '" << graph->label(n) << "'." << std::endl;
  } else {
    std::cout << "\nThe graph is empty." << std::endl;
  }
}

void nextNode(Graph* graph) {
  char label;
  std::cout << "\nEnter the label of the node: ";
  std::cin >> label;
  int n = utils::node(graph, label);
  n = graph->nextNode(n);

  if (n != -1) {
    std::cout << "The label of the node next to '" << label << "' is '" << graph->label(n) << "'." << std::endl;
  } else {
    std::cout << "\nThe graph has no more nodes." << std::endl;
  }
}

void firstAdjacentNode(Graph* graph) {
  char label;
  std::cout << "\nEnter the label of the node: ";
  std::cin >> label;
  int n = utils::node(graph, label);
  n = graph->firstAdjacentNode(n);
  if (n != -1) {
    std::cout << "\nThe label of the first adjacent node is '" << graph->label(n) << "'." << std::endl;
  } else {
    std::cout << "\nThe node has no adjacent nodes." << std::endl;
  }
}

void nextAdjacentNode(Graph* graph) {
  char label;
  std::cout << "\nEnter the label of the node: ";
  std::cin >> label;
  int n1 = utils::node(graph, label);
  std::cout << "Enter the label of the adjacent node: ";
  std::cin >> label;
  int n2 = utils::node(graph, label);
  n1 = graph->nextAdjacentNode(n1, n2);
  if (n1 != -1) {
    std::cout << "\nThe label of the next adjacent node is '" << graph->label(n1) << "'." << std::endl;
  } else {
    std::cout << "\nThe node has no more adjacent nodes." << std::endl;
  }
}

void dijkstraMenu(Graph* graph) {
  char label;
  std::cout << "\nEnter the label of the node from which you want to obtain the shortest paths: ";
  std::cin >> label;
  int n = utils::node(graph, label);
  auto result = algorithms::dijkstra(graph, n);

  for (int i = 0; i < graph->numNodes(); i++) {
    if (i == n) continue;
    
    std::cout << "\nPath from '" << graph->label(n) << "' to '" << graph->label(i) << "' ";
    
    if (result[i].first < INF) {
      std::string path = "";
      std::cout << "(cost: " << result[i].first << "):" << std::endl;
      int j = i;

      while (j != n) {
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

void kruskalMenu(Graph* graph) {
  std::vector<std::pair<int, int>> mst = algorithms::kruskal(graph);
  std::cout<< "\nEdges in the minimum cost spanning tree: " << std::endl;
  int totalCost = 0;

  for (std::pair<int, int> edge : mst) {
    totalCost += graph->weight(edge.first, edge.second);
    std::cout << "  " << graph->label(edge.first) << " - " << graph->label(edge.second) << " ("
      << graph->weight(edge.first, edge.second) << ")" << std::endl;
  }
  std::cout << "Total cost: " << totalCost << std::endl;
}

void graphColoringMenu(Graph* graph) {
  std::vector<std::vector<int>> colors = algorithms::graphColoring(graph);
  int i = 1;
  std::cout << "\nSets of vertices colored with different colors:" << std::endl;

  for (std::vector<int> color : colors) {
    if (color.size() != 0) {
      std::cout << "  " << i << ": ";
      for (int v : color) {
        std::cout<< graph->label(v) << ", ";
      }
      std::cout << std::endl;
      i++;
    }
  }
}

void hamiltonMenu(Graph* graph){
  std::vector<int> path = algorithms::hamilton(graph);

  if (path.empty()) {
    std::cout << "\nA Hamiltonian cycle does not exist for this graph." << std::endl;
  } else {
    std::cout << "\nShortest Hamiltonian cycle: " << std::endl;
    
    for (int n : path) {
      std::cout << graph->label(n) << " - ";
    }
    std::cout << graph->label(path[0]) << std::endl;
  }
}
