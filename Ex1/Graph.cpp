#include "Graph.hpp"
#include <iostream>

using ariel::Graph;

namespace ariel
{

    // Constructor definition
    Graph::Graph()
    {
        // Initialize any member variables or perform other setup tasks here
    }

    // Destructor definition
    Graph::~Graph()
    {
        // Perform any cleanup tasks here, such as releasing resources
    }

    // Function to load the graph from an adjacency matrix

    void Graph::loadGraph(const std::vector<std::vector<int>> &matrix,int numOfGraph)
    {
        if (matrix.size() != matrix[0].size())
        {
            throw std::invalid_argument("Invalid graph: Graph "+std::to_string(numOfGraph) +" is not a square matrix.");
        }
        adjacencyMatrix = matrix;
    }

    // Function to print the graph
    void Graph::printGraph() const
    {
        int edges = countEdges(adjacencyMatrix);
        std::cout << "Graph with " << adjacencyMatrix.size() << " vertices and "
                  << edges << " edges." << std::endl;
        for (const auto &row : adjacencyMatrix)
        {
            std::cout << "(";
            for (int val : row)
            {
                std::cout << val << " ";
            }
            std::cout << ")" << std::endl;
        }
    }

    // Function to count the number of edges in a graph's adjacency matrix
       int Graph::countEdges(const std::vector<std::vector<int>>& matrix) const {
        int edges = 0;
        for (const auto& row : matrix) {
            for (int value : row) {
                if (value != 0) {  // Consider non-zero values as directed edges
                    edges++;
                }
            }
        }
        return edges;
    }

    std::vector<int> Graph::getNeighbors(int vertex) const
    {
        std::vector<int> neighbors;
        std::vector<int> one(1, 1);
        const std::vector<std::vector<int>> &matrix = getAdjacencyMatrix(); // Access adjacencyMatrix
        if (vertex >= 0 && static_cast<std::vector<int>::size_type>(vertex) < matrix.size())
        {
            const std::vector<int> &row = matrix[static_cast<std::vector<int>::size_type>(vertex)];
            for (int i = 0; i < static_cast<int>(row.size()); ++i)
            {
                if (row[static_cast<std::vector<int>::size_type>(i)] == one[0])
                { // Assuming 1 represents an edge, adjust as needed
                    neighbors.push_back(i);
                }
            }
        }
        return neighbors;
    }

    // Getter for the adjacency matrix
    const std::vector<std::vector<int>> &Graph::getAdjacencyMatrix() const
    {
        return adjacencyMatrix;
    }

} // namespace ariel
