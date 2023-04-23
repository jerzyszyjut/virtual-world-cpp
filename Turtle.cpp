#include "Turtle.hpp"

Organism& Turtle::clone()
{
	Organism* newOrganism = new Turtle(*this);
	newOrganism->setAge(0);
	return *newOrganism;
}

void Turtle::action()
{
	bool shouldItMove = ((rand() % 100) < 75);
	if (shouldItMove)
	{
		Animal::action();
	}
}

bool Turtle::collision(Coordinates& coordinates)
{
	return Animal::collision(coordinates);
}

bool Turtle::attack(Organism& other, bool isAttacked)
{
	if (isAttacked && other.getStrength() < 5)
	{
		return true;
	}
	return Animal::attack(other, isAttacked);
}
