#ifndef TILE_HPP
#define TILE_HPP

#include <string>
#include <vector>
#include <Edge.hpp>
#include "Vertex.hpp"
//using namespace std;
namespace ariel
{
    // Forward declaration
    //  class Vertex;

    // Include necessary headers in the implementation file
    class Tile
    {
    private:
        int index;
        int number;
        std::string name;
        std::string resource;
        std::vector<Vertex *> vertices;
        std::vector<Edge> edges;

    public:
        Tile();
        Tile(const std::string &resource, int number, size_t index);
        int getIndex() const;
        int getNumber() const;
        
        string getResource() const;
        void setVertex(Vertex &vertex);
        std::vector<Vertex *>& getVertices();
        void setEdge(int position, const Edge &edge);
        const std::vector<Edge> &getEdges() const;
    };
}

#endif // TILE_HPP
