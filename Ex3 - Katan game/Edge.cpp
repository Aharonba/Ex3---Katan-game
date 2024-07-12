/**ID:206751976
Email:"aharonba123@gmail.com"
*/


#include "Edge.hpp"
#include "Player.hpp"
#include "Road.hpp"

using namespace ariel;

Edge::Edge(Vertex *v1, Vertex *v2, int num)
    : vertex1(v1), vertex2(v2), number(num), edge_color(PlayerColor::None), road(nullptr)
{
}

Vertex *Edge::getVertex1() const
{
    return vertex1;
}

int Edge::getNumber() const
{
    return number;
}

Vertex *Edge::getVertex2() const
{
    return vertex2;
}

std::string Edge::getColor() const
{
    return ColorToString(edge_color);
}

void Edge::setColor(int color)
{
    edge_color = static_cast<PlayerColor>(color);
}

std::string Edge::ColorToString(PlayerColor color) const
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

bool Edge::hasRoad() const { return road != nullptr; }

void Edge::buildRoad(Road *newRoad)
{
    if (!hasRoad())
    {
        road = newRoad;
    }
}

Road *Edge::getRoad() const { return road; }

