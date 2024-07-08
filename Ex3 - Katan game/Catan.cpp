#include "Catan.hpp"
#include "Player.hpp"
#include <iostream> // For std::cout, std::endl

using namespace ariel;

Catan::Catan(Player &p1, Player &p2, Player &p3) : player1(p1), player2(p2), player3(p3)
{
    // Initialize game state, board, and players
}

void Catan::printPlayers() const
{
    std::cout << player1.getName() << std::endl;
    std::cout << player2.getName() << std::endl;
    std::cout << player3.getName() << std::endl;
}

// void Catan::ChooseStartingPlayer() {
//     // Logic to choose starting player
//     std::cout << "Choosing starting player." << std::endl;
//     // Example logic to determine and print starting player
//     std::cout << "Starting player is: " << player1.getName() << std::endl;
// }

// Board Catan::getBoard() const {
//     // Logic to get game board
//     return board;
// }

// void Catan::printWinner() const {
//     // Logic to determine and print winner
//     std::cout << "Determining winner..." << std::endl;
//     // Example logic to check points of each player and print winner
// }
