#include "Belladonna.hpp"

Organism& Belladonna::clone()
{
	Organism* newOrganism = new Belladonna(m_coordinates, m_world);
	return *newOrganism;
}

FightResult Belladonna::attack(Organism& other, bool isAttacked)
{
	other.setStrength(0);
	return FightResult::DEFEAT;
}
