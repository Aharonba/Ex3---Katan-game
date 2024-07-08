#ifndef CARD_HPP
#define CARD_HPP

// Forward declaration to avoid circular dependency
class Player;
class Board;

namespace ariel
{
    class Card
    {
    public:
        virtual ~Card() = default;
        virtual void use(Player &player, Board &board) = 0; // Pure virtual function to use the card
    };

    enum class PromotionType
    {
        Monopoly,
        BuildingRoads,
        YearOfAbundance
    };

    class PromotionCard : public Card
    {
    private:
        PromotionType type;

    public:
        PromotionCard(PromotionType type) : type(type) {}

        void use(Player &player, Board &board) override;
    };

    class KnightCard : public Card
    {
    public:
        void use(Player &player, Board &board) override;
    };

    class VictoryPointCard : public Card
    {
    public:
        void use(Player &player, Board &board) override;
    };
}
#endif // CARD_HPP
