#pragma once
#include "World.hpp"
#include "Coordinates.hpp"

class Organism
{
public:
	virtual void action() = 0;
	virtual void collision(Organism* attacker) = 0;
	virtual void draw() = 0;

	virtual int getStrength() = 0;
	virtual int getInitiative() = 0;
	virtual Coordinates* getCoordinates() = 0;

private:
	int m_strength, m_initiative;
	Coordinates* m_coordinates;
	World* m_world;
	char m_symbol;
};

