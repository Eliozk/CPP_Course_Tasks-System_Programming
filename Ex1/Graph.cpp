#include "Graph.hpp"
#include <iostream>

using ariel::Graph;


namespace ariel {

    // Constructor definition
    Graph::Graph() {
        // Initialize any member variables or perform other setup tasks here
    }

    // Destructor definition
    Graph::~Graph() {
        // Perform any cleanup tasks here, such as releasing resources
    }

    // Function to load the graph from an adjacency matrix
    void Graph::loadGraph(const std::vector<std::vector<int>>& matrix) {
        adjacencyMatrix = matrix;
    }

    // Function to print the graph
    void Graph::printGraph() const {
        for (const auto& row : adjacencyMatrix) {
            std::cout << "(";
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << ")" << std::endl;
        }
    }

    // Getter for the adjacency matrix
    const std::vector<std::vector<int>>& Graph::getAdjacencyMatrix() const {
        return adjacencyMatrix;
    }

} // namespace ariel
