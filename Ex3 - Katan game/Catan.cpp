/**ID:206751976
Email:"aharonba123@gmail.com"
*/


#include "Catan.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "Settlement.hpp"
#include "City.hpp"
#include <iostream>
using namespace ariel;

Catan::Catan(Player &p1, Player &p2, Player &p3) : player1(p1), player2(p2), player3(p3)
{
    game_board = new Board();
    StartingTheGame();
}

Catan::~Catan()
{
    delete game_board;
}

void Catan::printPlayers() const
{
    std::cout << player1.getName() << std::endl;
    std::cout << player2.getName() << std::endl;
    std::cout << player3.getName() << std::endl
              << std::endl;
}

Board *Catan::getBoard() const
{
    return game_board;
}

/**
 * @brief Initializes starting positions for players on the game board.
 *
 * Each player is assigned specific starting positions on the board.
 */

void Catan::StartingTheGame()
{
    player1.initializeStartingPositions(*(game_board->getVertex(8)), *(game_board->getVertex(9)), *(game_board->getEdge(9)), *(game_board->getEdge(8)));
    player2.initializeStartingPositions(*(game_board->getVertex(29)), *(game_board->getVertex(30)), *(game_board->getEdge(36)), *(game_board->getEdge(37)));
    player3.initializeStartingPositions(*(game_board->getVertex(24)), *(game_board->getVertex(33)), *(game_board->getEdge(42)), *(game_board->getEdge(48)));
}

Player &Catan::getPlayer1() const
{
    return player1;
}

Player &Catan::getPlayer2() const
{
    return player2;
}

Player &Catan::getPlayer3() const
{
    return player3;
}

/**
 * @brief Distributes resources to players based on dice roll.
 *
 * Checks each tile on the game board to see if its number matches the given dice roll.
 * If so, resources are distributed to settlements and cities on vertices connected to that tile.
 * @param diceRoll The result of the dice roll.
 */

void Catan::distributeResources(int diceRoll)
{
    if (diceRoll != 7)
    {
        for (const auto &tile : game_board->getAllTiles())
        {
            if (tile.getNumber() == diceRoll)
            {
                auto tileVertices = tile.getVertices();
                auto resource = tile.getResource();
                for (const auto vertex : tileVertices)
                {
                    if (vertex->hasSettlement())
                    {
                        vertex->getSettlement()->getOwner().setResource(resource, 1);
                    }
                    else if (vertex->hasCity())
                    {
                        vertex->getCity()->getOwner().setResource(resource, 2);
                    }
                }
            }
        }
    }
}

std::vector<Player> Catan::getPlayersVector()
{
    std::vector<Player> VP({player1, player2, player3});
    return VP;
}
