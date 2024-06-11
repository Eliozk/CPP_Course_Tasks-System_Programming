#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <ostream>
// ID - 208762765
// GMAIL - kolanielioz@gmail.com
namespace ariel
{
    using namespace std;

    class Graph
    {
    private:
        vector<vector<int>> adjacencyMatrix; // Adjacency matrix representation of the graph
        int numVertices;                     // Number of vertices in the graph
        int numEdges;                        // Number of edges in the graph

    public:
        // Constructors
        Graph();
        Graph(int size); // Constructor with size parameter

        // Accessor methods
        int getNumVertices() const;
        int getNumEdges() const;

        // Method to load the graph from an adjacency matrix
        void loadGraph(const vector<vector<int>> &matrix);

        // Method to print the graph
        void printGraph() const;

        // Method to count the number of edges in a graph's adjacency matrix
        int countEdges(const vector<vector<int>> &matrix) const;

        // Method to get the adjacency matrix
        const vector<vector<int>> &getAdjacencyMatrix() const;

        // Method to get the neighbors of a vertex
        vector<int> getNeighbors(int vertex) const;

        // Method to get the transpose of the graph
        Graph getTranspose(const Graph &g);

        // Method to get the size of the graph
        static int getSizeOfGraph(Graph g);

        // Method to check if there is a path between two vertices
        bool isConnected(size_t start, size_t end) const;

        // Method to get the weight of an edge
        int getEdgeWeight(int src, int dest) const;

        // Overloaded operators for graph operations
        Graph operator+(const Graph &graph) const;
        void operator+=(const Graph &graph); // x += y => x = x + y
        void operator+();
        void operator-();
        Graph operator-(const Graph &graph) const;
        void operator-=(const Graph &graph); // x -= y => x = x - y
        void operator*(int scalar);          // x * scalar on the same graph (x)

        // Prefix increment/decrement operators
        Graph &operator++(); // ++graph
        Graph &operator--(); // --graph

        // Postfix increment/decrement operators
        Graph operator++(int); // graph++
        Graph operator--(int); // graph--

        // Comparison operators
        bool operator==(const Graph &other) const;
        bool operator!=(const Graph &other) const;
        bool operator<(const Graph &other) const; // boolean: is g2 < g1?
        bool operator<=(const Graph &other) const;
        bool operator>(const Graph &other) const; // boolean: is g2 > g1?
        bool operator>=(const Graph &other) const;

        // Operator for graph multiplication
        Graph operator*(const Graph &other) const; // g3 = g2 * g1

        // Friend function to overload the << operator for outputting the graph and grant access to members(vertices etc..)
        friend ostream &operator<<(ostream &os, const Graph &graph);
       
    };

} // namespace ariel

#endif // GRAPH_HPP
