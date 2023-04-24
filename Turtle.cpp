#include "Turtle.hpp"

Organism& Turtle::clone()
{
	Organism* newOrganism = new Turtle(m_coordinates, m_world);
	return *newOrganism;
}

void Turtle::action(Direction direction)
{
	bool shouldItMove = ((rand() % 100) < 25);
	if (shouldItMove)
	{
		Animal::action(direction);
	}
}

bool Turtle::collision(COORD coordinates)
{
	return Animal::collision(coordinates);
}

FightResult Turtle::attack(Organism& other, bool isAttacked)
{
	if (isAttacked && other.getStrength() < 5)
	{
		std::string message = this->getSpecies() + " defended itself from " + other.getSpecies();
		return DRAW;
	}
	return Organism::attack(other, isAttacked);
}
