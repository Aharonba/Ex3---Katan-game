#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "Resource.hpp"
// #include "board.hpp"
// #include "card.hpp"

namespace ariel
{

    enum class PlayerColor
    {
        None,
        Red,
        Blue,
        Yellow
    };

    class Player
    {
    public:
        Player(const std::string &name);
        std::string getName () const;
        void printResources () const;
        // void placeSettlement(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board);
        // void placeRoad(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board);
        // void rollDice();
        // void endTurn();
        // void trade(Player &other, Resource giveResource, Resource receiveResource, int giveAmount, int receiveAmount);
        // void buyDevelopmentCard();
        // void playCard(std::shared_ptr<Card> card);
        // void printPoints() const;
        // const std::vector<std::shared_ptr<Card>> &getCards() const;

    private:
        std::string name;
        int points;
        std::map<Resource, int> resources;
        PlayerColor color;
        // std::vector<std::shared_ptr<Card>> cards;
        // // Other player-specific data members
    };

}

#endif // PLAYER_HPP
