# Graph Algorithms in C++

## Author
My name is Elioz Kolani  
My email is kolanielioz@gmail.com

## Overview

This repository contains implementations of various graph algorithms in C++. The code provides functionalities such as depth-first search (DFS), transposing matrices, checking graph connectivity, finding cycles in graphs, checking bipartiteness, and detecting negative cycles using the Bellman-Ford algorithm.

## File Structure
### Ex1 
+ **Graph.hpp**: Header file for the Graph class.
+ **Graph.cpp**: Implementation of the Graph class, including loading graphs from adjacency matrices, finding neighbors, transposing graphs, and checking connectivity.
+ **Algorithms.hpp**: Header file for graph-related algorithms.
+ **Algorithms.cpp**: Implements graph algorithms like DFS traversal, finding paths, checking bipartiteness, and detecting negative cycles.
+ **TestCounter.cpp**: Includes functions for unit testing using the Doctest library.
+ **Test.cpp**: Contains test cases for graph algorithms using Doctest.
+ **Demo.cpp**: Main file to demonstrate and test graph operations.
+ **Makefile**: Makefile to build the project and run tests.
### Ex2
    contains the same files as in Ex1 except Test.cpp which contains various tests for Graph operators.
## Graph Algorithms

The repository includes the following graph algorithms:

+ **Depth-First Search (DFS)**: Implemented in `Algorithms.cpp`.
+ **Transposing Matrices**: Functions for transposing graphs are in `Graph.cpp`.
+ **Connectivity Check**: Implemented in `Algorithms.cpp` using DFS.
+ **Cycle Detection**: `Algorithms.cpp` includes functions to detect cycles in graphs.
+ **Bipartiteness Check**: `Algorithms.cpp` implements a method to check if a graph is bipartite.
+ **Negative Cycle Detection**: Implemented using the Bellman-Ford algorithm in `Algorithms.cpp`.

## Running 
To run execute:
+  `make run`
To run the tests, simply execute:
+ `make runtest`


The `Test.cpp` file includes comprehensive tests for the graph algorithms using the Doctest framework.
