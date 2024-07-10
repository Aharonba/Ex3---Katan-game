#include "Card.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "Catan.hpp"
#include <iostream>
#include <string>

using namespace ariel;

// Implementation of PromotionCard constructor
PromotionCard::PromotionCard(PromotionType type) : type(type) {}

// Implementation of PromotionCard use method
void PromotionCard::use(Player &player, Catan &catan, Resource resource1, Resource resource2, std::string name, int starting_point_road, int ending_point_road)
{
    int counter = 0;
    // Implement logic based on PromotionType
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
        player.buildRoad(*(catan.getBoard()->getVertex(starting_point_road)), *(catan.getBoard()->getVertex(ending_point_road)));

        break;
    case PromotionType::YearOfAbundance:
        std::cout << player.getName() << " plays Year of Abundance card.\n";
        player.setResource(resource1, 1);
        player.setResource(resource2, 1);
        break;
    }
}

//     // Implementation of KnightCard use method
//     void KnightCard::use(Player &player, Board &board) {
//         std::cout << player.getName() << " plays Knight card.\n";
//         // Implement Knight card logic
//     }

//     // Implementation of VictoryPointCard constructor
//     VictoryPointCard::VictoryPointCard(int points) : points(points) {}

//     // Implementation of VictoryPointCard use method
//     void VictoryPointCard::use(Player &player, Board &board) {
//         std::cout << player.getName() << " plays Victory Point card (+1 point).\n";
//         player.addPoints(points); // Assuming a method like addPoints exists in Player
//     }

// } // namespace ariel
