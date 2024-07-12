/**ID:206751976
Email:"aharonba123@gmail.com"
*/

#include "Player.hpp"
#include "City.hpp"
#include "Settlement.hpp"
#include "Road.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Card.hpp"
#include "Catan.hpp"
#include "Resource.hpp"
#include "Board.hpp"
#include <stdexcept>
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>

namespace ariel
{
    Player::Player(const std::string &name, PlayerColor color) : name(name), points(0), color(color)
    {
        resources = {
            {Resource::Wood, 0},
            {Resource::Brick, 0},
            {Resource::Wool, 0},
            {Resource::Oats, 0},
            {Resource::Iron, 0}};
    }

    /**
     * @brief Destroys the Player object, freeing dynamically allocated memory for settlements, cities, and roads.
     *
     * Deletes all dynamically allocated settlement, city, and road objects.
     */

    Player::~Player()
    {

        for (auto settlement : settlements)
        {
            if (settlement != NULL)
            {
                delete settlement;
            }
        }
        settlements.clear();

        for (auto city : cities)
        {
            if (city != NULL)
            {
                delete city;
            }
        }
        cities.clear();

        for (auto road : roads)
        {
            if (road != NULL)
            {
                delete road;
            }
        }
        roads.clear();

        for (auto card : hand)
        {
            if (card != NULL)
            {
                delete card;
            }
            hand.clear();
        }
    }

    // Copy constructor
    Player::Player(const Player &other)
        : name(other.name), points(other.points), color(other.color), resources(other.resources), numerOfKnightCard(other.numerOfKnightCard)
    {
        for (auto settlement : other.settlements)
        {
            settlements.push_back(new Settlement(*settlement));
        }
        for (auto city : other.cities)
        {
            cities.push_back(new City(*city));
        }
        for (auto road : other.roads)
        {
            roads.push_back(new Road(*road));
        }
        for (auto card : other.hand)
        {
            hand.push_back(new Card(*card));
        }
    }

    // Overloaded assignment operator
    Player &Player::operator=(const Player &other)
    {
        if (this == &other)
            return *this; // Handle self-assignment

        // Free existing resources
        for (auto settlement : settlements)
        {
            delete settlement;
        }
        settlements.clear();

        for (auto city : cities)
        {
            delete city;
        }
        cities.clear();

        for (auto road : roads)
        {
            delete road;
        }
        roads.clear();

        for (auto card : hand)
        {
            delete card;
        }
        hand.clear();

        // Copy new resources
        name = other.name;
        points = other.points;
        color = other.color;
        resources = other.resources;
        numerOfKnightCard = other.numerOfKnightCard;

        for (auto settlement : other.settlements)
        {
            settlements.push_back(new Settlement(*settlement));
        }
        for (auto city : other.cities)
        {
            cities.push_back(new City(*city));
        }
        for (auto road : other.roads)
        {
            roads.push_back(new Road(*road));
        }
        for (auto card : other.hand)
        {
            hand.push_back(new Card(*card));
        }

        return *this;
    }

    std::string Player::getName() const
    {
        return name;
    }

    PlayerColor Player::getColor() const
    {
        return color;
    }

    /**
     * @brief Retrieves the current size of the player's hand.
     *
     * @return int The number of cards in the player's hand.
     */

    int Player::getHandSize()

    {
        return hand.size();
    }

    void Player::printResources() const
    {
        for (const auto &resource : resources)
        {
            std::cout << "Resource: " << resourceToString(resource.first) << ", Amount: " << resource.second << std::endl;
        }

        std::cout << std::endl;
    }

    void Player::removeCardRandom()
    {
        // Check if the hand is empty
        if (hand.empty())
            return;

        // Remove the first card from hand
        Card *cardToRemove = hand.front();
        delete cardToRemove;
        hand.erase(hand.begin());
    }

