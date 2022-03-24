#pragma once

#include "Point.hpp"

#include <string>
#include <vector>

template <class T>
class Manipulator
{
    private:
        std::string _name;
        Point<T> _location;
        T _R;
        std::vector<Point<T> > _goals;

    public:

        Manipulator(): _name(""), _location(Point<T>()), _R(0), _goals(std::vector<Point<T> > ()) {};

        Manipulator(std::string const& name, Point<T> const& location, T const& radius) :
            _name(name), _location(location), _R(radius), _goals(std::vector<Point<T> > ()) {};

        Manipulator(Manipulator<T> const& copy) :
            _name(copy._name), _location(copy._location), _R(copy._R), _goals(std::vector<Point<T> > (copy._goals)) {};

        Manipulator& operator=(Manipulator const& source)
        {
            if (this != &source)
            {
                this->_name = source._name;
                this->_location = source._location;
                this->_R = source._R;
                this->_goals = source._goals;
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

        void insert(Point<T> const& p)
        {
            this->_goals.push_back(p);
        };

        void chooseManupulator(Manipulator& right, Point<T> target)
        {
            T d1 = _location.distance(target);
            T d2 = right._location.distance(target);

            if (d1 > d2)
            {
                right.insert(target);
                right.setLocation(target);
            }
            else
            {
                insert(target);
                setLocation(target);
            }
        };

        friend std::ostream& operator<<(std::ostream &out, Manipulator& M)
        {
            out << "Manipulator " << M.getName() << "\nlocation: {" << M.getLocation().getX() << ";" << M.getLocation().getY() << "}, action radius: " << M.getRadius();
            out << "\nPoints [";
            for (typename std::vector<Point<T> >::iterator it = M._goals.begin(); it != M._goals.end(); it++)
                out << " {" << it->getX() << ";" << it->getY() << "}";
            out << " ]\n";
            return out;
        };

        friend std::istream& operator>>(std::istream &in, Manipulator& M)
        {
            in >> M._location >> M._R;
            in >> M._name;
            return in;
        };
};
