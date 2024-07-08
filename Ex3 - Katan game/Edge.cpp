#include "Edge.hpp"
#include "Player.hpp"

using namespace ariel;



Edge::Edge(Vertex *v1, Vertex *v2, int num)
    : vertex1(v1), vertex2(v2), is_empty(true), number(num), edge_color(PlayerColor::None)
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

bool Edge::isEmpty() const
{
    return is_empty;
}

void Edge::build()
{
    is_empty = false;
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
    case PlayerColor::Yellow:
        return "Yellow";
    default:
        return "Unknown";
    }
}