    /**
     * @brief Build a settlement at the specified vertex location.
     *
     * A settlement can be built if the player has enough resources and there is a road of the same player leading to the location.
     * Additionally, the settlement cannot be built if there is another settlement or city of another player within two road sections.
     *
     * @param location The vertex location where the settlement is to be built.
     */
    void Player::buildSettlement(Vertex &location)
    {
        // Check if player has enough resources
        if (resources[Resource::Brick] >= 1 && resources[Resource::Wood] >= 1 &&
            resources[Resource::Wool] >= 1 && resources[Resource::Oats] >= 1)
        {
            // Check if there is a road of the same player leading to the location
            bool roadLeadsToLocation = std::any_of(location.getRoads().begin(), location.getRoads().end(),
                                                   [this](Road *road)
                                                   { return &road->getOwner() == this; });

            if (!roadLeadsToLocation)
            {
                std::cout << "Cannot build settlement. No road of the same player leads to this location." << std::endl;
                return;
            }

            // Check if there is another settlement or city of another player within two road sections
            bool tooClose = false;

            // Check for settlement or city in the nearest vertex
            if ((location.getSettlement() && &location.getSettlement()->getOwner() != this) ||
                (location.getCity() && &location.getCity()->getOwner() != this))
            {
                tooClose = true;
            }

            // Check the roads connected to the location
            for (Road *road : location.getRoads())
            {
                // Determine the next vertex connected by the current road
                Vertex *nextVertex = (&road->getStart() == &location) ? &road->getEnd() : &road->getStart();

                // Check for settlement or city in the next vertex
                if ((nextVertex->getSettlement() && &nextVertex->getSettlement()->getOwner() != this) ||
                    (nextVertex->getCity() && &nextVertex->getCity()->getOwner() != this))
                {
                    tooClose = true;
                    break;
                }

                // Check the roads connected to the next vertex
                for (Road *adjacentRoad : nextVertex->getRoads())
                {
                    Vertex *adjacentVertex = (&adjacentRoad->getStart() == nextVertex) ? &adjacentRoad->getEnd() : &adjacentRoad->getStart();

                    // Check for settlement or city in the adjacent vertex
                    if ((adjacentVertex->getSettlement() && &adjacentVertex->getSettlement()->getOwner() != this) ||
                        (adjacentVertex->getCity() && &adjacentVertex->getCity()->getOwner() != this))
                    {
                        tooClose = true;
                        break;
                    }
                }

                if (tooClose)
                    break;
            }

            if (tooClose)
            {
                std::cout << "Cannot build settlement. Another player's settlement or city is too close." << std::endl;
                return;
            }

            // Deduct resources
            resources[Resource::Brick]--;
            resources[Resource::Wood]--;
            resources[Resource::Wool]--;
            resources[Resource::Oats]--;

            // Create and add settlement
            Settlement *settlement = new Settlement(*this, location);
            settlements.push_back(settlement);
            location.buildSettlement(settlement);

            // Update score
            updatePoints(1);
        }
        else
        {
            std::cout << "Not enough resources to build a settlement." << std::endl;
        }
    }

    void Player::buildCity(Vertex &location)
    {
        // Check if player has enough resources
        if (resources[Resource::Iron] >= 3 && resources[Resource::Oats] >= 2)
        {
            // Deduct resources
            resources[Resource::Iron] -= 3;
            resources[Resource::Oats] -= 2;

            // Check if there is a settlement at the location
            if (!location.isEmpty() && location.getSettlement() != nullptr)
            {
                // Check if the settlement belongs to the current player
                if (&location.getSettlement()->getOwner() == this)
                {
                    // Create and add city
                    City *city = new City(*this, location);
                    cities.push_back(city);
                    location.buildCity(city);

                    // Remove the settlement from the vertex and the player's settlements
                    Settlement *settlement = location.getSettlement();
                    location.removeSettlement();
                    removeSettlement(settlement);

                    // Update score
                    updatePoints(1); // Gain 2 points for a city, minus the 1 point for the settlement it replaces
                }
                else
                {
                    std::cout << "Cannot build city. There is another player's settlement at this location." << std::endl;
                }
            }
            else
            {
                std::cout << "No settlement found at this location to upgrade to a city." << std::endl;
            }
        }
        else
        {
            std::cout << "Not enough resources to build a city." << std::endl;
        }
    }

    void Player::buildRoad(Vertex &start, Vertex &end, Board *board)
    {
        // Check if player has enough resources
        if (resources[Resource::Brick] >= 1 && resources[Resource::Wood] >= 1)
        {

            // Check if a road already exists between start and end
            bool roadExists = false;
            for (Road *road : start.getRoads())
            {
                if ((&road->getStart() == &end || &road->getEnd() == &end) && &road->getOwner() != this)
                {
                    roadExists = true;
                    break;
                }
            }

            if (!roadExists)
            {
                // Check Option A: At one end of the road there is a city or settlement belonging to the player
                bool hasPlayerBuilding = (start.getSettlement() && &start.getSettlement()->getOwner() == this) ||
                                         (start.getCity() && &start.getCity()->getOwner() == this) ||
                                         (end.getSettlement() && &end.getSettlement()->getOwner() == this) ||
                                         (end.getCity() && &end.getCity()->getOwner() == this);

                // Check Option B: Connect to another road section that the player owns
                bool connectsToPlayerRoad = std::any_of(start.getRoads().begin(), start.getRoads().end(),
                                                        [this](Road *road)
                                                        { return &road->getOwner() == this; }) ||
                                            std::any_of(end.getRoads().begin(), end.getRoads().end(),
                                                        [this](Road *road)
                                                        { return &road->getOwner() == this; });

                // Check if any condition is met
                if (hasPlayerBuilding || connectsToPlayerRoad)
                {
                    // Deduct resources
                    resources[Resource::Brick]--;
                    resources[Resource::Wood]--;

                    // Create and add road
                    Road *road = new Road(*this, start, end);
                    roads.push_back(road);
                    start.buildRoad(road);
                    end.buildRoad(road);
                    Edge *edge = board->findEdge(start.getNumber(), end.getNumber());
                    edge->buildRoad(road);

                    std::cout << "The road was successfully built!" << std::endl;
                }
                else
                {
                    std::cout << "Cannot build road: Must be connected to a building or another road of the player." << std::endl;
                }
            }
            else
            {
                std::cout << "Cannot build road: A road already exists between these vertices." << std::endl;
            }
        }
        else
        {
            std::cout << "Not enough resources to build a road." << std::endl;
        }
    }

