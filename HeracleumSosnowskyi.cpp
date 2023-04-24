#include "HeracleumSosnowskyi.hpp"
#include "Animal.hpp"

void HeracleumSosnowskyi::action(Direction direction)
{
	for (int i = -1; i <= 1; i++)
	{
		if (i == 0)
		{
			continue;
		}
		COORD checkedPosition{ m_coordinates.X + i, m_coordinates.Y };
		if (m_world.isInWorld(checkedPosition))
		{
			if (!m_world.isEmpty(checkedPosition))
			{
				Organism& organism = m_world.getOrganism(checkedPosition);
				Animal* animal = dynamic_cast<Animal*>(&organism);
				if (animal != nullptr && animal->getSpecies() != CYBERSHEEP) {
					animal->die();
				}
			}
		}
	}
	for (int i = -1; i <= 1; i++)
	{
		if (i == 0)
		{
			continue;
		}
		COORD checkedPosition{ m_coordinates.X, m_coordinates.Y + i };
		if (m_world.isInWorld(checkedPosition))
		{
			if (!m_world.isEmpty(checkedPosition))
			{
				Organism& organism = m_world.getOrganism(checkedPosition);
				Animal* animal = dynamic_cast<Animal*>(&organism);
				if (animal != nullptr && animal->getSpecies() != CYBERSHEEP) {
					animal->die();
				}
			}
		}
	}
	Plant::action(direction);
}

Organism& HeracleumSosnowskyi::clone()
{
	Organism* newOrganism = new HeracleumSosnowskyi(m_coordinates, m_world);
	return *newOrganism;
}

FightResult HeracleumSosnowskyi::attack(Organism& other, bool isAttacked)
{
	if (isAttacked)
	{
		if (other.getSpecies() == CYBERSHEEP) {
			return DEFEAT;
		}
		else {
			other.setStrength(0);
			return VICTORY;
		}
	}
}
