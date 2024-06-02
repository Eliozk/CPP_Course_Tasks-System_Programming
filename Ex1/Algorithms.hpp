
#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <string>
#include <vector>

// ID - 208762765
// GMAIL - kolanielioz@gmail.com
namespace ariel
{
    using namespace std;

    class Algorithms
    {
    public:
        // Algorithms for graph operations
        // static vector<int> BellmanFordAlgo(const Graph &graph, int source, int dest); // bellmanford algo
        static void printCycle(const vector<int> &cyclePath);
        static bool isBipartiteDFS(vector<vector<int>> &graph, int current, vector<int> &visited, vector<int> &group_A, vector<int> &group_B, int group_num);
        static void DFS(vector<vector<int>> &tempMatrix, size_t vertex, bool connected[]);
        static void transpose(vector<vector<int>> &tempMatrix);
        static bool findCycleDFS(const Graph &graph, int vertex, int parent, vector<bool> &visited, std::vector<int> &cyclepath);
        static bool isConnected(const Graph &g);                        // Check if graph is connected
        static string shortestPath(const Graph &g, int start, int end); // Find shortest path between vertices
        static bool isContainsCycle(const Graph &g);                    // Check if graph contains a cycle
        static string isBipartite(const Graph &g);                      // Check if graph is bipartite
        // Utility function for checking cycle using DFS traversal
        // static bool isCyclicUtil(int v, vector<bool> &visited, int parent, const Graph &g, vector<int> &cycleVertices);
        static string negativeCycle(const Graph &graph); // Added function declaration
    };
}

#endif // ALGORITHMS_HPP