    int Player::getPoints() const
    {
        return points;
    }

    void Player::updatePoints(int p)
    {
        points = points + p;

        if (points >= 10)
        {
            std::cout << name << " wins the game with " << points << " points!" << std::endl;
        }
    }

    void Player::removeSettlement(Settlement *settlement)
    {
        auto it = std::find(settlements.begin(), settlements.end(), settlement);
        if (it != settlements.end())
        {
            settlements.erase(it);
            delete settlement; // Assuming settlements are dynamically allocated and need to be deleted
        }
    }

    // A function that at the beginning of the game assigns 2 settlements and 2 roads to each player

    void Player::initializeStartingPositions(Vertex &settlement1, Vertex &settlement2, Edge &road1, Edge &road2)
    {
        // Build first settlement
        Settlement *s1 = new Settlement(*this, settlement1);
        settlements.push_back(s1);
        settlement1.buildSettlement(s1);

        // Build first road
        Vertex &start1 = *(road1.getVertex1());
        Vertex &end1 = *(road1.getVertex2());
        Road *r1 = new Road(*this, start1, end1);
        roads.push_back(r1);
        road1.buildRoad(r1);
        start1.buildRoad(r1);
        end1.buildRoad(r1);

        // Build second settlement
        Settlement *s2 = new Settlement(*this, settlement2);
        settlements.push_back(s2);
        settlement2.buildSettlement(s2);

        // Build second road
        Vertex &start2 = *(road2.getVertex1());
        Vertex &end2 = *(road2.getVertex2());
        Road *r2 = new Road(*this, start2, end2);
        roads.push_back(r2);
        road2.buildRoad(r2);
        start2.buildRoad(r2);
        end2.buildRoad(r2);

        // Add starting victory points
        updatePoints(2);

        // Distribute starting resources
        distributeStartingResources(settlement1);
        distributeStartingResources(settlement2);
    }

    // A function that distributes resources at the beginning of the game according to the settlements belonging to the player
    void Player::distributeStartingResources(Vertex &settlement)
    {
        for (Resource resource : settlement.getResources())
        {
            resources[resource]++;
        }
    }

    Card *Player::buyCard()
    {
        // Check if the player has enough resources
        if (resources[Resource::Iron] < 1 || resources[Resource::Wool] < 1 || resources[Resource::Oats] < 1)
        {
            throw std::runtime_error("Not enough resources to buy a promotion card.\n");
        }

        // Deduct the resources
        resources[Resource::Iron]--;
        resources[Resource::Wool]--;
        resources[Resource::Oats]--;

        int rand = randNumberForCard();
        Card *newCard;
        if (rand <= 33)
        {

            // Randomly select a promotion card type
            PromotionType randomType = static_cast<PromotionType>(rand % 3);

            // Create a new promotion card and add it to the player's hand
            newCard = new PromotionCard(randomType);
            hand.push_back(newCard);

            std::cout << getName() << " bought a " << (randomType == PromotionType::Monopoly ? "Monopoly" : randomType == PromotionType::BuildingRoads ? "Building Roads"
                                                                                                                                                       : "Year of Abundance")
                      << " card.\n";
        }

        else if (33 < rand && rand <= 66)
        {
            newCard = new KnightCard();

            std::cout << getName() << " bought a knight card " << std::endl;

            numerOfKnightCard++;
            if (numerOfKnightCard >= 3)
            {
                updatePoints(2);
            }
        }

        else
        {
            newCard = new VictoryPointCard();
            updatePoints(1);
            std::cout << getName() << " bought a victory point card " << std::endl;
        }

        return newCard;
    }

    void Player::usePromotionCard(Card *card, Catan *catan, Resource resource1, Resource resource2, int starting_point_road, int ending_point_road)
    {
        card->use(*this, *catan, resource1, resource2, this->getName(), starting_point_road, ending_point_road);
        hand.erase(std::remove(hand.begin(), hand.end(), card), hand.end());
        delete card;
    }

