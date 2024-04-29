#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
namespace ariel{
class Algorithms {
public:
    // Algorithms for graph operations
    static bool isConnected(const Graph& g); // Check if graph is connected
    static int shortestPath(const Graph& g, int start, int end); // Find shortest path between vertices
    static bool isContainsCycle(const Graph& g); // Check if graph contains a cycle
    static bool isBipartite(const Graph& g); // Check if graph is bipartite
};
}

#endif // ALGORITHMS_HPP
