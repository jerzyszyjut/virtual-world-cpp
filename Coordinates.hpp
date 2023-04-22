#pragma once
#include "World.hpp"

class Coordinates
{
public:
	Coordinates();
	Coordinates(int x, int y);
	Coordinates(Coordinates& other);
	Coordinates(Coordinates&& other);
	bool operator==(Coordinates& other);
	bool operator!=(Coordinates& other);
	Coordinates& operator=(Coordinates& other);
	Coordinates& operator=(const Coordinates& other);
	int x, y;
};

