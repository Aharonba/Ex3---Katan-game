#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "Tile.hpp"

namespace ariel {

    class Board {
    private:
        std::vector<Vertex> vertices;
        std::vector<Edge> edges;
        std::vector<Tile> tiles;

    public:
        Board();
        void initializeBoard();
        void printBoard() const;
    };

}

#endif // BOARD_HPP
