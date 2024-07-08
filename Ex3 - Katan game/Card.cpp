#include "Card.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include <iostream>

namespace ariel {

    // Implementation of PromotionCard constructor
    PromotionCard::PromotionCard(PromotionType type) : type(type) {}

    // Implementation of PromotionCard use method
    void PromotionCard::use(Player &player, Board &board) {
        // Implement logic based on PromotionType
        switch (type) {
            case PromotionType::Monopoly:
                std::cout << player.getName() << " plays Monopoly card.\n";
                // Implement Monopoly logic
                break;
            case PromotionType::BuildingRoads:
                std::cout << player.getName() << " plays Building Roads card.\n";
                // Implement Building Roads logic
                break;
            case PromotionType::YearOfAbundance:
                std::cout << player.getName() << " plays Year of Abundance card.\n";
                // Implement Year of Abundance logic
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
