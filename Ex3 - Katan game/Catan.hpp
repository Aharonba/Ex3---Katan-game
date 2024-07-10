#ifndef CATAN_HPP
#define CATAN_HPP
#include <vector>
namespace ariel
{
    class Player;
    class Board;
}

namespace ariel
{

    class Catan
    {
    public:
        Catan(Player &p1, Player &p2, Player &p3);
        void printPlayers() const;
        Player &getPlayer1() const;
        Player &getPlayer2() const;
        Player &getPlayer3() const;
        std::vector<Player> getPlayersVector();
        // void ChooseStartingPlayer();
        Board *getBoard() const;
        void StartingTheGame();
        void distributeResources(int diceRoll);
        // void printWinner() const;

    private:
        Player &player1;
        Player &player2;
        Player &player3;
        Board *game_board;
        // Other game-specific data members and helper functions
    };

}

#endif // CATAN_HPP
