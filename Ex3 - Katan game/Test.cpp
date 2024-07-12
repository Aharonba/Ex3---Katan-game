// #define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
// #include "Catan.hpp"
// #include "Player.hpp"
// #include "doctest.h"

// using namespace doctest;
// using namespace std;
// using namespace ariel;  // Adjust namespace to match your implementation


// void before_each() {
//     Player p1 = Player("p1",PlayerColor::Blue);
//     Player p2 = Player("p2",PlayerColor::Red);
//     Player p3 = Player("p3",PlayerColor::Purple);
//     Catan catan(p1, p2, p3);

// }


// TEST_CASE("Initial Placement Validation") {
//     before_each();

//     SUBCASE("Invalid INITIAL settlement/road placement") {
//         SUBCASE("placing road too far from settlement") {
//             CHECK(p1.buildRoad(cata, game));
//         }

//         SUBCASE("placing road too close to settlement") {
//             CHECK_THROWS(_p2.placeInitialSettlement(5, game));
//         }

//         SUBCASE("placing 3rd initial settlement") {
//             CHECK_THROWS(_p2.placeInitialSettlement(22, game));
//         }

//         CHECK_THROWS(_p2.placeInitialSettlement(54, game));  // Example out of bounds check
//     }

//     SUBCASE("Valid INITIAL placement") {
//         // Modify for your specific validation checks if needed
//         CHECK_NOTHROW(_p1.placeInitialSettlement(3, game));
//         CHECK_NOTHROW(_p1.placeInitialRoad(8, game));
//     }
// }

// TEST_CASE("Invalid Settlement/City/Road Placements") {
//     before_each();

//     SUBCASE("placing settlement on top of another settlement") {
//         CHECK_THROWS(_p1.placeSettlement(25, game));
//     }

//     SUBCASE("placing settlement too close to another settlement") {
//         CHECK_THROWS(_p1.placeSettlement(20, game));
//     }

//     SUBCASE("placing settlement too far from road") {
//         CHECK_THROWS(_p1.placeSettlement(26, game));
//     }

//     SUBCASE("placing settlement on top of another city") {
//         _p1.placeCity(25, game);
//         CHECK_THROWS(_p1.placeSettlement(25, game));
//     }

//     SUBCASE("placing city on top of another city") {
//         _p1.placeCity(25, game);
//         CHECK_THROWS(_p1.placeCity(25, game));
//     }

//     SUBCASE("placing city on top of another player's settlement") {
//         _p1.placeCity(25, game);
//         game.endTurn();
//         CHECK_THROWS(_p2.placeCity(25, game));
//     }

//     SUBCASE("placing road on top of another road") {
//         CHECK_THROWS(_p1.placeRoad(31, game));
//     }

//     SUBCASE("placing road too far from settlement") {
//         CHECK_THROWS(_p1.placeRoad(47, game));
//     }

//     SUBCASE("trying to build without required resources") {
//         _p1.placeRoad(32, game);
//         _p1.placeSettlement(26, game);
//         _p1.placeRoad(38, game);
//         _p1.placeCity(26, game);
//         _p1.placeCity(2, game);
//         CHECK_THROWS(_p1.placeCity(25, game));
//     }

//     SUBCASE("trying to build on top of a road") {
//         _p1.placeRoad(32, game);
//         CHECK_THROWS(_p1.placeSettlement(32, game));
//         CHECK_THROWS(_p1.placeCity(32, game));
//     }
// }

// TEST_CASE("Invalid Development Card Usage") {
//     before_each();

//     SUBCASE("trying to play a development card without having one") {
//         CHECK_FALSE(_p1.useYearOfPlenty("wool", "lumber", game));
//     }

//     SUBCASE("trying to play a development card in the same turn it was bought") {
//         _p1.buyDevelopmentCard("yearOfPlenty", game);
//         CHECK_FALSE(_p1.useYearOfPlenty("wool", "lumber", game));
//     }

//     SUBCASE("trying to play a development card that has already been played") {
//         _p1.buyDevelopmentCard("roadBuilding", game);
//         _p1.useRoadBuilding(3, 4, game);
//         CHECK_FALSE(_p1.useRoadBuilding(3, 4, game));
//     }
// }

// TEST_CASE("Invalid Trades") {
//     before_each();

//     SUBCASE("trying to trade with the bank without having enough resources") {
//         CHECK_FALSE(_p1.tradeWithBank({{"wheat", 1}}, {{"ore", 1}}, game));
//     }

//     SUBCASE("trying to trade with another player without having enough resources") {
//         CHECK_FALSE(_p1.trade({{"brick", 9}}, {{"wheat", 1}, {"wool", 1}}, _p2));
//     }

//     SUBCASE("trying to trade with another player without him having enough resources") {
//         CHECK_FALSE(_p1.trade({{"brick", 1}}, {{"wheat", 9}, {"wool", 9}}, _p2));
//     }

//     SUBCASE("trying to trade with myself") {
//         CHECK_FALSE(_p1.trade({{"brick", 1}}, {{"wheat", 1}, {"wool", 1}}, _p1));
//     }
// }

// TEST_CASE("Playing out of turn") {
//     before_each();

//     SUBCASE("trying to place initial settlement out of turn") {
//         CHECK_THROWS(_p1.placeInitialSettlement(13, game));
//     }

//     SUBCASE("trying to place settlement out of turn") {
//         game.endTurn();
//         CHECK_THROWS(_p1.placeSettlement(12, game));
//     }

//     SUBCASE("trying to place road out of turn") {
//         game.endTurn();
//         CHECK_THROWS(_p1.placeRoad(11, game));
//     }

//     SUBCASE("trying to trade with bank out of turn") {
//         game.endTurn();
//         CHECK_THROWS(_p1.tradeWithBank({{"wheat", 1}}, {{"ore", 1}}, game));
//     }

//     SUBCASE("trying to trade with another player out of turn") {
//         game.endTurn();
//         CHECK_FALSE(_p1.trade({{"brick", 1}, {"lumber", 1}}, {{"wheat", 1}, {"wool", 1}}, _p3));
//     }

//     SUBCASE("trying to buy a development card out of turn") {
//         game.endTurn();
//         CHECK_THROWS(_p3.buyDevelopmentCard("knight", game));
//     }

//     SUBCASE("trying to roll the dice out of turn") {
//         game.endTurn();
//         CHECK_THROWS(_p3.rollDice(6));
//     }
// }

// TEST_CASE("Resource Management") {
//     before_each();

//     SUBCASE("initial resource distribution") {
//         // Example initial resource setup verification
//         auto p1Resources = _p1.getAllResources();
//         CHECK(p1Resources[Resource::Brick] == 1);
//         CHECK(p1Resources[Resource::Wood] == 1);
//         CHECK(p1Resources[Resource::Sheep] == 1);
//         CHECK(p1Resources[Resource::Wheat] == 1);
//         CHECK(p1Resources[Resource::Ore] == 0);  // Example of expected initial resource count
//     }

//     SUBCASE("resource addition and removal") {
//         _p1.addResource(Resource::Brick, 2);
//         CHECK(_p1.getResource(Resource::Brick) == 3);

//         _p1.removeResource(Resource::Wood, 1);
//         CHECK(_p1.getResource(Resource::Wood) == 0);

//         _p1.removeResource(Resource::Sheep, 1);
//         CHECK(_p1.getResource(Resource::Sheep) == 0);
//     }
// }

// // Add more test cases as needed to cover all aspects of your Catan game implementation

// DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
