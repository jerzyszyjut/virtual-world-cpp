#include <stdexcept>
#include "Coordinates.hpp"

Coordinates::Coordinates(): x(0), y(0)
{
}

Coordinates::Coordinates(int x, int y) : x(x), y(y)
{
}

Coordinates::Coordinates(Coordinates& other)
{
	x = other.x;
	y = other.y;
}

Coordinates::Coordinates(Coordinates&& other)
{
	x = other.x;
	y = other.y;
}

bool Coordinates::operator==(Coordinates& other)
{
	if (x == other.x && y == other.y)
	{
		return true;
	}
	return false;
}

bool Coordinates::operator!=(Coordinates& other)
{
	return !(*this == other);
}

Coordinates& Coordinates::operator=(Coordinates& other)
{
	x = other.x;
	y = other.y;
	return *this;
}

Coordinates& Coordinates::operator=(const Coordinates& other)
{
	x = other.x;
	y = other.y;
	return *this;
}
