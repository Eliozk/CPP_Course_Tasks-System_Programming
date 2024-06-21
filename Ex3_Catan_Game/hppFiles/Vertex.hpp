// Kolani Elioz
// Kolanielioz@gmail.com
#pragma once
#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <vector>
#include <cstddef>
using namespace std; 

namespace ariel
{
    // Forward declaration
    class Tile;
    class Edge;
    class Vertex
    {
    private:
        size_t index;                 // Index of the vertex
        int owner;                    // ID of the player who owns the vertex, -1 if unowned
        int city;                     // ID of the city, -1 if no city
        vector<Tile *> adjacentTiles; // Adjacent tiles
        vector<Vertex *> neighbors;   // Adjacent vertices (neighbors)
        vector<Edge *> edges;         // Adjacent edges
    public:
        // Constructor to initialize the vertex with an index
        Vertex(size_t index);
        Vertex() = default;

        // Getters and setters for index and owner
        size_t getIndex() const;
        void setOwner(int playerId);
        int getOwner() const;
        void setCity(int cityId);
        int getCity() const;

        // Add an adjacent tile to the vertex
        void addAdjacentTile(Tile *tile);

        // Get the adjacent tiles
        const vector<Tile *> &getAdjacentTiles() const;

        // Add 2 adjacent vertices to the vertex
        void addNeighbor(Vertex *vertex1, Vertex *vertex2);

        // Check if a vertex is a neighbor
        bool isNeighbor(const Vertex &vertex) const;

        // Get the adjacent vertices
        const vector<Vertex *> &getNeighbors() const;

        // Add an adjacent edge to the vertex
        void addEdge(Edge *edge);

        // Get the adjacent edges
        const vector<Edge *> &getEdges() const;

   
    };
}
#endif // VERTEX_HPP
