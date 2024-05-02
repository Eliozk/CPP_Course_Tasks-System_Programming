#include "Algorithms.hpp"
#include "Graph.hpp"
#include <queue>
#include <sstream>
#include <iostream>
#include <limits>

namespace ariel
{
    using namespace std;

    bool Algorithms::isConnected(const Graph &g)
    {
        const vector<vector<int>> &matrix = g.getAdjacencyMatrix();
        vector<bool> visited(matrix.size(), false);
        queue<int> q;

        // Start BFS traversal from the first vertex (vertex 0)
        q.push(0);
        visited[0] = true;

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            for (int neighbor : g.getNeighbors(current))
            {
                if (!visited[static_cast<vector<int>::size_type>(neighbor)])
                {
                    q.push(neighbor);
                    visited[static_cast<vector<int>::size_type>(neighbor)] = true;
                }
            }
        }

        // Check if all vertices were visited
        for (bool vertexVisited : visited)
        {
            if (!vertexVisited)
            {
                cout << "Graph is not connected - ";
                return false; // Not all vertices are reachable, graph is not connected
            }
        }
        cout << "Graph is connected - ";
        return true; // All vertices are reachable, graph is connected
    }


   string Algorithms::shortestPath(const Graph &g, int start, int end)
{
    const vector<vector<int>> &matrix = g.getAdjacencyMatrix();
    size_t size = matrix.size(); // Use size_t for size

    // Check if start and end are valid vertices and if there is a path between them
    if (static_cast<size_t>(start) >= size || static_cast<size_t>(end) >= size || !g.isConnected(static_cast<size_t>(start), static_cast<size_t>(end)))
    {
        return "No path from vertex "+ to_string(start) + " to vertex "+ to_string(end)+"."; // No path exists between start and end vertices
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


    // int Algorithms::shortestPath(const Graph &g, int start, int end)
    // {
    //     // Implementation of shortestPath algorithm
    //     return -1; // Placeholder, replace with actual implementation.
    // }

    bool Algorithms::isContainsCycle(const Graph &g)
    {
        // Implementation of isContainsCycle algorithm
        return false; // Placeholder, replace with actual implementation.
    }

    string Algorithms::isBipartite(const Graph &g)
    {
        const vector<vector<int>> &matrix = g.getAdjacencyMatrix();
        queue<int> q;
        vector<int> colors(matrix.size(), -1);
        vector<int> bipartitionA, bipartitionB;

        vector<int> vectorOfMinusOne(1, -1); // Vector with value -1
        vector<int> vectorOfZero(1, 0);      // Vector with value 0
        vector<int> vectorOfOne(1, 1);       // Vector with value 1

        q.push(0);
        colors[0] = 0;
        bipartitionA.push_back(0);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (int neighbor : g.getNeighbors(curr))
            {
                vector<int>::size_type neighborIndex = static_cast<vector<int>::size_type>(neighbor);
                if (colors[neighborIndex] == vectorOfMinusOne[0])
                {
                    colors[neighborIndex] = vectorOfOne[0] - colors[static_cast<vector<int>::size_type>(curr)];
                    q.push(neighbor);

                    if (colors[neighborIndex] == vectorOfZero[0])
                    {
                        bipartitionA.push_back(neighbor);
                    }
                    else
                    {
                        bipartitionB.push_back(neighbor);
                    }
                }
                else if (colors[neighborIndex] == colors[static_cast<vector<int>::size_type>(curr)])
                {
                    return "The graph is not bipartite"; // Return the error message directly
                }
            }
        }

        // Construct the bipartite sets string
        stringstream ss;
        ss << "The graph is bipartite: A={";
        for (int vertex : bipartitionA)
        {
            ss << vertex << ", ";
        }
        ss.seekp(-2, ios_base::end);
        ss << "}, B={";
        for (int vertex : bipartitionB)
        {
            ss << vertex << ", ";
        }
        ss.seekp(-2, ios_base::end);
        ss << "}";
        return ss.str(); // Return the constructed string
                         // return "need to implement isBipartite";
    }
} // namespace ariel