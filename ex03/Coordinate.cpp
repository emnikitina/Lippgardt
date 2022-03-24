#include "Coordinate.hpp"

Coordinate::Coordinate(): _x(0), _y(0), _z(0) {};

Coordinate::Coordinate(float const& x, float const& y, float const& z): _x(x), _y(y), _z(z) {};

Coordinate::Coordinate(Coordinate const& copy): _x(copy._x), _y(copy._y), _z(copy._z) {};

Coordinate& Coordinate::operator=(Coordinate const& source)
{
    if (this == &source)
        return *this;
    this->_x = source.getX();
    this->_y = source.getY();
    this->_z = source.getZ();
    return *this;
};

Coordinate::~Coordinate() {};

float Coordinate::getX() const
{
    return this->_x;
};

float Coordinate::getY() const
{
    return this->_y;
};

float Coordinate::getZ() const
{
    return this->_z;
};

bool Coordinate::checkFormat(std::string str)
{
    size_t i = 1;
    if (!(str[0] == 'X' || str[0] == 'Y' || str[0] == 'Z'))
        return false;
    if (str[1] == '-')
        i++;
    for (size_t i = (str[1] == '-') ? 2 : 1; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

bool Coordinate::change(std::string str)
{
    std::string xLine, yLine, zLine;
    size_t pos;
    if ((pos = str.find_first_of(";")) == std::string::npos)
        return false;
    xLine = str.substr(0, pos);
    str = str.substr(pos + 1);
    if ((pos = str.find_first_of(";")) == std::string::npos)
        return false;
    yLine = str.substr(0, pos);
    str = str.substr(pos + 1);
    if ((pos = str.find_first_of(";")) == std::string::npos)
        return false;
    zLine = str.substr(0, pos);
    if (str.substr(pos + 1) != "")
        return false;
    if (!(checkFormat(xLine) && checkFormat(yLine) && checkFormat(zLine)))
        return false;
    xLine = xLine.substr(1);
    yLine = yLine.substr(1);
    zLine = zLine.substr(1);
    this->_x += std::atoi(xLine.c_str());
    this->_y += std::atoi(yLine.c_str());
    this->_z += std::atoi(zLine.c_str());    
    return true;
};

void Coordinate::set(float const& x, float const& y, float const& z)
{
    this->_x = x;
    this->_y = y;
    this->_z = z;
};

std::ostream& operator<<(std::ostream &out, Coordinate const& coordinate)
{
    out << coordinate.getX() << " " << coordinate.getY() << " " << coordinate.getZ();
    return out;
};