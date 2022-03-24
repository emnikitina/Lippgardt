#pragma once

#include <iostream>

class Coordinate
{
    private:
        float _x;
        float _y;
        float _z;

        bool checkFormat(std::string str);
    
    public:
        Coordinate();
        Coordinate(float const& x, float const& y, float const& z);
        Coordinate(Coordinate const& copy);
        Coordinate& operator=(Coordinate const& source);
        ~Coordinate();
        
        float getX() const;
        float getY() const;
        float getZ() const;

        void set(float const& x, float const& y, float const& z);
        bool change(std::string str);
};

std::ostream& operator<<(std::ostream &out, Coordinate const& coordinate);