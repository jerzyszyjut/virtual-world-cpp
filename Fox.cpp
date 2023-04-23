#include "Fox.hpp"

Organism& Fox::clone()
{
	Organism* newOrganism = new Fox(*this);
	newOrganism->setAge(0);
	return *newOrganism;
}

std::string Fox::action()
{
	COORD closestFreeSpace = findClosestFreeSpace(1);
	if (closestFreeSpace.X == this->m_coordinates.X && closestFreeSpace.Y == this->m_coordinates.Y)
	{
		return "2";
	}
	while (1) {
		int direction = rand() % 4;
		COORD newPosition{m_coordinates.X, m_coordinates.Y};
		switch (direction)
		{
		case 0:
			newPosition.X--;
			break;
		case 1:
			newPosition.X++;
			break;
		case 2:
			newPosition.Y--;
			break;
		case 3:
			newPosition.Y++;
			break;
		}

		if (m_world.isInWorld(newPosition))
		{
			if (!m_world.isEmpty(newPosition))
			{
				Organism& otherOrganism = m_world.getOrganism(newPosition);
				if (OrganismComparator()(this, &otherOrganism))
				{
					if (collision(newPosition))
					{
						move(newPosition);
					}
					break;
				}
			}
		}
	}
	return "3";
}
