#include "Vertex.hpp"

using namespace ariel;

    Vertex::Vertex(int num) 
        : number(num), vertex_color(PlayerColor::None), is_empty(true)
    {}

    int Vertex::getNumber() const{
        return number;
    }

    std::string Vertex::getColor() const{
        return ColorToString(vertex_color);
    }

    void Vertex::setColor(PlayerColor color) {
        vertex_color = color;
    }

    bool Vertex::isEmpty() const{
        return is_empty;
    }

    void Vertex::build() {
        is_empty = false;
    }

    std::string Vertex::ColorToString(PlayerColor color) const{
    switch (color) {
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