    // An auxiliary function for realizing a Monopoly card

    bool Player::checkAndTakeResource(Resource resource)
    {
        auto it = resources.find(resource);
        if (it != resources.end() && it->second > 0)
        {
            it->second--;
            return true;
        }
        return false;
    }

    void Player::setResource(Resource resource, int count)
    {
        resources[resource] += count;
    }

    // A function that helps draw a random card from the pack

    int Player::randNumberForCard()
    {
        // Use the current time as a seed for the random number generator
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator(seed);

        // Define a distribution for generating integers in a range (e.g., 1 to 100)
        std::uniform_int_distribution<int> distribution(1, 100);

        // Generate a random number using the generator and distribution
        int randomNumber = distribution(generator);

        return randomNumber;
    }

    // Check if the player has enough of a specific resource
    bool Player::hasResource(Resource resource, int quantity) const
    {

        auto it = resources.find(resource);
        if (it != resources.end())
        {
            return it->second >= quantity;
        }
        return false;
    }

    bool Player::removeResource(Resource resource, int quantity)
    {
        if (hasResource(resource, quantity))
        {
            resources[resource] -= quantity;

            return true; // Resource successfully removed
        }
        return false; // Resource removal failed (not enough resources)
    }
    // Add a specified quantity of a resource to the player's inventory
    void Player::addResource(Resource resource, int quantity)
    {
        resources[resource] += quantity;
    }

    bool Player::hasCard(Card *card) const
    {
        // Check if the card is in the hand vector
        return std::find(hand.begin(), hand.end(), card) != hand.end();
    }

    void Player::removeCard(Card *card)
    {
        // Remove the card from the hand vector
        auto it = std::find(hand.begin(), hand.end(), card);
        if (it != hand.end())
        {
            hand.erase(it);
            delete card;
        }
    }

    void Player::addCard(Card *card)
    {
        // Add the card to the hand vector
        hand.push_back(card);
    }

    void Player::tradeCard(Player &otherPlayer, Card &offeredCard, Card &desiredCard)
    {
        // Verify if the other player agrees to the trade conditions
        // For simplicity, assuming direct trade without complex negotiation
        if (hasCard(&offeredCard) && otherPlayer.hasCard(&desiredCard))
        {
            // Perform the trade
            removeCard(&offeredCard);
            otherPlayer.addCard(&offeredCard);

            otherPlayer.removeCard(&desiredCard);
            addCard(&desiredCard);

            std::cout << "Card trade successful!" << std::endl;
        }
        else
        {
            std::cout << "Card trade failed. Either player does not possess the required card." << std::endl;
        }
    }

    void Player::tradeResources(Player &otherPlayer, Resource offeredResource, Resource desiredResource, int quantity)
    {
        // Verify if the other player agrees to the trade conditions
        if (hasResource(offeredResource, quantity) && otherPlayer.hasResource(desiredResource, quantity))
        {
            // Perform the trade
            removeResource(offeredResource, quantity);
            addResource(desiredResource, quantity);

            otherPlayer.removeResource(desiredResource, quantity);
            otherPlayer.addResource(offeredResource, quantity);

            std::cout << "Trade successful!" << std::endl;
        }
        else
        {
            std::cout << "Trade failed. Insufficient resources or disagreement." << std::endl;
        }
    }

    void Player::rollDice(Catan *catan)
    {
        // Use the current time as a seed for the random number generator
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator(seed);

        // Define a distribution for generating integers in a range (e.g., 2 to 12)
        std::uniform_int_distribution<int> distribution(2, 12);

        // Generate a random number using the generator and distribution
        int diceRoll = distribution(generator);

        // Logic to roll dice
        std::cout << "Dice rolled: " << diceRoll << std::endl;

        // Flag to check if any player needs to discard cards

        // Distribute resources based on the dice roll
        catan->distributeResources(diceRoll);

        if (diceRoll == 7)
        {
            std::cout << "Players with more than 7 cards must discard half of their cards.\n";
            // Iterate through all players again to discard cards
            for (auto &player : catan->getPlayersVector())
            {

                // Check if the player has more than 7 cards
                if (player.getHandSize() > 7)
                {
                    // Calculate the number of cards to discard (half of the current hand size)
                    int cardsToDiscard = player.getHandSize() / 2;
                    std::cout << player.getName() << " has more than 7 cards. Discarding " << cardsToDiscard << " cards.\n";

                    // Randomly discard cards from the player's hand
                    for (int i = 0; i < cardsToDiscard; ++i)
                    {
                        // Remove the card from hand and free its memory
                        player.removeCardRandom(); // Assuming a method like removeCard exists
                    }
                }
            }
        }
    }
}