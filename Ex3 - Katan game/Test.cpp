#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Catan.hpp"
#include "Player.hpp"
#include "doctest.h"
#include "City.hpp"
#include "Settlement.hpp"
#include "Road.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Card.hpp"
#include "Resource.hpp"
#include "Board.hpp"
#include <stdexcept>
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>

using namespace doctest;
using namespace std;
using namespace ariel;

Player p1 = Player("Amit", PlayerColor::Blue);

Player p2 = Player("Yossi", PlayerColor::Red);

Player p3 = Player("Dana", PlayerColor::Purple);

Catan game(p1, p2, p3);

void before_each()
{
    p1 = Player("Amit", PlayerColor::Blue);

    p2 = Player("Yossi", PlayerColor::Red);

    p3 = Player("Dana", PlayerColor::Purple);

    game = Catan(p1, p2, p3);
}

TEST_CASE("Invalid INITIAL settlement/road placement")
{
    before_each();

    SUBCASE("placing road too far from settlement")
    {
        p1.addResource(Resource::Brick, 1);
        p1.addResource(Resource::Wood, 1);
        CHECK_THROWS(p1.buildRoad(*(game.getBoard()->getVertex(16)), *(game.getBoard()->getVertex(15)), game.getBoard())); // too far from settlement
    }

    SUBCASE("placing road too close to p3 settlement")
    {
        p2.addResource(Resource::Brick, 1);
        p2.addResource(Resource::Wood, 1);
        CHECK_THROWS(p2.buildRoad(*(game.getBoard()->getVertex(23)), *(game.getBoard()->getVertex(24)), game.getBoard())); // too close to p3 settlement
    }

    SUBCASE("placing 3rd initial settlement")
    {
        p3.addResource(Resource::Oats, 1);
        CHECK_THROWS(p3.buildSettlement(*(game.getBoard()->getVertex(29)))); // already placed 2 initial settlements.
    }

    SUBCASE("An attempt to build a city in a place where there is no settlement")
    {
        p3.addResource(Resource::Oats, 2);
        p3.addResource(Resource::Iron, 1);
        CHECK_THROWS(p3.buildCity(*(game.getBoard()->getVertex(37)))); // already placed 2 initial settlements.
    }

    CHECK_THROWS(p3.buildSettlement(*(game.getBoard()->getVertex(100)))); // OUT OF BOUNDS
    CHECK_THROWS(p3.buildSettlement(*(game.getBoard()->getVertex(-50)))); // OUT OF BOUNDS
}

TEST_CASE("Invalid Building or Buying due to Insufficient Resources")
{
    before_each();

    SUBCASE("Building Road with Insufficient Resources")
    {

        // Attempt to build a road but he dosent have brick
        CHECK_THROWS(p2.buildRoad(*(game.getBoard()->getVertex(29)), *(game.getBoard()->getVertex(19)), game.getBoard())); // Expecting exception due to insufficient resources
    }

    SUBCASE("Building Settlement with Insufficient Resources")
    {
        // Assume player1 starts with insufficient resources
        CHECK_THROWS(p1.buildSettlement(*(game.getBoard()->getVertex(7))));

        // Attempt to build a settlement
        CHECK_THROWS(p3.buildSettlement(*(game.getBoard()->getVertex(34))));
        // Expecting exception due to insufficient resources
    }

    SUBCASE("Buying Development Card with Insufficient Resources")
    {                               // Attempt to buy a development card
        CHECK_THROWS(p1.buyCard()); // Expecting exception due to insufficient resources
    }
}

TEST_CASE("Invalid trades")
{
    before_each();
    SUBCASE("trying to trade with another player without having enough resources")
    {
        CHECK_THROWS(p1.tradeResources(p3, Resource::Oats, Resource::Wood, 1));
    }
    SUBCASE("trying to trade with another player without him having enough resources")
    {
        CHECK_THROWS(p1.tradeResources(p3, Resource::Wool, Resource::Oats, 2));
    }
    SUBCASE("trying to trade with myself")
    {
        CHECK_THROWS(p1.tradeResources(p1, Resource::Wool, Resource::Oats, 1));
    }
}

TEST_CASE("Successful Trade")
{
    before_each();
    CHECK_NOTHROW(p1.tradeResources(p3, Resource::Wool, Resource::Brick, 1));
    CHECK_NOTHROW(p1.tradeResources(p2, Resource::Wool, Resource::Wood, 1));
}

TEST_CASE("Resource Management")
{
    before_each();
    CHECK(p1.hasResource(Resource::Oats, 2) == false);
    p1.addResource(Resource::Oats, 2);
    CHECK(p1.hasResource(Resource::Oats, 2) == true);
}


TEST_CASE("Auxiliary function test")
{
    before_each();
    //Testing a helper function for using the Monopoly card
    CHECK(p1.checkAndTakeResource(Resource::Wool) == true);
    CHECK(p1.hasResource(Resource::Wool,3) == true);
}
