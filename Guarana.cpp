#include "Guarana.hpp"

Organism& Guarana::clone()
{
	Organism* newGuarana = new Guarana(m_coordinates, m_world);
	return *newGuarana;
}

FightResult Guarana::attack(Organism& other, bool isAttacked)
{
	FightResult result = other.attack(*this, true);
	if (result == VICTORY)
	{
		other.setStrength(other.getStrength() + GUARANA_STRENGTH_BOOST);
	}
	return result;
}
