#include "AlgorithmsUtils.hpp"

int node(Graph* graph, char label) {
   int n = graph->firstNode();

   while(n && (graph->label(n) != label)) {
      n = graph->nextNode(n);
   }
   return n;
}
