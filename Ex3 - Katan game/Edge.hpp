/**ID:206751976
Email:"aharonba123@gmail.com"
*/

#ifndef EDGE_HPP
#define EDGE_HPP

#include <string>

namespace ariel
{
    class Vertex;
    enum class PlayerColor;
    class Road;

    class Edge
    {
    private:
        Vertex *vertex1; // First vertex connected by the edge
        Vertex *vertex2; // Second vertex connected by the edge
        PlayerColor edge_color;
        int number;
        Road *road;

    public:
        Edge(Vertex *v1, Vertex *v2, int num);
        Vertex *getVertex1() const;
        Vertex *getVertex2() const;
        int getNumber() const;
        std::string getColor() const;
        void setColor(int color);
        std::string ColorToString(PlayerColor color) const;
        bool hasRoad() const;
        void buildRoad(Road *newRoad);
        Road* getRoad() const;
    };

}

#endif // EDGE_HPP
