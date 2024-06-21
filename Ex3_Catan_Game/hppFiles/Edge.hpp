#ifndef EDGE_HPP
#define EDGE_HPP

 #pragma once
#include "Vertex.hpp"


using namespace std;

namespace ariel
{
   class Vertex; // Forward declaration
    class Edge
    {
    public:
        // Constructor to initialize the edge with vertices, index, and owner
        Edge(Vertex* v1, Vertex* v2, size_t index, int owner);
        Edge(size_t index);  
        Edge() = default;  // Default constructor
        // Getters & setters for vertices, index, and owner
        void setVertices(Vertex *vertex1, Vertex *vertex2);
        const Vertex* getVertex1() const;
        const Vertex *getVertex2() const;
        size_t getIndex() const;
        void setOwner(int playerNum);
        int getOwner() const;

    private:
        const Vertex *vertex1; // First vertex connected by the edge
        const Vertex *vertex2; // Second vertex connected by the edge
        size_t index;    // Index of the edge on the board
        int owner;       // ID of the player who owns the edge, -1 if unowned
    };
}

#endif // EDGE_HPP
