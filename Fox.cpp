#include "Fox.hpp"

Organism& Fox::clone()
{
	Organism* newOrganism = new Fox(*this);
	newOrganism->setAge(0);
	return *newOrganism;
}

void Fox::action()
{
	COORD closestFreeSpace = findClosestFreeSpace(1);
	if (closestFreeSpace.X == this->m_coordinates.X && closestFreeSpace.Y == this->m_coordinates.Y)
	{
		return;
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
				else
				{
					std::string message = "Fox dodged entering field  at (";
					message += std::to_string(newPosition.X);
					message += ", ";
					message += std::to_string(newPosition.Y);
					message += ") with ";
					message += otherOrganism.getSpecies();
					m_world.m_renderer->addLog(message);
				}
			}
			else
			{
				move(newPosition);
				break;
			}
		}
	}
}
