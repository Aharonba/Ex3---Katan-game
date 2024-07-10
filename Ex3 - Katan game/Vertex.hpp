#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <string>
#include <vector>
#include <iostream>

namespace ariel
{

    class Settlement;
    class City;
    class Road;
    enum class PlayerColor;
    enum class Resource;

    class Vertex
    {
    private:
        int number;
        Settlement *settlement;
        City *city;
        std::vector<Road *> roads;
        std::vector<Resource> resources;
        std::vector<int> adjacentTiles;

    public:
        Vertex(int num);
        int getNumber() const;
        std::string getColorVertex() const;
        void setColor(PlayerColor color);
        bool isEmpty() const;
        void buildSettlement(Settlement *s);
        void removeSettlement();
        void buildCity(City *c);
        std::string ColorToString(PlayerColor color) const;
        void buildRoad(Road *road);
        const std::vector<Road *> &getRoads() const;
        Settlement *getSettlement() const;
        City *getCity() const;
        bool hasSettlement() const;
        bool hasCity() const;
        const std::vector<Resource> &getResources() const;
        void addResource(Resource res);
        void printResources();
        void addAdjacentTile (int tileNumber); 
        const std::vector<int> &getAdjacentTiles() const;
    };

}

#endif // VERTEX_HPP
