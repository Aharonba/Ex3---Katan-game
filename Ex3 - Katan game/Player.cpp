#include "Player.hpp"
#include "City.hpp"
#include "Settlement.hpp"
#include "Road.hpp"
#include "Vertex.hpp"

// #include "developmentcard.hpp"
// #include "knightcard.hpp"
// #include "victorypointcard.hpp"
#include <iostream>

namespace ariel
{
    Player::Player(const std::string &name, PlayerColor color) : name(name), points(0), color(color)
    {
        // Initialize the map with 5 keys, all set to zero
        resources = {
            {Resource::Wood, 0},
            {Resource::Brick, 0},
            {Resource::Wool, 0},
            {Resource::Oats, 0},
            {Resource::Iron, 0}};
    }

    Player::~Player()
    {
        for (auto settlement : settlements)
        {
            delete settlement;
        }
        for (auto city : cities)
        {
            delete city;
        }
        for (auto road : roads)
        {
            delete road;
        }


    }

    std::string Player::getName() const
    {
        return name;
    }

    PlayerColor Player::getColor() const
    {
        return color;
    }

    void Player::printResources() const
    {
        for (const auto &resource : resources)
        {
            std::cout << "Resource: " << resourceToString(resource.first) << ", Amount: " << resource.second << std::endl;
        }
    }

    void Player::buildSettlement(Vertex &location)
{
    // Check if player has enough resources
    if (resources[Resource::Brick] >= 1 && resources[Resource::Wood] >= 1 &&
        resources[Resource::Wool] >= 1 && resources[Resource::Oats] >= 1) {
        // Deduct resources
        resources[Resource::Brick]--;
        resources[Resource::Wood]--;
        resources[Resource::Wool]--;
        resources[Resource::Oats]--;

        // Create and add settlement
        Settlement *settlement = new Settlement(*this, location);
        settlements.push_back(settlement);
        location.buildSettlement(settlement);
    } else {
        std::cout << "Not enough resources to build a settlement." << std::endl;
    }
}


void Player::buildCity(Vertex &location)
{
    // Check if player has enough resources
    if (resources[Resource::Iron] >= 3 && resources[Resource::Oats] >= 2) {
        // Deduct resources
        resources[Resource::Iron] -= 3;
        resources[Resource::Oats] -= 2;

        // Check if there is a settlement at the location
        if (!location.isEmpty() && location.getSettlement() != nullptr) {
            // Check if the settlement belongs to the current player
            if (&location.getSettlement()->getOwner() == this) {
                // Create and add city
                City *city = new City(*this, location);
                cities.push_back(city);
                location.buildCity(city);

                // Remove the settlement from the vertex
                // location.removeSettlement();
            } else {
                std::cout << "Cannot build city. There is another player's settlement at this location." << std::endl;
            }
        } else {
            std::cout << "No settlement found at this location to upgrade to a city." << std::endl;
        }
    } else {
        std::cout << "Not enough resources to build a city." << std::endl;
    }
}



   void Player::buildRoad(Vertex &start, Vertex &end)
{
    // Check if player has enough resources
    if (resources[Resource::Brick] >= 1 && resources[Resource::Wood] >= 1) {
        // Deduct resources
        resources[Resource::Brick]--;
        resources[Resource::Wood]--;

        // Create and add road
        Road *road = new Road(*this, start, end);
        roads.push_back(road);
        start.buildRoad(road);
        end.buildRoad(road);
    } else {
        std::cout << "Not enough resources to build a road." << std::endl;
    }
}


    // void Player::placeSettlement(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board) {
    //     // Logic to place a settlement on the board
    //     // Example: Assume places and placesNum are coordinates to place the settlement
    //     // Check if the player has the required resources
    //     bool hasResources = true; // Example logic, needs implementation
    //     if (!hasResources) {
    //         std::cout << "Not enough resources to place a settlement." << std::endl;
    //         return;
    //     }
    //     // Place settlement on the board
    //     // Example logic to update board state and player's resources
    // }

    // void Player::placeRoad(const std::vector<std::string> &places, const std::vector<int> &placesNum, Board &board) {
    //     // Logic to place a road on the board
    //     // Example: Assume places and placesNum are coordinates to place the road
    //     // Check if the player has the required resources
    //     bool hasResources = true; // Example logic, needs implementation
    //     if (!hasResources) {
    //         std::cout << "Not enough resources to place a road." << std::endl;
    //         return;
    //     }
    //     // Place road on the board
    //     // Example logic to update board state and player's resources
    // }

    // void Player::rollDice() {
    //     // Logic to roll dice
    //     int diceRoll = 0; // Example roll result, needs implementation
    //     std::cout << "Dice rolled: " << diceRoll << std::endl;
    //     // Determine which players get resources based on dice roll and board state
    //     // Example logic to distribute resources
    // }

    // void Player::endTurn() {
    //     // Logic to end turn
    //     std::cout << name << " ends their turn." << std::endl;
    //     // Example logic to pass turn to the next player
    // }

    // void Player::trade(Player &other, Resource giveResource, Resource receiveResource, int giveAmount, int receiveAmount) {
    //     // Logic to trade resources with another player
    //     // Example: Check if trade conditions are met and update resources accordingly
    //     std::cout << name << " trades with " << other.name << "." << std::endl;
    //     // Example logic to update player and other player's resources
    // }

    // void Player::buyDevelopmentCard() {
    //     // Logic to buy a development card
    //     // Example: Check if player has enough resources and deduct resources
    //     std::cout << name << " buys a development card." << std::endl;
    //     // Example logic to add a random development card to player's collection
    //     cards.push_back(std::make_shared<DevelopmentCard>(DevelopmentCard::SubType::Monopoly));
    // }

    // void Player::playCard(std::shared_ptr<Card> card) {
    //     // Logic to play a development card
    //     std::cout << name << " plays a development card." << std::endl;
    //     card->play(); // Play the card specific logic
    //     // Example logic to remove the card from player's collection after use
    //     cards.erase(std::remove(cards.begin(), cards.end(), card), cards.end());
    // }

    // void Player::printPoints() const {
    //     // Logic to print player's points
    //     std::cout << name << " has " << points << " points." << std::endl;
    // }

    // const std::vector<std::shared_ptr<Card>>& Player::getCards() const {
    //     return cards;
    // }
}