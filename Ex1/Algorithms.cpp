#include "Algorithms.hpp"
#include <algorithm>
#include "Graph.hpp"
#include <queue>
#include <sstream>
#include <iostream>
#include <limits>

// ID - 208762765
// GMAIL - kolanielioz@gmail.com
namespace ariel
{
    using namespace std;
    /**
     * Perform Depth-First Search (DFS) traversal starting from the specified vertex.
     *
     * @param tempMatrix The adjacency matrix representing the graph.
     * @param vertex The starting vertex for DFS traversal.
     * @param connectedVer An array indicating which vertices are connected.
     */
    void Algorithms::DFS(vector<vector<int>> &tempMatrix, size_t vertex, bool connectedVer[])
    {
        int size = tempMatrix.size();
        for (size_t i = 0; i < size; i++)
        {
            if (tempMatrix[vertex][i] != 0 && !connectedVer[i]) // 0 means there is no path, makes sure it also has not been visited
            {
                connectedVer[i] = true;           // There is a connection
                DFS(tempMatrix, i, connectedVer); // Call on the connected vertex
            }
        }
    }
    /**
     * Reset the boolean array to false and check if all elements are true before resetting.
     *
     * @param connected An array indicating connected vertices.
     * @param size The size of the array.
     * @return True if all elements were true before reset, false otherwise.
     */
    // Function which does both reseting the array to false and checks if all is true before reseting
    bool ResetAndCheckAllTrue(bool connected[], int size)
    {
        bool b = true;
        for (size_t i = 0; i < size; i++)
        {
            if (!connected[i])
            {
                b = false;
            }
            connected[i] = false;
        }
        return b; // if there is at least 1 false in the list it will return false, else true
    }
    /**
     * Transpose the given adjacency matrix.
     *
     * @param tempMatrix The adjacency matrix to transpose.
     */
    void Algorithms::transpose(vector<vector<int>> &tempMatrix)
    {
        int size = tempMatrix.size();

        // Perform transpose
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = i + 1; j < size; j++)
            { // itarate through the upper triangle
                swap(tempMatrix[i][j], tempMatrix[j][i]);
            }
        }
    }
    /**
     * Check if the graph is connected.
     *
     * @param g The graph to check.
     * @return True if the graph is connected, false otherwise.
     */
    bool Algorithms::isConnected(const Graph &g)
    {
        vector<vector<int>> tempMatrix = g.getAdjacencyMatrix(); // For editing copyd graph
        int size = tempMatrix.size();
        bool connected[size];

        ResetAndCheckAllTrue(connected, size); // For initializing all elements to false
        DFS(tempMatrix, 0, connected);         // Check DFS from first point

        if (!ResetAndCheckAllTrue(connected, size)) // Checks if all are true + resets all to false
        {
            return false;
        }

        transpose(tempMatrix);                      // Transpose the matrix
        DFS(tempMatrix, 0, connected);              // Check again DFS from first point
        if (!ResetAndCheckAllTrue(connected, size)) // Checks if all are true + resets all to false
        {
            return false;
        }
        return true;
    }
    /**
     * Find the shortest path between two vertices using the Bellman-Ford algorithm.
     *
     * @param g The graph to search for the shortest path.
     * @param start The starting vertex for the shortest path.
     * @param end The ending vertex for the shortest path.
     * @return The shortest path as a string or "-1" if no path exists.
     */
    string Algorithms::shortestPath(const Graph &g, int start, int end)
    {
        if (g.getNumVertices() == 0)
        {
            return "-1";
        }
        const vector<vector<int>> &matrix = g.getAdjacencyMatrix();
        size_t size = matrix.size(); // Use size_t for size

        // Check if start and end are valid vertices and if there is a path between them
        if (static_cast<size_t>(start) >= size || static_cast<size_t>(end) >= size || !g.isConnected(static_cast<size_t>(start), static_cast<size_t>(end)))
        {
            // cout << "No path from vertex " + to_string(start) + " to vertex " + to_string(end) + ", returned: "; // No path exists between start and end vertices
            return "-1";
        }

        vector<int> dist(size, numeric_limits<int>::max());
        vector<int> prev(size, -1);
        dist[static_cast<size_t>(start)] = 0;

        // Relax edges repeatedly
        for (size_t i = 0; i < size - 1; ++i)
        {
            for (size_t u = 0; u < size; ++u)
            {
                for (size_t v = 0; v < size; ++v)
                {
                    if (matrix[u][v] != 0 && dist[u] + matrix[u][v] < dist[v])
                    {
                        dist[v] = dist[u] + matrix[u][v];
                        prev[v] = u;
                    }
                }
            }
        }

        // Check for negative cycles
        for (size_t u = 0; u < size; ++u)
        {
            for (size_t v = 0; v < size; ++v)
            {
                if (matrix[u][v] != 0 && dist[u] + matrix[u][v] < dist[v])
                {
                    return "-1"; // Negative cycle detected, return "-1"
                }
            }
        }

        // Build the path string
        string path;
        int current = end;
        bool flagLast = false;
        while (current != start)
        {
            if (flagLast)
            {
                path = to_string(current) + "->" + path;
            }
            else
            {
                path = to_string(current) + path;
                flagLast = true;
            }
            current = prev[static_cast<size_t>(current)];
        }
        path = to_string(start) + "->" + path;

        return path;
    }
    /**
     * Helper function to perform Depth-First Search (DFS) for finding cycles in a graph.
     *
     * @param graph The graph to search for a cycle.
     * @param vertex The current vertex in the DFS traversal.
     * @param parent The parent vertex of the current vertex.
     * @param visited A boolean vector indicating visited vertices.
     * @param cyclePath A vector to store the cycle path if found.
     * @return True if a cycle is found, false otherwise.
     */
    bool Algorithms::findCycleDFS(const Graph &graph, int vertex, int parent, vector<bool> &visited, std::vector<int> &cyclepath)
    {
        visited[vertex] = true;                                     // set the current vertex as visited
        vector<vector<int>> adjMatrix = graph.getAdjacencyMatrix(); // access the adjacency matrix

        // iterate over the neighboors vertices of the current vertex
        for (size_t i = 0; i < adjMatrix[vertex].size(); ++i)
        {
            if (adjMatrix[vertex][i] != 0) // if there exists an edge from the current vertex to vertex i
            {
                if (!visited[i])
                {                                                           // if vertex i has not been visited yet
                    cyclepath.push_back(vertex);                            // add the current vertex to the cycle path
                    if (findCycleDFS(graph, i, vertex, visited, cyclepath)) // recursively search for a cycle starting from vertex i
                    {
                        return true; // if a cycle is found, return true
                    }
                    cyclepath.pop_back();
                }
                else if (i != parent)
                {                                // if vertex i has been visited and is not the parent vertex
                    cyclepath.push_back(vertex); // add the current vertex to the cycle path
                    cyclepath.push_back(i);      // add vertex i to the cycle path
                    return true;
                }
            }
        }
        return false;
    }
    /**
     * Find a cycle in the graph using Depth-First Search (DFS).
     *
     * @param graph The graph to search for a cycle.
     * @return True if a cycle is found, false otherwise.
     */
    bool Algorithms::isContainsCycle(const Graph &graph)
    {
        if (graph.getNumEdges() == 0)
        {
            return false; // An empty graph doesn't have cycles
        }
        vector<bool> visited(graph.getNumVertices(), false);
        vector<int> cyclePath;
        return findCycleDFS(graph, 0, -1, visited, cyclePath); // use dfscyclehelper from vertex 0 that dont have parent
    }
    /**
     * Helper function to perform Depth-First Search (DFS) for checking bipartiteness in a graph.
     *
     * @param graph The graph to check for bipartiteness.
     * @param current The current vertex in the DFS traversal.
     * @param visited A vector to mark visited vertices and group them.
     * @param group_A A vector to store vertices in group A.
     * @param group_B A vector to store vertices in group B.
     * @param group_num The current group number (0 or 1).
     * @return True if the graph is bipartite, false otherwise.
     */
    bool Algorithms::isBipartiteDFS(vector<vector<int>> &graph, int current, vector<int> &visited, vector<int> &group_A, vector<int> &group_B, int group_num)
    {
        // numbers for dividing into two groups
        visited[current] = group_num; // Mark group
        // Add to the correct group
        if (group_num == 0)
        {
            group_A.push_back(current);
        }
        else
        {
            group_B.push_back(current);
        }

        for (size_t i = 0; i < graph.size(); i++)
        {
            if (graph[current][i] != 0)
            {
                if (visited[i] == -1) // Has not been visited
                {
                    if (!isBipartiteDFS(graph, i, visited, group_A, group_B, 1 - group_num))
                    {
                        return false; // If any recursive DFS call returns false, the graph is not bipartite
                    }
                }
                else if (visited[i] == visited[current]) // Has the same color as the neighbor
                {
                    return false;
                }
            }
        }
        return true;
    }

    /**
     * Check if the graph is bipartite using Depth-First Search (DFS).
     *
     * @param g The graph to check for bipartiteness.
     * @return A string indicating the bipartite sets if the graph is bipartite, otherwise "0".
     */
    string Algorithms::isBipartite(const Graph &g)
    {
        vector<vector<int>> graph = g.getAdjacencyMatrix();
        // Turn graph to an undirected graph so we can do dfs coloring (i will put wights - 1 becuase we dont care)
        // If there is a directed edge from one to another then make a directed edge back. we can find the bipartite
        // on this graph and that will include the original directed graph.
        for (size_t i = 0; i < graph.size(); i++)
        {
            for (size_t j = 0; j < graph.size(); j++)
            {
                if (graph[i][j] != 0 || graph[j][i] != 0)
                {
                    graph[i][j] = 1;
                    graph[j][i] = 1;
                }
            }
        }

        vector<int> group_A;
        vector<int> group_B;
        vector<int> visited(graph.size(), -1);
        // Use dfs to traverse throgh neighbors
        for (size_t i = 0; i < graph.size(); i++)
        {
            if (visited[i] == -1)
            {
                if (!isBipartiteDFS(graph, i, visited, group_A, group_B, 0))
                {
                    // graph is not bipertite
                    return "0";
                }
            }
        }

        string groups = "The graph is bipartite: A={";
        for (size_t i = 0; i < group_A.size(); i++)
        {
            groups = groups + to_string(group_A[i]);
            if (i < group_A.size() - 1)
            {
                groups += ",";
            }
        }
        groups = groups + "}, B={";
        for (size_t i = 0; i < group_B.size(); i++)
        {
            groups = groups + to_string(group_B[i]);
            if (i < group_B.size() - 1)
            {
                groups += ",";
            }
        }
        groups = groups + "}";
        return groups;
    }
    /**
     * Detect negative cycles in the graph using the Bellman-Ford algorithm.
     *
     * @param graph The graph to check for negative cycles.
     * @return A string indicating the negative cycle if found, otherwise "No negative cycle".
     */
    string Algorithms::negativeCycle(const Graph &graph)
    {
        if (graph.getNumVertices() == 0)
        {
            return "No negative cycle";
        }
        const vector<vector<int>> &adjMatrix = graph.getAdjacencyMatrix(); // Access the adjacency matrix of the graph
        int numVertices = graph.getNumVertices();                          // Get the number of vertices in the graph
        vector<int> distances(numVertices, numeric_limits<int>::max());    // Set distances to all vertices as infinity
        vector<int> parent(numVertices, -1);                               // Store the parent vertex for each vertex

        distances[0] = 0; // Set the distance to the source vertex (vertex 0) to 0

        // Bellman-Ford algorithm to relax edges
        for (int i = 0; i < numVertices - 1; ++i)
        {
            for (int u = 0; u < numVertices; ++u) // Iterate over all vertices
            {
                for (int v = 0; v < numVertices; ++v) // Iterate over all vertices to check edges from u to v
                {
                    if (adjMatrix[u][v] != 0) // If there is an edge from u to v
                    {
                        int weight = adjMatrix[u][v]; // Get the weight of the edge
                        // For all vertex u, we iterate over all vertices v, and if we find a shortest way
                        // through u to v, we update the distance of v
                        if (distances[u] != numeric_limits<int>::max() && distances[u] + weight < distances[v])
                        {
                            distances[v] = distances[u] + weight;
                            parent[v] = u; // Store the parent vertex for tracing back the cycle
                        }
                    }
                }
            }
        }

        // Check for negative-weight cycles by trying to relax edges one more time
        for (int u = 0; u < numVertices; ++u)
        {
            for (int v = 0; v < numVertices; ++v)
            {
                if (adjMatrix[u][v] != 0) // If there is an edge from u to v
                {
                    int weight = adjMatrix[u][v]; // Get the weight of the edge
                    // If the distance shrinks due to the relaxation, there is a negative cycle
                    if (distances[u] != numeric_limits<int>::max() && distances[u] + weight < distances[v])
                    {
                        // Negative cycle found, trace back the cycle
                        vector<int> cycle;
                        int current = v;
                        for (int i = 0; i < numVertices; ++i)
                        {
                            current = parent[current];
                        }

                        int start = current;
                        cycle.push_back(start);
                        current = parent[start];

                        while (current != start)
                        {
                            cycle.push_back(current);
                            current = parent[current];
                        }
                        cycle.push_back(start);

                        // Construct the string representation of the cycle
                        stringstream ss;
                        ss << "Negative cycle found: ";
                        for (size_t i = 0; i < cycle.size(); ++i)
                        {
                            ss << cycle[i];
                            if (i != cycle.size() - 1)
                            {
                                ss << "->";
                            }
                        }
                        return ss.str(); // Return the string representation of the cycle
                    }
                }
            }
        }

        return "No negative cycle"; // No negative cycle found
    }

} // namespace ariel