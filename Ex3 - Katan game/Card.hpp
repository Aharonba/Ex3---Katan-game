#ifndef CARD_HPP
#define CARD_HPP

// Forward declaration to avoid circular dependency

#include <string>

namespace ariel
{
    class Player;
    class Board;
    class Catan;
    enum class Resource;

    class Card
    {
    public:
        virtual ~Card() = default;
        virtual void use(Player &player, Catan &catan, Resource resource1, Resource resource2, std::string name, int starting_point_road, int ending_point_road){return;};

    };

    enum class PromotionType
    {
        Monopoly,
        BuildingRoads,
        YearOfAbundance,
    };

    //////////////

    class PromotionCard : public Card
    {
    private:
        PromotionType type;

    public:
        PromotionCard(PromotionType type);

        void use(Player &player, Catan &catan, Resource resource1, Resource resource2, std::string name, int starting_point_road, int ending_point_road);
    };

    ///////////////

    class KnightCard : public Card
    {
    };

    // //////////////

    class VictoryPointCard : public Card
    {
    };
};
#endif // CARD_HPP
