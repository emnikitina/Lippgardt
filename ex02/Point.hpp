#pragma once

#include <iostream>
#include <cmath>

template<class T>
class Point
{
	private:
		T _x;
		T _y;

	public:
		Point() : _x(0), _y(0) {};

		Point(T x, T y) : _x(x), _y(y) {};

		Point(Point const& copy): _x(copy._x), _y(copy._y) {};

		Point& operator =(Point const& source)
		{
			if (this != &source)
			{
				this->_x = source._x;
				this->_y = source._y;
			}
			return *this;
		};

		~Point() {};

		void setX(T const& x)
		{
			this->_x = x;
		};

		void setY(T const& y)
		{
			this->_y = y;
		};

		T getX() const
		{
			return this->_x;
		};

		T getY() const
		{
			return this->_y;
		};

		T distance(Point<T> const& P) const
		{
			T dx = P._x - this->_x;
			T dy = P._y - this->_y;
			return sqrt(dx * dx + dy * dy);
		};

		friend std::istream& operator >>(std::istream &in, Point& P)
		{
			in >> P._x >> P._y;
			return in;
		};

		friend std::ostream& operator<<(std::ostream &out, Point P)
		{
			out << "{" << P._x << ";" << P._y << "}";
			return out;
		};
};