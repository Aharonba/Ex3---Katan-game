/**ID:206751976
Email:"aharonba123@gmail.com"
*/

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
        ~Catan();
        Catan(const Catan &other);
        Catan &operator=(const Catan &other);
        void printPlayers() const;
        Player &getPlayer1() const;
        Player &getPlayer2() const;
        Player &getPlayer3() const;
        std::vector<Player> getPlayersVector();
        Board *getBoard() const;
        void StartingTheGame();
        void distributeResources(int diceRoll);

    private:
        Player &player1;
        Player &player2;
        Player &player3;
        Board *game_board;
    };

}

#endif // CATAN_HPP
