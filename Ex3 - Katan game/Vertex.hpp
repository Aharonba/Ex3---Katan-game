#ifndef VERTEX_HPP
#define VERTEX_HPP
#include "Player.hpp"

namespace ariel
{

    class Vertex
    {
    private:
        int number; // 0-53
        PlayerColor vertex_color;
        bool is_empty;

    public:
        Vertex(int num);
        int getNumber() const;
        std::string getColor() const;
        void setColor(PlayerColor color) ;
        bool isEmpty() const;
        void build();
        std::string ColorToString(PlayerColor color) const;
    };

}

#endif // VERTEX_HPP
