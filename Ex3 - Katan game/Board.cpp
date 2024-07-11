#include "Edge.hpp"
#include "Board.hpp"
#include "Settlement.hpp"
#include "City.hpp"
#include "Road.hpp"

#include <iostream>

using namespace ariel;

Board::Board()
{
    initializeBoard();
}

void Board::initializeBoard()
{
    // Initialize vertices
    for (int i = 0; i < 54; ++i)
    {
        vertices.emplace_back(i);
    }

    // Initialize edges based on the given vertex arrangement
    edges.emplace_back(&vertices[5], &vertices[0], 0);
    edges.emplace_back(&vertices[0], &vertices[1], 1);
    edges.emplace_back(&vertices[1], &vertices[2], 2);
    edges.emplace_back(&vertices[2], &vertices[3], 3);
    edges.emplace_back(&vertices[3], &vertices[4], 4);
    edges.emplace_back(&vertices[4], &vertices[5], 5);

    edges.emplace_back(&vertices[1], &vertices[6], 6);
    edges.emplace_back(&vertices[6], &vertices[7], 7);
    edges.emplace_back(&vertices[7], &vertices[8], 8);
    edges.emplace_back(&vertices[8], &vertices[9], 9);
    edges.emplace_back(&vertices[9], &vertices[2], 10);

    edges.emplace_back(&vertices[7], &vertices[10], 11);
    edges.emplace_back(&vertices[10], &vertices[11], 12);
    edges.emplace_back(&vertices[11], &vertices[12], 13);
    edges.emplace_back(&vertices[12], &vertices[13], 14);
    edges.emplace_back(&vertices[13], &vertices[8], 15);

    edges.emplace_back(&vertices[17], &vertices[4], 16);
    edges.emplace_back(&vertices[3], &vertices[14], 17);
    edges.emplace_back(&vertices[14], &vertices[15], 18);
    edges.emplace_back(&vertices[15], &vertices[16], 19);
    edges.emplace_back(&vertices[16], &vertices[17], 20);

    edges.emplace_back(&vertices[9], &vertices[18], 21);
    edges.emplace_back(&vertices[18], &vertices[19], 22);
    edges.emplace_back(&vertices[19], &vertices[14], 23);

    edges.emplace_back(&vertices[13], &vertices[20], 24);
    edges.emplace_back(&vertices[20], &vertices[21], 25);
    edges.emplace_back(&vertices[21], &vertices[18], 26);

    edges.emplace_back(&vertices[12], &vertices[22], 27);
    edges.emplace_back(&vertices[22], &vertices[23], 28);
    edges.emplace_back(&vertices[23], &vertices[24], 29);

    edges.emplace_back(&vertices[28], &vertices[16], 30);
    edges.emplace_back(&vertices[15], &vertices[25], 31);
    edges.emplace_back(&vertices[25], &vertices[26], 32);
    edges.emplace_back(&vertices[26], &vertices[27], 33);
    edges.emplace_back(&vertices[27], &vertices[28], 34);

    edges.emplace_back(&vertices[19], &vertices[29], 35);
    edges.emplace_back(&vertices[29], &vertices[30], 36);
    edges.emplace_back(&vertices[30], &vertices[25], 37);

    edges.emplace_back(&vertices[21], &vertices[31], 38);
    edges.emplace_back(&vertices[31], &vertices[32], 39);
    edges.emplace_back(&vertices[32], &vertices[29], 40);
    edges.emplace_back(&vertices[24], &vertices[20], 41);

    edges.emplace_back(&vertices[24], &vertices[33], 42);
    edges.emplace_back(&vertices[33], &vertices[34], 43);
    edges.emplace_back(&vertices[34], &vertices[31], 44);

    edges.emplace_back(&vertices[23], &vertices[35], 45);
    edges.emplace_back(&vertices[35], &vertices[36], 46);
    edges.emplace_back(&vertices[36], &vertices[37], 47);
    edges.emplace_back(&vertices[37], &vertices[33], 48);

    edges.emplace_back(&vertices[30], &vertices[39], 49);
    edges.emplace_back(&vertices[39], &vertices[43], 50);
    edges.emplace_back(&vertices[43], &vertices[38], 51);
    edges.emplace_back(&vertices[38], &vertices[26], 52);

    edges.emplace_back(&vertices[32], &vertices[40], 53);
    edges.emplace_back(&vertices[40], &vertices[44], 54);
    edges.emplace_back(&vertices[44], &vertices[39], 55);

    edges.emplace_back(&vertices[34], &vertices[41], 56);
    edges.emplace_back(&vertices[41], &vertices[45], 57);
    edges.emplace_back(&vertices[45], &vertices[40], 58);

    edges.emplace_back(&vertices[37], &vertices[42], 59);
    edges.emplace_back(&vertices[42], &vertices[46], 60);
    edges.emplace_back(&vertices[46], &vertices[41], 61);

    edges.emplace_back(&vertices[43], &vertices[47], 62);
    edges.emplace_back(&vertices[44], &vertices[48], 63);
    edges.emplace_back(&vertices[48], &vertices[51], 64);
    edges.emplace_back(&vertices[51], &vertices[47], 65);

    edges.emplace_back(&vertices[45], &vertices[49], 66);
    edges.emplace_back(&vertices[49], &vertices[52], 67);
    edges.emplace_back(&vertices[52], &vertices[48], 68);

    edges.emplace_back(&vertices[46], &vertices[50], 69);
    edges.emplace_back(&vertices[50], &vertices[53], 70);
    edges.emplace_back(&vertices[53], &vertices[49], 71);

    tiles.emplace_back(
        std::vector<Vertex *>{&vertices[0], &vertices[1], &vertices[2], &vertices[3], &vertices[4], &vertices[5]},
        std::vector<Edge *>{&edges[0], &edges[1], &edges[2], &edges[3], &edges[4], &edges[5]},
        Resource::Iron, 10);

    tiles.emplace_back(
        std::vector<Vertex *>{&vertices[6], &vertices[7], &vertices[8], &vertices[9], &vertices[2], &vertices[1]},
        std::vector<Edge *>{&edges[6], &edges[7], &edges[8], &edges[9], &edges[10], &edges[2]},
        Resource::Wool, 2);

    tiles.emplace_back(
        std::vector<Vertex *>{&vertices[10], &vertices[11], &vertices[12], &vertices[13], &vertices[8], &vertices[7]},
        std::vector<Edge *>{&edges[11], &edges[12], &edges[13], &edges[14], &edges[15], &edges[8]},
        Resource::Wood, 9);

    tiles.emplace_back(
        std::vector<Vertex *>{&vertices[4], &vertices[3], &vertices[14], &vertices[15], &vertices[16], &vertices[17]},
        std::vector<Edge *>{&edges[4], &edges[17], &edges[18], &edges[19], &edges[20], &edges[16]},
        Resource::Oats, 12);

    tiles.emplace_back(
        std::vector<Vertex *>{&vertices[2], &vertices[9], &vertices[18], &vertices[19], &vertices[14], &vertices[3]},
        std::vector<Edge *>{&edges[3], &edges[10], &edges[21], &edges[22], &edges[23], &edges[17]},
        Resource::Brick, 6);

    tiles.emplace_back(
        std::vector<Vertex *>{&vertices[8], &vertices[13], &vertices[20], &vertices[21], &vertices[18], &vertices[9]},
        std::vector<Edge *>{&edges[9], &edges[15], &edges[24], &edges[25], &edges[26], &edges[21]},
        Resource::Wool, 4);

    tiles.emplace_back(
        std::vector<Vertex *>{&vertices[12], &vertices[22], &vertices[23], &vertices[24], &vertices[20], &vertices[13]},
        std::vector<Edge *>{&edges[14], &edges[27], &edges[28], &edges[29], &edges[41], &edges[24]},
        Resource::Brick, 10);

    tiles.emplace_back(
        std::vector<Vertex *>{&vertices[16], &vertices[15], &vertices[25], &vertices[26], &vertices[27], &vertices[28]},
        std::vector<Edge *>{&edges[30], &edges[19], &edges[31], &edges[32], &edges[33], &edges[34]},
        Resource::Oats, 9);

    tiles.emplace_back(
        std::vector<Vertex *>{&vertices[14], &vertices[19], &vertices[29], &vertices[30], &vertices[25], &vertices[15]},
        std::vector<Edge *>{&edges[18], &edges[23], &edges[35], &edges[36], &edges[37], &edges[31]},
        Resource::Wood, 11);

    tiles.emplace_back(
        std::vector<Vertex *>{&vertices[18], &vertices[21], &vertices[31], &vertices[32], &vertices[29], &vertices[19]},
        std::vector<Edge *>{&edges[22], &edges[26], &edges[38], &edges[39], &edges[40], &edges[35]},
        Resource::Desert, 7);

    tiles.emplace_back(
        std::vector<Vertex *>{&vertices[20], &vertices[24], &vertices[33], &vertices[34], &vertices[31], &vertices[21]},
        std::vector<Edge *>{&edges[25], &edges[41], &edges[42], &edges[43], &edges[44], &edges[38]},
        Resource::Wood, 3);

    tiles.emplace_back(
        std::vector<Vertex *>{&vertices[23], &vertices[35], &vertices[36], &vertices[37], &vertices[33], &vertices[24]},
        std::vector<Edge *>{&edges[29], &edges[45], &edges[46], &edges[47], &edges[48], &edges[42]},
        Resource::Iron, 8);

    tiles.emplace_back(
        std::vector<Vertex *>{&vertices[25], &vertices[30], &vertices[39], &vertices[43], &vertices[38], &vertices[26]},
        std::vector<Edge *>{&edges[32], &edges[37], &edges[49], &edges[50], &edges[51], &edges[52]},
        Resource::Wood, 8);

    tiles.emplace_back(
        std::vector<Vertex *>{&vertices[29], &vertices[32], &vertices[40], &vertices[44], &vertices[39], &vertices[30]},
        std::vector<Edge *>{&edges[36], &edges[40], &edges[53], &edges[54], &edges[55], &edges[49]},
        Resource::Iron, 3);

    tiles.emplace_back(
        std::vector<Vertex *>{&vertices[31], &vertices[34], &vertices[41], &vertices[45], &vertices[40], &vertices[32]},
        std::vector<Edge *>{&edges[39], &edges[44], &edges[56], &edges[57], &edges[58], &edges[53]},
        Resource::Oats, 4);

    tiles.emplace_back(
        std::vector<Vertex *>{&vertices[33], &vertices[37], &vertices[42], &vertices[46], &vertices[41], &vertices[34]},
        std::vector<Edge *>{&edges[43], &edges[48], &edges[59], &edges[60], &edges[61], &edges[56]},
        Resource::Wool, 5);

    tiles.emplace_back(
        std::vector<Vertex *>{&vertices[39], &vertices[44], &vertices[48], &vertices[51], &vertices[47], &vertices[43]},
        std::vector<Edge *>{&edges[50], &edges[55], &edges[63], &edges[64], &edges[65], &edges[62]},
        Resource::Brick, 5);

    tiles.emplace_back(
        std::vector<Vertex *>{&vertices[40], &vertices[45], &vertices[49], &vertices[52], &vertices[48], &vertices[44]},
        std::vector<Edge *>{&edges[54], &edges[58], &edges[66], &edges[67], &edges[68], &edges[63]},
        Resource::Oats, 6);

    tiles.emplace_back(
        std::vector<Vertex *>{&vertices[41], &vertices[46], &vertices[50], &vertices[53], &vertices[49], &vertices[45]},
        std::vector<Edge *>{&edges[57], &edges[61], &edges[69], &edges[70], &edges[71], &edges[66]},
        Resource::Wool, 11);

    // Add resources and tile numbers to vertices
    for (size_t tileIndex = 0; tileIndex < tiles.size(); ++tileIndex)
    {
        const auto &tile = tiles[tileIndex];
        auto vertices = tile.getVertices();
        auto resource = tile.getResource();
        int tileID = tile.getNumber();
        for (auto vertex : vertices)
        {
            vertex->addResource(resource);
            vertex->addAdjacentTile(static_cast<int>(tileID)); // Assuming addAdjacentTile is a method in Vertex class
        }
    }
}

