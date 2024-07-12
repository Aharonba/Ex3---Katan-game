/**ID:206751976
Email:"aharonba123@gmail.com"
*/

#ifndef ROAD_HPP
#define ROAD_HPP

#include "Player.hpp"
#include "Vertex.hpp"

namespace ariel {

    class Road {
    public:
        Road(Player &owner, Vertex &start, Vertex &end) : owner(owner), start(start), end(end) {}

        Player& getOwner() const { return owner; }
        Vertex& getStart() const { return start; }
        Vertex& getEnd() const { return end; }

    private:
        Player &owner;
        Vertex &start;
        Vertex &end;
    };

}

#endif // ROAD_HPP
