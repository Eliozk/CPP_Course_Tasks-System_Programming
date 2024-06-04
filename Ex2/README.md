# Graph Operations Project
## Author
My name is Elioz Kolani
my email is kolanielioz@gmail.com

## Overview

This project is a C++ implementation of a graph data structure with various operations including addition, subtraction, and comparison of graphs. It also includes unit tests to validate the functionality of the implemented operations.

## File Structure

+ Graph.hpp: Header file for the Graph class.

+ Graph.cpp: Implementation of the Graph class.

+ Algorithms.hpp: Header file for graph-related algorithms.

+ Algorithms.cpp: Implementation of graph-related algorithms.
    
+ Demo.cpp: Main file to demonstrate and test graph operations.
    
+ Test.cpp: Unit tests using the doctest framework.

+ Makefile: Makefile to build the project and run tests.


## Graph Class

The Graph class provides various operations on graphs:

+ operator+: Add two graphs (graph1 + graph2). This operation creates a new graph where each cell is the sum of the corresponding cells in the two input graphs.

+ operator-: Subtract one graph from another (graph1 - graph2). This operation creates a new graph where each cell is the difference of the corresponding cells in the two input graphs.

+ operator+=: Add a graph to the current graph (graph1 += graph2). This operation updates the current graph by adding the corresponding cells of the other graph.
    
+ operator-=: Subtract a graph from the current graph (graph1 -= graph2). This operation updates the current graph by subtracting the corresponding cells of the other graph.
    
+ operator==: Check if two graphs are equal (graph1 == graph2). This operation returns true if all corresponding cells in the two graphs are equal.
    
+ operator!=: Check if two graphs are not equal (graph1 != graph2). This operation returns true if any corresponding cells in the two graphs are not equal.
    
+ operator<: Compare two graphs (graph1 < graph2). This operation returns true if the current graph is less than the other graph based on a predefined comparison criteria (e.g., sum of all cells).
    
+ operator<=: Compare two graphs (graph1 <= graph2). This operation returns true if the current graph is less than or equal to the other graph based on a predefined comparison criteria.
    
+ operator>: Compare two graphs (graph1 > graph2). This operation returns true if the current graph is greater than the other graph based on a predefined comparison criteria.
    
+ operator>=: Compare two graphs (graph1 >= graph2). This operation returns true if the current graph is greater than or equal to the other graph based on a predefined comparison criteria.
    
+ operator+():  This function adding sign plus to each element of the adjancey matrix of the graph.

+ operator-():  This function multiply each element of the graph by (-1).

## Running Tests

To run the tests, simply execute:
+ make runtest


The Test.cpp file includes comprehensive tests for the Graph class operations using the doctest framework.


