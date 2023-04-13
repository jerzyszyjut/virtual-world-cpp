#include <stdexcept>
#include "Coordinates.hpp"

Coordinates::Coordinates(int x, int y): m_x(x), m_y(y)
{
}

Coordinates::~Coordinates()
{
}

int Coordinates::getX()
{
	return m_x;
}

int Coordinates::getY()
{
	return m_y;
}

void Coordinates::setX(int x)
{
	if (x >= 0 && x < m_world->getWidth())
		m_x = x;
	else
		throw std::out_of_range("X out of range");
}

void Coordinates::setY(int y)
{
	if (y >= 0 && y < m_world->getHeight())
		m_y = y;
	else
		throw std::out_of_range("Y out of range");
}
