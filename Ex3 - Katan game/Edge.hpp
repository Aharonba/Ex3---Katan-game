#ifndef EDGE_HPP
#define EDGE_HPP

#include <string>


namespace ariel
{
    class Vertex;
    enum class PlayerColor;

    class Edge
    {
    private:
        Vertex *vertex1; // First vertex connected by the edge
        Vertex *vertex2; // Second vertex connected by the edge
        bool is_empty;   
        PlayerColor edge_color;
        int number;

    public:
        Edge(Vertex *v1, Vertex *v2, int num); 
        Vertex *getVertex1() const;  
        Vertex *getVertex2() const;   
        bool isEmpty() const;  
        int getNumber() const;       
        void build();                 // Method to mark edge as built
        std::string getColor() const;
        void setColor(int color);
        std::string ColorToString(PlayerColor color) const;
    };

}

#endif // EDGE_HPP
