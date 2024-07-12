/**ID:206751976
Email:"aharonba123@gmail.com"
*/

#ifndef SETTLEMENT_HPP
#define SETTLEMENT_HPP

namespace ariel
{

    class Player;
    class Vertex;

    class Settlement
    {
    public:
        Settlement(Player &owner, Vertex &location) : owner(owner), location(location) {}

        Player &getOwner() const { return owner; }
        Vertex &getLocation() { return location; }

    private:
        Player &owner;
        Vertex &location;
    };

}

#endif // SETTLEMENT_HPP
