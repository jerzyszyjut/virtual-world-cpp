#include "Belladonna.hpp"

Organism& Belladonna::clone()
{
	Organism* newOrganism = new Belladonna(*this);
	newOrganism->setAge(0);
	return *newOrganism;
}

FightResult Belladonna::attack(Organism& other, bool isAttacked)
{
	other.setStrength(0);
	return FightResult::DEFEAT;
}
