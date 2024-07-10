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
    class Edge;
    class Catan;
    enum class Resource;
    class PromotionCard;

    enum class PlayerColor
    {
        None,
        Red,
        Blue,
        Purple
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
        int getPoints() const;
        void updatePoints(int points);
        void removeSettlement(Settlement *settlement);
        void initializeStartingPositions(Vertex &settlement1, Vertex &settlement2, Edge &road1, Edge &road2);
        void distributeStartingResources(Vertex &settlement);
        Card *buyCard();
        void usePromotionCard(Card *card, Catan *catan, Resource resource1, Resource resource2, int starting_point_road, int ending_point_road);
        bool checkAndTakeResource(Resource resource);
        void setResource(Resource resource, int count);
        int randNumberForCard();
        bool hasResource(Resource resource, int quantity) const;
        bool removeResource(Resource resource, int quantity);
        void addResource(Resource resource, int quantity);
        void tradeResources(Player &otherPlayer, Resource offeredResource, Resource desiredResource, int quantity);
        void tradeCard(Player &otherPlayer, Card &offeredCard, Card &desiredCard);
        bool hasCard(Card *card) const;
        void removeCard(Card *card);
        void addCard(Card *card);
        int getHandSize();
        Card *removeCardRandom();

        // void placeSettlement(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board);
        // void placeRoad(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board);
        void rollDice(Catan *catan);
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
        int numerOfKnightCard = 0;
    };

}

#endif // PLAYER_HPP
