#include "Tile.hpp"
#include "Vertex.hpp" // Include Vertex.hpp for using Vertex in the implementation
#include "Edge.hpp"
#include <string>

using namespace std;
namespace ariel {


// Implementation for Tile
Tile::Tile() {} // for creation of null Tile
Tile::Tile(const string &resource, int number, size_t index)
    : resource(resource), number(number), index(index), vertices{}, edges{} {}

int Tile::getIndex() const
{
    return index;
}

int Tile::getNumber() const
{
    return number;
}

 vector<Vertex *>& Tile::getVertices() {
    return vertices;
     }

string Tile::getResource() const
{
    string res;
    if (resource == "Field")
    {
        res = "Grain";//שיבולת
    }
    else if (resource == "Forest")
    {
        res = "Lumber";//עץ
    }
    else if (resource == "Pasture")
    {
        res = "Wool";
    }
    else if (resource == "Hill")
    {
        res = "Brick";
    }
    else if (resource == "Mountain")
    {
        res = "Ore";
    }
     else if (resource == "Desert") {
        res = "Dessert doesn't provide a resource."; // Desert doesn't provide a resource
    }
    return res;
}

void Tile::setVertex(Vertex &vertex)
{
        vertices.push_back(&vertex);
}

void Tile::setEdge(int position, const Edge &edge)
{
    if (position >= 0 && position < 6)
    {
        edges[position] = edge;
    }
}

const vector<Edge> &Tile::getEdges() const
{
    return edges;
}
}

