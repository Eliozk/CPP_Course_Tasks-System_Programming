#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

namespace ariel {
    class Graph {
    private:
        std::vector<std::vector<int>> adjacencyMatrix; // Declaration of adjacencyMatrix

    public:
        // Constructor, destructor, and other member function declarations
        Graph();
        ~Graph();
        void loadGraph(const std::vector<std::vector<int>>& matrix);
        void printGraph() const;
        const std::vector<std::vector<int>>& getAdjacencyMatrix() const;
    };
} // namespace ariel

#endif // GRAPH_HPP
