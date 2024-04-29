#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <string>
namespace ariel
{
    class Algorithms
    {
    public:
        // Algorithms for graph operations
        static bool isConnected(const Graph &g);                     // Check if graph is connected
        static int shortestPath(const Graph &g, int start, int end); // Find shortest path between vertices
        static bool isContainsCycle(const Graph &g);                 // Check if graph contains a cycle
        static bool isContainsCycleUtil(const Graph &g, int v, std::vector<bool> &visited, std::vector<int> &parent);
        static std::string isBipartite(const Graph &g);                     // Check if graph is bipartite
    };
}

#endif // ALGORITHMS_HPP
