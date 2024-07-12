/**ID:206751976
Email:"aharonba123@gmail.com"
*/

#include "Tile.hpp"

using namespace ariel;

Tile::Tile(const std::vector<Vertex*>& verts, const std::vector<Edge*>& eds, Resource res, int num)
    : vertices(verts), edges(eds), resource(res), number(num) {}

std::vector<Vertex*> Tile::getVertices() const {
    return vertices;
}

std::vector<Edge*> Tile::getEdges() const {
    return edges;
}

Resource Tile::getResource() const {
    return resource;
}

int Tile::getNumber() const {
    return number;
}

std::string Tile::getResourceString() const {
    return resourceToString(resource);
}
