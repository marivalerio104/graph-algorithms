#include "Heap.hpp"

Heap::Heap() { last = 0; }

void Heap::insert(pair<int, int> edge, int priority) {
  last++;
  vector[last] = HeapCell{edge, priority};
  int i = last;

  // Exchange with its father until it is greater or equal than it
  while(i/2 != 0 && priority < vector[i/2].priority) {
    HeapCell temp = vector[i/2];
    vector[i/2] = vector[i];
    vector[i] = temp;
    i = i/2;
  }
}

pair<int, int> Heap::remove() {
  pair<int, int> deleted = vector[1].edge;
  vector[1] = vector[last];
  last--;
  int i = 1;

  // Exchange with its smallest child until it is smaller or equal than them
  while((2*i <= last && vector[2*i].priority < vector[i].priority) ||
      (2*i+1 <= last && vector[2*i+1].priority < vector[i].priority)) {
    int child = (vector[2*i].priority <= vector[2*i+1].priority) ? 2*i : 2*i+1
    HeapCell temp = vector[child];
    vector[child] = vector[i];
    vector[i] = temp;
    i = child;
  }
  return deleted;
}

int Heap::numElements() { return last; }
