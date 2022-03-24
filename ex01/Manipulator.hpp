#pragma once

#include "Point.hpp"

#include <iostream>
#include <string>

template <class T>
class Manipulator
{
    private:
        std::string _name;
        Point<T> _location;
        T _R;

    public:

        Manipulator(): _name(""), _location(Point<T>()), _R(0) {};

        Manipulator(std::string const& name, Point<T> const& location, T const& radius) :
            _name(name), _location(location), _R(radius) {};

        Manipulator(Manipulator<T> const& copy) :
            _name(copy._name), _location(copy._location), _R(copy._R) {};

        Manipulator& operator=(Manipulator const& source)
        {
            if (this != &source)
            {
                this->_name = source.getName();
                this->_location = source.getLocation();
                this->_R = source.getRadius();
            }    
            return *this;
        };

        ~Manipulator() {};

        void setName(std::string name)
        {
            this->_name = name;
        };

        void setLocation(Point<T> const& location)
        {
            this->_location = location;
        };

        void setRadius(T const& R)
        {
            this->_R = R;
        };

        std::string getName() const
        {
            return this->_name;
        };

        Point<T> getLocation() const
        {
            return this->_location;
        };

        T getRadius() const
        {
            return this->_R;
        };

        Manipulator& chooseManupulator(Manipulator& right, Point<T> target)
        {
            T d1 = _location.distance(target);
            T d2 = right._location.distance(target);

            if (d1 <= _R)
                return *this;
            if (d2 <= right._R)
                return right;
            if (d1 - _R > d2 - right._R)
                return right;
            return *this;
        };

        friend std::ostream& operator<<(std::ostream &out, Manipulator const& M)
        {
            out << "Manipulator " << M.getName() << "\nlocation: {" << M.getLocation().getX() << ";" << M.getLocation().getY() << "}, action radius: " << M.getRadius();
            return out;
        };

        friend std::istream& operator>>(std::istream &in, Manipulator& M)
        {
            in >> M._location >> M._R;
            in.ignore(1);
            in >> M._name;
            return in;
        };
};
