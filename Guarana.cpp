#include "Guarana.hpp"

Organism& Guarana::clone()
{
    Organism* newGuarana = new Guarana(*this);
	newGuarana->setAge(0);
	return *newGuarana;
}

FightResult Guarana::attack(Organism& other, bool isAttacked)
{
	FightResult result = other.attack(*this, true);
	if (result == VICTORY)
	{
		other.setStrength(other.getStrength() + 3);
	}
	return result;
}
