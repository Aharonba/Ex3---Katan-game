#ifndef CATAN_HPP
#define CATAN_HPP

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
        // void ChooseStartingPlayer();
        // Board getBoard() const;
        // void printWinner() const;

    private:
        Player &player1;
        Player &player2;
        Player &player3;
        // Board board;
        // Other game-specific data members and helper functions
    };

}

#endif // CATAN_HPP
