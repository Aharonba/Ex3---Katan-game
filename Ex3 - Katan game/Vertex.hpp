#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <string>
#include <vector>

namespace ariel {

    class Settlement;
    class City;
    class Road;
    enum class PlayerColor;

    class Vertex {
    private:
        int number;
        Settlement* settlement;
        City* city;
        std::vector<Road*> roads;

    public:
        Vertex(int num);
        int getNumber() const;
        std::string getColorVertex() const;
        void setColor(PlayerColor color);
        bool isEmpty() const;
        void buildSettlement(Settlement* s);
        void buildCity(City* c);
        std::string ColorToString(PlayerColor color) const;
        void buildRoad(Road* road);
        const std::vector<Road*>& getRoads() const;
        Settlement* getSettlement() const;
    };

}

#endif // VERTEX_HPP
