/**ID:206751976
Email:"aharonba123@gmail.com"
*/

#ifndef CITY_HPP
#define CITY_HPP

namespace ariel {

    class Player;
    class Vertex;

    class City {
    public:
        City(Player& owner, Vertex& location) : owner(owner), location(location) {}

        Player& getOwner() const {return owner;};
        Vertex& getLocation() const{return location;};

    private:
        Player& owner;
        Vertex& location;
    };

}

#endif // CITY_HPP
