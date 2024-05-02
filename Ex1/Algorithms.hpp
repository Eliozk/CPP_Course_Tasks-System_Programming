#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <string>
namespace ariel
{
    using namespace std;
    class Algorithms
    {
    public:
        // Algorithms for graph operations
        static bool isConnected(const Graph &g);                     // Check if graph is connected
        static string shortestPath(const Graph &g, int start, int end); // Find shortest path between vertices
        static bool isContainsCycle(const Graph &g);                 // Check if graph contains a cycle
        static string isBipartite(const Graph &g);                     // Check if graph is bipartite
    };
}

#endif // ALGORITHMS_HPP