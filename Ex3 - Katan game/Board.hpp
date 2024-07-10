#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "Tile.hpp"

namespace ariel
{

    class Board
    {
    private:
        std::vector<Vertex> vertices;
        std::vector<Edge> edges;
        std::vector<Tile> tiles;

    public:
        Board();
        void initializeBoard();
        void printBoard() const;
        Vertex *getVertex(int num_vertex);
        Edge *getEdge(int num_edge);
        std::vector<Tile>& getAllTiles();
        // Edge &findEdge(Vertex &start, Vertex &end); // Method to find edge between two vertices
    };

}

#endif // BOARD_HPP
