
#include "Vertex.hpp"
#include "Tile.hpp"
#include "Edge.hpp"

using namespace std;
namespace ariel
{
    // Constructor to initialize the vertex with an index
    Vertex::Vertex(size_t index)
        : index(index), owner(-1), city(-1) {}

    // Get the index of the vertex
    size_t Vertex::getIndex() const
    {
        return index;
    }

    // Set the owner of the vertex
    void Vertex::setOwner(int playerId)
    {
        owner = playerId;
    }

    // Set the city of the vertex
    void Vertex::setCity(int cityId)
    {
        city = cityId;
    }

    // Get the owner of the vertex
    int Vertex::getOwner() const
    {
        return owner;
    }

    // Get the city of the vertex
    int Vertex::getCity() const
    {
        return city;
    }

    // Add an adjacent tile to the vertex
    void Vertex::addAdjacentTile(Tile *tile)
    {
        adjacentTiles.push_back(tile);
    }

    // Get the adjacent tiles
    const vector<Tile *> &Vertex::getAdjacentTiles() const
    {
        return adjacentTiles;
    }

    // Add an adjacent vertex to the vertex
    void Vertex::addNeighbor(Vertex *vertex1,Vertex *vertex2)
    {
        neighbors.push_back(vertex1);
        neighbors.push_back(vertex2);
    }

    // Check if a vertex is a neighbor
    bool Vertex::isNeighbor(const Vertex &vertex) const
    {
        for ( Vertex *neighbor : neighbors)
        {
            if (neighbor->getIndex() == vertex.getIndex())
            {
                return true;
            }
        }
        return false;
    }

    // Get the adjacent vertices
    const vector<Vertex *> &Vertex::getNeighbors() const
    {
        return neighbors;
    }

    // Add an adjacent edge to the vertex
    void Vertex::addEdge(Edge *edge)
    {
        edges.push_back(edge);
    }

    // Get the adjacent edges
    const vector<Edge *> &Vertex::getEdges() const
    {
        return edges;
    }
}