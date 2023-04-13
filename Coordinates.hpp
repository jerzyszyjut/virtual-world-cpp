#pragma once
#include "World.hpp"

class Coordinates
{
public:
	Coordinates(int x, int y);
	~Coordinates();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
private:
	int m_x, m_y;
	World* m_world;
};

