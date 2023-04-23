#include "Fox.hpp"

Organism& Fox::clone()
{
	Organism* newOrganism = new Fox(*this);
	newOrganism->setAge(0);
	return *newOrganism;
}

void Fox::action()
{
	if (this->findClosestFreeSpace(1) == *(this->m_coordinates))
	{
		return;
	}
	while (1) {
		int direction = rand() % 4;
		Coordinates newPosition(m_coordinates->x, m_coordinates->y);
		switch (direction)
		{
		case 0:
			newPosition.x--;
			break;
		case 1:
			newPosition.x++;
			break;
		case 2:
			newPosition.y--;
			break;
		case 3:
			newPosition.y++;
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
}
