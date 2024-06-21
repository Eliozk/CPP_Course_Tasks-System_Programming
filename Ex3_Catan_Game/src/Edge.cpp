#include "Edge.hpp"
#include "Vertex.hpp" // Include the Vertex header to access the Vertex class

using namespace std;
using namespace ariel;


// Constructor implementation
Edge::Edge(Vertex* v1, Vertex* v2, size_t index, int owner)
    : vertex1(v1), vertex2(v2), index(index), owner(-1) {}

Edge::Edge(size_t index) : index(index), owner(-1) {}

void Edge::setVertices(Vertex* v1, Vertex* v2) {
    this->vertex1 = v1;
    this->vertex2 = v2;
}
// Getter implementations
const Vertex* Edge::getVertex1() const {
    return vertex1;
}

const Vertex* Edge::getVertex2() const {
    return vertex2;
}

void Edge::setOwner(int player) {
    owner = player;
}

size_t Edge::getIndex() const {
    return index;
}

int Edge::getOwner() const {
    return owner;
}
