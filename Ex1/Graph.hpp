#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

namespace ariel
{
    class Graph
    {
    private:
        std::vector<std::vector<int>> adjacencyMatrix; // Declaration of adjacencyMatrix

    public:
        // Constructor, destructor, and other member function declarations
        Graph();
        ~Graph();
        void loadGraph(const std::vector<std::vector<int>> &matrix,int numOfGraph);
        void printGraph() const;
        // Function to count the number of edges in a graph's adjacency matrix
        int countEdges(const std::vector<std::vector<int>> &matrix) const;
        const std::vector<std::vector<int>> &getAdjacencyMatrix() const;
          // Declare the getNeighbors function
        std::vector<int> getNeighbors(int vertex) const;
    };
} // namespace ariel

#endif // GRAPH_HPP
