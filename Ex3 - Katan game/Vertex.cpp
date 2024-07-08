#include "Vertex.hpp"
#include "Settlement.hpp"
#include "City.hpp"
#include "Player.hpp"

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
    case PlayerColor::Yellow:
        return "Yellow";
    default:
        return "Unknown";
    }
}

Settlement *Vertex::getSettlement() const
{
    return settlement;
}
