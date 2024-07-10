#ifndef TILE_HPP
#define TILE_HPP

#include <vector>
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Resource.hpp"

namespace ariel {

    class Tile {
    private:
        std::vector<Vertex*> vertices; // Vector of 6 vertices
        std::vector<Edge*> edges; // Vector of 6 edges
        Resource resource; // Type of resource this tile provides
        int number; // Number associated with the tile (2-12)

    public:
        Tile(const std::vector<Vertex*>& verts, const std::vector<Edge*>& eds, Resource res, int num);
        std::vector<Vertex*> getVertices() const;
        std::vector<Edge*> getEdges() const;
        Resource getResource() const;
        int getNumber() const;
        std::string getResourceString() const;
    };

}

#endif // TILE_HPP
