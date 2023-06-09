#include "Plant.hpp"

void Plant::action(Direction direction)
{
	bool willSeed = (rand() % 100) < PLANT_SEED_CHANCE_PERCENT;
	if (willSeed)
	{
		COORD newPlantPosition = findClosestFreeSpace(1);
		if (m_world.isEmpty(newPlantPosition))
		{
			Organism& newPlant = this->clone();
			newPlant.setCoordinates(newPlantPosition);
			m_world.addOrganism(newPlant, newPlantPosition);
		}
	}
}

bool Plant::collision(COORD newCoordinates)
{
	return false;
}

FightResult Plant::attack(Organism& other, bool isAttacked)
{
	return this->getStrength() > other.getStrength() ? VICTORY : DEFEAT;
}
