#include "Algorithms.hpp"
#include "Graph.hpp"
#include <queue>
#include <sstream>
#include <iostream>

namespace ariel
{

    bool Algorithms::isConnected(const Graph &g)
    {
        // Implementation of isConnected algorithm
        return false; // Placeholder, replace with actual implementation.
    }

    int Algorithms::shortestPath(const Graph &g, int start, int end)
    {
        // Implementation of shortestPath algorithm
        return -1; // Placeholder, replace with actual implementation.
    }

    bool Algorithms::isContainsCycle(const Graph &g)
    {
        // Implementation of isContainsCycle algorithm
        return false; // Placeholder, replace with actual implementation.
    }





    std::string Algorithms::isBipartite(const Graph &g)
    {
        const std::vector<std::vector<int>> &matrix = g.getAdjacencyMatrix();
        std::queue<int> q;
        std::vector<int> colors(matrix.size(), -1);
        std::vector<int> bipartitionA, bipartitionB;

        std::vector<int> vectorOfMinusOne(1, -1); // Vector with value -1
        std::vector<int> vectorOfZero(1, 0);      // Vector with value 0
        std::vector<int> vectorOfOne(1, 1);       // Vector with value 1

        q.push(0);
        colors[0] = 0;
        bipartitionA.push_back(0);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (int neighbor : g.getNeighbors(curr))
            {
                std::vector<int>::size_type neighborIndex = static_cast<std::vector<int>::size_type>(neighbor);
                if (colors[neighborIndex] == vectorOfMinusOne[0])
                {
                    colors[neighborIndex] = vectorOfOne[0] - colors[static_cast<std::vector<int>::size_type>(curr)];
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
                else if (colors[neighborIndex] == colors[static_cast<std::vector<int>::size_type>(curr)])
                {
                    return "The graph is not bipartite"; // Return the error message directly
                }
            }
        }

        // Construct the bipartite sets string
        std::stringstream ss;
        ss << "The graph is bipartite: A={";
        for (int vertex : bipartitionA)
        {
            ss << vertex << ", ";
        }
        ss.seekp(-2, std::ios_base::end);
        ss << "}, B={";
        for (int vertex : bipartitionB)
        {
            ss << vertex << ", ";
        }
        ss.seekp(-2, std::ios_base::end);
        ss << "}";
        return ss.str(); // Return the constructed string
       // return "need to implement isBipartite";
    }

} // namespace ariel
