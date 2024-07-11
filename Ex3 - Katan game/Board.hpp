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
        std::vector<Tile> &getAllTiles();
        Edge *findEdge(int vertex1, int vertex2);
    };

}

#endif // BOARD_HPP
