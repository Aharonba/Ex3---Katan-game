#include "Card.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "Catan.hpp"
#include <iostream>
#include <string>

using namespace ariel;

PromotionCard::PromotionCard(PromotionType type) : type(type) {}

// PromotionCard use method implementation
void PromotionCard::use(Player &player, Catan &catan, Resource resource1, Resource resource2, std::string name, int starting_point_road, int ending_point_road)
{
    int counter = 0;
    switch (type)
    {
    case PromotionType::Monopoly:
        std::cout << player.getName() << " plays Monopoly card.\n";
        if (catan.getPlayer1().getName() != name && catan.getPlayer1().checkAndTakeResource(resource1))
        {
            counter++;
        }

        if (catan.getPlayer1().getName() != name && catan.getPlayer2().checkAndTakeResource(resource1))
        {
            counter++;
        }

        if (catan.getPlayer1().getName() != name && catan.getPlayer3().checkAndTakeResource(resource1))
        {
            counter++;
        }

        player.setResource(resource1, counter);

        break;
    case PromotionType::BuildingRoads:
        std::cout << player.getName() << " plays Building Roads card.\n";
        player.buildRoad(*(catan.getBoard()->getVertex(starting_point_road)), *(catan.getBoard()->getVertex(ending_point_road)),catan.getBoard());

        break;
    case PromotionType::YearOfAbundance:
        std::cout << player.getName() << " plays Year of Abundance card.\n";
        player.setResource(resource1, 1);
        player.setResource(resource2, 1);
        break;
    }
}

