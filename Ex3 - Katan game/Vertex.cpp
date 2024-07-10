#include "Vertex.hpp"
#include "Settlement.hpp"
#include "City.hpp"
#include "Player.hpp"
#include "Resource.hpp"

using namespace ariel;

Vertex::Vertex(int num) : number(num), settlement(nullptr), city(nullptr)
{
}

int Vertex::getNumber() const
{
    return number;
}

std::string Vertex::getColorVertex() const
{
    PlayerColor color;
    if (settlement)
        return ColorToString(settlement->getOwner().getColor());
    if (city)
        return ColorToString(city->getOwner().getColor());
    return "None";
}

bool Vertex::isEmpty() const
{
    return settlement == nullptr && city == nullptr;
}

void Vertex::buildSettlement(Settlement *s)
{
    settlement = s;
}

void Vertex::buildCity(City *c)
{
    city = c;
}

void Vertex::buildRoad(Road *road)
{
    roads.push_back(road);
}

const std::vector<Road *> &Vertex::getRoads() const
{
    return roads;
}

void Vertex::removeSettlement()
{
    settlement = nullptr;
}

std::string Vertex::ColorToString(PlayerColor color) const
{
    switch (color)
    {
    case PlayerColor::None:
        return "None";
    case PlayerColor::Red:
        return "Red";
    case PlayerColor::Blue:
        return "Blue";
    case PlayerColor::Purple:
        return "Purple";
    default:
        return "Unknown";
    }
}

Settlement *Vertex::getSettlement() const
{
    return settlement;
}

City *Vertex::getCity() const
{
    return city;
}

const std::vector<Resource> &Vertex::getResources() const { return resources; }

void Vertex::addResource(Resource res) { resources.push_back(res); }

void Vertex::addAdjacentTile(int tileNumber) { adjacentTiles.push_back(tileNumber); }
const std::vector<int> &Vertex::getAdjacentTiles() const { return adjacentTiles; }

void Vertex::printResources()
{
    for (auto resource : resources)
    {
        std::cout << resourceToString(resource) << std::endl;
    }
}

bool Vertex::hasSettlement() const{
    return  settlement != NULL;
}
bool Vertex::hasCity() const{
    return city != NULL;
}
