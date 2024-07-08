#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <map>
#include <vector>
#include <memory>
#include "Resource.hpp"
// #include "Board.hpp"

namespace ariel
{

    class Card;
    class Settlement;
    class Road;
    class City;
    class Vertex;

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
        Player(const std::string &name, PlayerColor color);
        ~Player();

        std::string getName() const;
        PlayerColor getColor() const;
        void printResources() const;
        void buildSettlement(Vertex &location);
        void buildCity(Vertex &location);
        void buildRoad(Vertex &start, Vertex &end);
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
        std::vector<Card *> hand;
        std::vector<Settlement *> settlements;
        std::vector<Road *> roads;
        std::vector<City *> cities;
    };

}

#endif // PLAYER_HPP
