Graph Algorithms in C++
Overview
This repository contains implementations of various graph algorithms in C++. The code is structured to provide functionalities such as depth-first search (DFS), transposing matrices, checking graph connectivity, finding cycles in graphs, checking bipartiteness, and detecting negative cycles using the Bellman-Ford algorithm.

File Structure
Graph.cpp: Contains the implementation of the Graph class, including loading graphs from adjacency matrices, finding neighbors, transposing graphs, and checking connectivity.

Algorithms.cpp: Implements graph algorithms like DFS traversal, finding paths, checking bipartiteness, and detecting negative cycles.

TestCounter.cpp: Includes functions for unit testing using the Doctest library.

Test.cpp: Contains test cases for graph algorithms using Doctest.

main.cpp: Includes showcasing the usage of implemented graph algorithms.

Graph Algorithms
Depth-First Search (DFS): Implemented in Algorithms.cpp.

Transposing Matrices: Graph.cpp contains functions for transposing graphs.

Connectivity Check: Implemented in Algorithms.cpp using DFS.

Cycle Detection: Algorithms.cpp includes functions to detect cycles in graphs.

Bipartiteness Check: Algorithms.cpp implements a method to check if a graph is bipartite.

Negative Cycle Detection: Implemented using the Bellman-Ford algorithm in Algorithms.cpp.