void Board::printBoard() const
{
    // Print vertices
    std::cout << "Vertices:" << std::endl;
    for (const auto &vertex : vertices)
    {
        std::cout << "Vertex " << vertex.getNumber() << std::endl;

        // Check if there's a settlement or city
        if (vertex.getSettlement())
        {
            std::cout << "  Settlement owned by " << vertex.getSettlement()->getOwner().getName() << std::endl;
        }
        if (vertex.getCity())
        {
            std::cout << "  City owned by " << vertex.getCity()->getOwner().getName() << std::endl;
        }
    }
    std::cout << std::endl;

    // Print edges
    std::cout << "Edges:" << std::endl;
    for (const auto &edge : edges)
    {
        std::cout << "Edge number: " << edge.getNumber() << " is between Vertex " << edge.getVertex1()->getNumber()
                  << " and Vertex " << edge.getVertex2()->getNumber() << std::endl;

        // Check if there's a road
        if (edge.getRoad())
        {
            std::cout << "  Road owned by " << edge.getRoad()->getOwner().getName() << std::endl;
        }
    }
    std::cout << std::endl;

    // Print tiles
    std::cout << "Tiles:" << std::endl;
    for (const auto &tile : tiles)
    {
        std::cout << "Tile number: " << tile.getNumber() << " with resource: ";
        switch (tile.getResource())
        {
        case Resource::Iron:
            std::cout << "Iron";
            break;
        case Resource::Wood:
            std::cout << "Wood";
            break;
        case Resource::Wool:
            std::cout << "Wool";
            break;
        case Resource::Brick:
            std::cout << "Brick";
            break;
        case Resource::Oats:
            std::cout << "Oats";
            break;
        case Resource::Desert:
            std::cout << "Desert";
            break;
        default:
            std::cout << "Unknown";
        }
        std::cout << " with vertices: ";
        for (const auto &vertex : tile.getVertices())
        {
            std::cout << vertex->getNumber() << " ";
        }
        std::cout << "and edges: ";
        for (const auto &edge : tile.getEdges())
        {
            std::cout << edge->getNumber() << " ";
        }
        std::cout << std::endl;
    }
}

Vertex *Board::getVertex(int num_vertex)
{
    return &vertices[(size_t)num_vertex];
}
Edge *Board::getEdge(int num_edge)
{
    return &edges[(size_t)num_edge];
}

std::vector<Tile> &Board::getAllTiles()
{
    return tiles;
}

Edge *Board::findEdge(int vertex1, int vertex2)
{
    for (auto &edge : edges)
    {
        if ((edge.getVertex1()->getNumber() == vertex1 && edge.getVertex2()->getNumber() == vertex2) ||
            (edge.getVertex1()->getNumber() == vertex2 && edge.getVertex2()->getNumber() == vertex1))
        {
            return &edge;
        }
    }
    return nullptr;
}