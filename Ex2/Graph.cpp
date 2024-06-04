#include "Graph.hpp"
#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <stdexcept>

// ID - 208762765
// GMAIL - kolanielioz@gmail.com
using ariel::Graph;
namespace ariel
{
    
    using namespace std;

    /**
     * @brief Constructor for the Graph class.
     * Initializes the number of vertices and edges to zero.
     */
    Graph::Graph() : numVertices(0), numEdges(0)
    {
    }
    // constructor to init graph in desired size.
    Graph::Graph(int size) : numVertices(size), numEdges(0)
    {
        adjacencyMatrix.resize(size, vector<int>(size, 0));
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

    //******************************************Operators for Task 2*****************************************************************

    // Operator+ declaration for adding bet
    Graph Graph::operator+(const Graph &graph) const
    {
        const vector<vector<int>> &other = graph.getAdjacencyMatrix();
        int size = adjacencyMatrix.size();
        if (size != other.size() || size != other[0].size())
        {
            throw invalid_argument("Graph sizes do not match!(operator+)");
        }
        Graph res(size);
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                res.adjacencyMatrix[i][j] = adjacencyMatrix[i][j] + other[i][j];
            }
        }
        return res;
    }
 /**
     * @brief Overloaded compound addition operator to add another graph element-wise to the current graph.
     * @details This operator adds the corresponding elements of the adjacency matrices of two graphs and modifies the current graph in place.
     *
     * @param graph The graph to be added.
     * @throws std::invalid_argument if the sizes of the adjacency matrices do not match.
     */
    void Graph::operator+=(const Graph &graph)
    {
        const vector<vector<int>> &other = graph.getAdjacencyMatrix();
        int size = adjacencyMatrix.size();
        if (size != other.size() || size != other[0].size())
        {
            throw invalid_argument("Graph sizes do not match!(operator+=)");
        }

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                this->adjacencyMatrix[i][j] += other[i][j];
            }
        }
    }
    // operator + onary
    void Graph::operator+()
    {
        *this * (+1);
    }
    // operator - onary
    void Graph::operator-()
    {
        if (this->adjacencyMatrix.empty() || this->numVertices == 0)
        {
            throw invalid_argument("Graph not initialized (operator-())");
        }
        *this * (-1); // return the same adjacencyMatrix the multiplication with scalar -1.
    }
 /**
     * @brief Overloaded subtraction operator to subtract two graphs element-wise.
     * @details This operator subtracts the corresponding elements of the adjacency matrices of two graphs and returns a new graph as the result.
     *
     * @param graph The graph to be subtracted.
     * @return A new Graph object representing the element-wise difference of the two graphs.
     * @throws std::invalid_argument if the sizes of the adjacency matrices do not match.
     */
    Graph Graph::operator-(const Graph &graph) const
    {
        const vector<vector<int>> &other = graph.getAdjacencyMatrix();
        int size = adjacencyMatrix.size();
        if (size != other.size() || size != other[0].size())
        {
            throw invalid_argument("Graph sizes do not match!(operator-)");
        }
        Graph res(size);
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                res.adjacencyMatrix[i][j] = adjacencyMatrix[i][j] - other[i][j];
            }
        }
        return res;
    }
    /**
     * @brief Overloaded compound subtraction operator to subtract another graph element-wise from the current graph.
     * @details This operator subtracts the corresponding elements of the adjacency matrices of two graphs and modifies the current graph in place.
     *
     * @param graph The graph to be subtracted.
     * @throws std::invalid_argument if the sizes of the adjacency matrices do not match.
     */
    void Graph::operator-=(const Graph &graph)
    {
        const vector<vector<int>> &other = graph.getAdjacencyMatrix();
        int size = adjacencyMatrix.size();
        if (size != other.size() || size != other[0].size())
        {
            throw invalid_argument("Graph sizes do not match!(operator-=)");
        }
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                this->adjacencyMatrix[i][j] -= other[i][j];
            }
        }
        // return *this;
    }
  /**
     * @brief Overloaded multiplication operator to multiply the adjacency matrices of two graphs.
     * @details This operator multiplies the adjacency matrix of the current graph with the adjacency matrix of another graph.
     * It performs matrix multiplication where the element at position (i, j) in the resulting matrix is the sum of the products
     * of corresponding elements from the rows of the first matrix and the columns of the second matrix.
     *
     * @param other The graph whose adjacency matrix will be multiplied with the adjacency matrix of the current graph.
     * @return A new Graph object that represents the result of the matrix multiplication.
     * @throws std::invalid_argument if the sizes of the adjacency matrices do not match.
     */
    void Graph::operator*(int scalar)
    {

        if (this->adjacencyMatrix.empty() || this->numVertices == 0)
        {
            throw invalid_argument("Graph not initialized (operator*)");
        }
        int size = adjacencyMatrix.size();

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                this->adjacencyMatrix[i][j] *= scalar;
            }
        }
    }
    //operator to check equivalance of 2 graphs, including checks of the vertices and weights
    bool Graph::operator==(const Graph &graph) const
    {
        const vector<vector<int>> &other = graph.getAdjacencyMatrix();
        if (this->adjacencyMatrix.empty() && other.empty())
        {
            return true;
        }
        if (!this->adjacencyMatrix.empty() && other.empty() || this->adjacencyMatrix.empty() && !other.empty())
        {
            return false;
        }
        int size = this->adjacencyMatrix.size();
        if (size != other.size() || size != other[0].size())
        {
            return false;
        }
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                if (this->adjacencyMatrix[i][j] != other[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
  //operator to check equivalance of 2 graphs, including checks of the vertices and weights.
    bool Graph::operator!=(const Graph &graph) const
    {
        return !(*this == graph);
    }

    // Prefix increment operator (++graph)
    Graph &Graph::operator++()
    {
        if (this->adjacencyMatrix.empty())
        {
            throw invalid_argument("Graph is empty and cannot be incremented (operator++)");
        }

        int size = this->adjacencyMatrix.size();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                if (this->adjacencyMatrix[i][j] != 0)
                {
                    this->adjacencyMatrix[i][j]++;
                }
            }
        }

        // Optionally update the number of edges if necessary
        this->numEdges = countEdges(this->adjacencyMatrix);
        return *this;
    }

    // Prefix decrement operator (--graph)
    Graph &Graph::operator--()
    {
        if (this->adjacencyMatrix.empty())
        {
            throw invalid_argument("Graph is empty and cannot be decremented (operator--)");
        }

        int size = this->adjacencyMatrix.size();
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                if (this->adjacencyMatrix[i][j] != 0)
                {
                    this->adjacencyMatrix[i][j]--;
                }
            }
        }
        // Optionally update the number of edges if necessary
        this->numEdges = countEdges(this->adjacencyMatrix);
        return *this;
    }

    // Postfix increment operator (graph++)
    Graph Graph::operator++(int)
    {
        Graph temp = *this; // Make a copy of the current object
        ++(*this);          // Use the prefix increment operator to increment the current object
        return temp;        // Return the copy (original state)
    }

    // Postfix decrement operator (graph--)
    Graph Graph::operator--(int)
    {
        Graph temp = *this; // Make a copy of the current object
        --(*this);          // Use the prefix decrement operator to decrement the current object
        return temp;        // Return the copy (original state)
    }

    /**
     * @brief Overloaded comparison operator > to check if one graph is greater than another.
     * @details A graph G2 is considered greater than graph G1 if one of the following conditions is true:
     * - G1 is empty and G2 is not empty.
     * - Both G1 and G2 are not empty, G2 has the same number of edges and same weights of edges as G1,
     * but G2's adjacency matrix size is greater than G1's size.
     * If none of the above conditions are met, G2 is not greater than G1.
     *
     * @param other The graph to compare with.
     * @return True if G2 is greater than G1, false otherwise.
     */
    bool Graph::operator>(const Graph &other) const // if g2>g1
    {
        const vector<vector<int>> &g2 = this->adjacencyMatrix; // Get reference to adjacency matrix of *this
        const vector<vector<int>> &g1 = other.adjacencyMatrix; // Get reference to adjacency matrix of other

        // Check if g2 is empty and g1 is not
        if (g2.empty() && !g1.empty())
        {
            return false;
        }

        // Check if either g2 is not empty and g1 is empty, or both are empty
        if ((!g2.empty() && g1.empty()) || (g2.empty() && g1.empty()))
        {
            return true;
        }

        int edgesThis = countEdges(g2);
        int edgesOther = countEdges(g1);

        // If edges of g2 are less than edges of g1, it cannot contain g1
        if (edgesThis < edgesOther)
        {
            return false;
        }

        int sizeOther = g1.size();
        int size = g2.size();

        // If the size of g2 is less than g1, g2 is not greater
        if (size < sizeOther)
        {
            return false;
        }

        // Now check if g1 is a subgraph of g2
        for (size_t i = 0; i < sizeOther; i++)
        {
            for (size_t j = 0; j < sizeOther; j++)
            {
                if ( other.getEdgeWeight(i,j) != 0 && this->getEdgeWeight(i,j) == 0){
                  return false;
                }
            }
        }
        //this contain other.
        return true; // g1 is not a subgraph of g2
    }
    /**
     * @brief Overloaded comparison operator >= to check if one graph is greater than or equal to another.
     * @details A graph G2 is considered greater than or equal to graph G1 if G2 is greater than G1 or if G2 is equal to G1.
     *
     * @param other The graph to compare with.
     * @return True if G2 is greater than or equal to G1, false otherwise.
     */
    bool Graph::operator>=(const Graph &other) const
    {
        return *this > other || *this == other;
    }
    /**
     * @brief Overloaded comparison operator < to check if one graph is less than another.
     * @details A graph G1 is considered less than graph G2 if G2 is greater than G1 or if G2 is equal to G1.
     *
     * @param other The graph to compare with.
     * @return True if G1 is less than G2, false otherwise.
     */
    bool Graph::operator<(const Graph &other) const
    {
        return !(*this >= other);
    }
    /**
     * @brief Overloaded comparison operator <= to check if one graph is less than or equal to another.
     * @details A graph G1 is considered less than or equal to graph G2 if G1 is not greater than or equal to G2 or if G1 is equal to G2.
     *
     * @param other The graph to compare with.
     * @return True if G1 is less than or equal to G2, false otherwise.
     */
    bool Graph::operator<=(const Graph &other) const
    {
        return !(*this < other) || (*this == other);
    }

    /**
     * @brief Overloaded multiplication operator to multiply the adjacency matrices of two graphs.
     * @details This operator multiplies the adjacency matrix of the current graph with the adjacency matrix of another graph.
     * It performs matrix multiplication where the element at position (i, j) in the resulting matrix is the sum of the products
     * of corresponding elements from the rows of the first matrix and the columns of the second matrix.
     *
     * @param other The graph whose adjacency matrix will be multiplied with the adjacency matrix of the current graph.
     * @return A new Graph object that represents the result of the matrix multiplication.
     * @throws std::invalid_argument if the sizes of the adjacency matrices do not match.
     */
    Graph Graph::operator*(const Graph &other) const
    {
        const vector<vector<int>> &g1 = this->adjacencyMatrix;
        const vector<vector<int>> &g2 = other.adjacencyMatrix;

        // Check if the sizes of the adjacency matrices match
        if (g1.size() != g2.size() || g1.size() != g2[0].size())
        {
            throw invalid_argument("Graph sizes do not match! (operator*)");
        }

        // Initialize the result graph with the same size
        Graph result(g1.size());
        vector<vector<int>> &resMatrix = result.adjacencyMatrix;

        // Perform matrix multiplication
        for (size_t i = 0; i < g1.size(); ++i)
        {
            for (size_t j = 0; j < g1.size(); ++j)
            {
                resMatrix[i][j] = 0; // Initialize the result matrix element
                for (size_t k = 0; k < g1.size(); ++k)
                {
                    resMatrix[i][j] += g1[i][k] * g2[k][j];
                }
            }
        }

        return result;
    }

    ostream &operator<<(ostream &os, const Graph &graph)
    {
        for (int i = 0; i < graph.numVertices; ++i)
        {
            for (int j = 0; j < graph.numVertices; ++j)
            {
                os << graph.adjacencyMatrix[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

} // namespace ariel
