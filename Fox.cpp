#include "Fox.hpp"

Organism& Fox::clone()
{
	Organism* newOrganism = new Fox(m_coordinates, m_world);
	return *newOrganism;
}

void Fox::action(Direction direction)
{
	COORD closestFreeSpace = findClosestFreeSpace(1);
	if (closestFreeSpace.X == this->m_coordinates.X && closestFreeSpace.Y == this->m_coordinates.Y)
	{
		return;
	}
	while (1) {
		int direction = rand() % DIRECTION_COUNT;
		COORD newPosition{m_coordinates.X, m_coordinates.Y};
		switch (direction)
		{
		case LEFT:
			newPosition.X--;
			break;
		case RIGHT:
			newPosition.X++;
			break;
		case UP:
			newPosition.Y--;
			break;
		case DOWN:
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
