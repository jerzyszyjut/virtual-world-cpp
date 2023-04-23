#include "Turtle.hpp"

Organism& Turtle::clone()
{
	Organism* newOrganism = new Turtle(*this);
	newOrganism->setAge(0);
	return *newOrganism;
}

void Turtle::action()
{
	bool shouldItMove = ((rand() % 100) < 25);
	if (shouldItMove)
	{
		Animal::action();
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
		return DRAW;
	}
	return Animal::attack(other, isAttacked);
}
