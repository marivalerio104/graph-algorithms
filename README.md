# graph-algorithms

This repository contains custom implementations of **graph** and **heap** data structures, as well as several fundamental algorithms in graph theory and optimization.  

## Implemented Algorithms

- **Dijkstra's Algorithm** – Finds the shortest path from a source node to all other nodes in a weighted graph with non-negative weights.
- **Kruskal's Algorithm (with Heap)** – Computes the Minimum Spanning Tree (MST) using a heap to efficiently manage edges.
- **Graph Coloring** – Assigns colors to vertices such that no two adjacent vertices share the same color, using a brute-force approach.
- **Minimum-Cost Hamiltonian Cycle** – Solves the Traveling Salesman Problem by searching for the minimum-cost Hamiltonian cycle using branch and bound.

---

## 📖 User Manual

### Software Requirements

1. Have **g++** installed.  
2. Have **make** installed.  
3. Compile on **Linux**.

If you don’t have `g++` or `make` installed, run the following commands:

```bash
sudo apt update
sudo apt install g++ make
```

### Compilation

The compilation of the program is done via a Makefile.

1. Open the project’s root folder in the terminal.
2. To compile the program, run the command:

```bash
make
```

3. To run the program, run the command:

```bash
make run
```

---

This project was developed as part of the course **Data Structures and Algorithms**.
