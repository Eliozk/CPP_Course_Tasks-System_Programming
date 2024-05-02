#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

namespace ariel
{
    using namespace std;
    class Graph
    {
    private:
        vector<vector<int>> adjacencyMatrix; // Declaration of adjacencyMatrix

    public:
        // Constructor, destructor, and other member function declarations
        Graph();
        ~Graph();
        void loadGraph(const vector<vector<int>> &matrix);
        void printGraph() const;
        // Function to count the number of edges in a graph's adjacency matrix
        int countEdges(const vector<vector<int>> &matrix) const;
        const vector<vector<int>> &getAdjacencyMatrix() const;
          // Declare the getNeighbors function
        vector<int> getNeighbors(int vertex) const;
        Graph getTranspose(const Graph& g);
        static int getSizeOfGraph(Graph g);
        bool isConnected(size_t start, size_t end) const;
    };
} // namespace ariel

#endif // GRAPH_HPP
