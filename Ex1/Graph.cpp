#include "Graph.hpp"
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <stdexcept>

using ariel::Graph;
// ID - 208762765
// GMAIL - kolanielioz@gmail.com
namespace ariel
{
    using namespace std;

    /**
     * @brief Constructor for the Graph class.
     * Initializes the number of vertices and edges to zero.
     */
    Graph::Graph() : numVertices(0), numEdges(0)
    {
        // Initialize any member variables or perform other setup tasks here
    }

    // Destructor definition (optional)
    Graph::~Graph()
    {
        // Perform any cleanup tasks here, such as releasing resources
    }

    /**
     * @brief Loads the graph from an adjacency matrix.
     *
     * @param matrix The adjacency matrix representing the graph.
     * @throws std::invalid_argument if the matrix is not square.
     */
    void Graph::loadGraph(const vector<vector<int>> &matrix)
    {
        if (matrix.empty())
        {
            adjacencyMatrix.clear();
            numVertices = 0;
            numEdges = 0;
            return;
        }
        if (matrix.size() != matrix[0].size())
        {
            throw invalid_argument("Invalid graph: Graph is not a square matrix.");
        }
        adjacencyMatrix = matrix;
        numVertices = matrix.size();
        numEdges = countEdges(matrix);
    }

    /**
     * @brief Gets the number of vertices in the graph.
     *
     * @return int The number of vertices.
     */
    int Graph::getNumVertices() const
    {
        return numVertices;
    }

    /**
     * @brief Gets the number of edges in the graph.
     *
     * @return int The number of edges.
     */
    int Graph::getNumEdges() const
    {
        return numEdges;
    }

    /**
     * @brief Prints the graph details.
     * Outputs the number of vertices and edges to the console.
     */
    void Graph::printGraph() const
    {
        cout << "Graph with " << getNumVertices() << " vertices and "
             << getNumEdges() << " edges." << endl;
        // Uncomment the following code to print the adjacency matrix
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

    /**
     * @brief Counts the number of edges in a graph's adjacency matrix.
     *
     * @param matrix The adjacency matrix of the graph.
     * @return int The number of edges.
     */
    int Graph::countEdges(const vector<vector<int>> &matrix) const
    {
        int edges = 0;
        if (matrix.size() != 0)
        {
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
        }
        return edges;
    }

    /**
     * @brief Gets the neighbors of a given vertex.
     *
     * @param vertex The vertex to get the neighbors for.
     * @return vector<int> A vector of neighboring vertex indices.
     */
    vector<int> Graph::getNeighbors(int vertex) const
    {
        vector<int> neighbors;
        const vector<vector<int>> newMatrix = this->getAdjacencyMatrix(); // Access adjacencyMatrix
        if (vertex >= 0 && vertex < newMatrix.size())
        {
            const vector<int> &row = newMatrix[static_cast<size_t>(vertex)];
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

    /**
     * @brief Returns the transpose of the given graph.
     *
     * @param g The original graph.
     * @return Graph The transposed graph.
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

    /**
     * @brief Gets the adjacency matrix of the graph.
     *
     * @return const vector<vector<int>>& The adjacency matrix.
     */
    const vector<vector<int>> &Graph::getAdjacencyMatrix() const
    {
        return adjacencyMatrix;
    }

    /**
     * @brief Gets the size of the graph.
     *
     * @param g The graph object.
     * @return int The size of the graph (number of vertices).
     */
    int getSizeOfGraph(Graph g)
    {
        const vector<vector<int>> &matrix = g.getAdjacencyMatrix();
        int size = matrix.size();
        return size;
    }

    /**
     * @brief Checks if there is a path between two vertices.
     *
     * @param start The starting vertex.
     * @param end The ending vertex.
     * @return bool True if there is a path, false otherwise.
     */
    bool Graph::isConnected(size_t start, size_t end) const
    {
        if (start < 0 || end < 0 || start >= this->adjacencyMatrix.size() || end >= adjacencyMatrix.size())
        {
            return false; // Invalid vertices
        }

        vector<bool> visited(adjacencyMatrix.size(), false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            size_t current = (size_t)q.front();
            q.pop();

            if (current == end)
            {
                return true; // Found a path between start and end
            }

            for (size_t i = 0; i < adjacencyMatrix[current].size(); ++i)
            {
                if (adjacencyMatrix[current][i] != 0 && !visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }

        return false; // No path found between start and end
    }

    int Graph::getEdgeWeight(int src, int dest) const
    {
        return adjacencyMatrix[src][dest];
    }

} // namespace ariel
