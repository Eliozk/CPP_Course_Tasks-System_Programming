#include "Graph.hpp"
#include <iostream>
#include <list>
#include <queue>

using ariel::Graph;

namespace ariel
{
    using namespace std;
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

    void Graph::loadGraph(const vector<vector<int>> &matrix)
    {
        if (matrix.size() != matrix[0].size())
        {
            throw invalid_argument("Invalid graph: Graph is not a square matrix.");
        }
        adjacencyMatrix = matrix;
    }

    // Function to print the graph
    void Graph::printGraph() const
    {
        int edges = countEdges(adjacencyMatrix);
        cout << "Graph with " << adjacencyMatrix.size() << " vertices and "
             << edges << " edges." << endl;
        for (const auto &row : adjacencyMatrix)
        {
            cout << "(";
            for (int val : row)
            {
                cout << val << " ";
            }
            cout << ")" << endl;
        }
    }

    // Function to count the number of edges in a graph's adjacency matrix
    int Graph::countEdges(const vector<vector<int>> &matrix) const
    {
        int edges = 0;
        for (const auto &row : matrix)
        {
            for (int value : row)
            {
                if (value != 0)
                { // Consider non-zero values as directed edges
                    edges++;
                }
            }
        }
        return edges;
    }

//  vector<int> Graph::getNeighbors(int vertex) const
// {
//     vector<int> neighbors;
//     const vector<vector<int>>& matrix = getAdjacencyMatrix(); // Access adjacencyMatrix
//     if (vertex >= 0 && static_cast<size_t>(vertex) < matrix.size())
//     {
//         const vector<int>& row = matrix[static_cast<size_t>(vertex)];
//         for (size_t i = 0; i < row.size(); ++i)
//         {
//             if (row[i] > 0) // Check if the value is greater than 0 to represent an edge
//             {
//                 neighbors.push_back(static_cast<int>(i));
//             }
//         }
//     }
//     return neighbors;
// }
vector<int> Graph::getNeighbors(int vertex) const
{
    vector<int> neighbors;
    const vector<vector<int>> newMatrix = this->getAdjacencyMatrix(); // Access adjacencyMatrix
    if (vertex >= 0 && vertex < newMatrix.size())
    {
        const vector<int>& row = newMatrix[static_cast<size_t>(vertex)];
        for (size_t i = 0; i < row.size(); ++i)
        {
            if (row[i] > 0) // Check if the value is greater than 0 to represent an edge
            {
                neighbors.push_back(i);
            }
        }
    }
    return neighbors;
}


    /*
     * Function that returns reverse (or transpose) of this graph
     */
    Graph Graph::getTranspose(const Graph &g)
    {
        const vector<vector<int>> &matrix = g.getAdjacencyMatrix();
        vector<int>::size_type size = matrix.size();
        vector<vector<int>> transposeMatrix(size, vector<int>(size, static_cast<vector<int>::size_type>(0)));

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                transposeMatrix[static_cast<vector<int>::size_type>(j)][static_cast<vector<int>::size_type>(i)] = matrix[static_cast<vector<int>::size_type>(i)][static_cast<vector<int>::size_type>(j)];
            }
        }

        Graph newTransposeGraph;
        newTransposeGraph.loadGraph(transposeMatrix);
        return newTransposeGraph;
    }

    // Getter for the adjacency matrix
    const vector<vector<int>> &Graph::getAdjacencyMatrix() const
    {
        return adjacencyMatrix;
    }
    int getSizeOfGraph(Graph g)
    {
        const vector<vector<int>> &matrix = g.getAdjacencyMatrix();
        int size = matrix.size();
        return size;
    }

     bool Graph::isConnected(size_t start, size_t end) const {
        if (start < 0 || end < 0 || start >= this->adjacencyMatrix.size() || end >= adjacencyMatrix.size()) {
            return false; // Invalid vertices
        }

        vector<bool> visited(adjacencyMatrix.size(), false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            size_t current = (size_t)q.front();
            q.pop();

            if (current == end) {
                return true; // Found a path between start and end
            }

            for (size_t i = 0; i < adjacencyMatrix[current].size(); ++i) {
                if (adjacencyMatrix[current][i] != 0 && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }

        return false; // No path found between start and end
    }
    

} // namespace ariel
