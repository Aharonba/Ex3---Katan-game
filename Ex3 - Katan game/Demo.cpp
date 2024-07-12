/**ID:206751976
Email:"aharonba123@gmail.com"
*/


#include <iostream>
#include <stdexcept>
#include <vector>

#include "Player.hpp"
#include "Catan.hpp"
#include "Resource.hpp"
#include "Vertex.hpp"
#include "Edge.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Settlement.hpp"
#include "Road.hpp"

using namespace ariel;

int main()
{
  Player p1("Amit", PlayerColor::Blue);
  Player p2("Yossi", PlayerColor::Red);
  Player p3("Dana", PlayerColor::Purple);

  Catan catan(p1, p2, p3); // create catan with 3 players

  // print description about players
  std::cout << "The Players are: " << std::endl;
  catan.printPlayers();

  p1.printResources();
  p2.printResources();
  p3.printResources();

  std::cout << "Let's start the game!" << std::endl
            << std::endl;

  // // The order of play will be as follows: p1, p2, p3

  // // Player p1's turn move
  p1.rollDice(&catan);
  p1.buildRoad(*(catan.getBoard()->getVertex(9)), *(catan.getBoard()->getVertex(2)), catan.getBoard()); // Building a road on edge number 10

  // /** p1 and p2 traders:
  //  p1 passes 2 wool
  //  p2 passes 2 trees
  //  */

  p1.tradeResources(p2, Resource::Wool, Resource::Wood, 2);

  p1.printResources(); // Indication to see that p1 loses 2 wool and gains 2 trees
  p2.printResources(); // Indication to see that p2 loses 2 trees and gains 2 wool

  // // Player p2's turn move
  p2.rollDice(&catan);

  // // Adds resources to p2 in order to demonstrate the operation of building a settlement

  p2.addResource(Resource::Oats, 1);
  p2.addResource(Resource::Brick, 1);

  p2.buildSettlement(*(catan.getBoard()->getVertex(25)));

  // /**
  //  * board printing.
  //  * The new road of player p1 can be seen on edge number 10.
  //  * and the new settlement of player p2 on vertex number 25.
  //  */

  catan.getBoard()->printBoard();

  try
  {
    p2.buyCard();
    std::cout << "Player2 successfully bought a card." << std::endl;
  }
  catch (const std::runtime_error &e)
  {
    std::cerr << "Player2 failed to buy a card: " << e.what() << std::endl;
  }

  // // Player p3's turn move

  p3.rollDice(&catan);

  // Added a resource to demonstrate buying a card and using it
  p3.addResource(Resource::Oats, 1);

  try
  {
    Card *c3 = p3.buyCard();
    p3.usePromotionCard(c3, &catan, Resource::Brick, Resource::Wood, 24, 20);
  }
  catch (const std::runtime_error &e)
  {
    std::cerr << "Player3 failed to buy a card: " << e.what() << std::endl;
  }

  std::cout << "Player 1 points: " << p1.getPoints() << std::endl;
  std::cout << "Player 2 points: " << p2.getPoints() << std::endl;
  std::cout << "Player 3 points: " << p3.getPoints() << std::endl;
}