#include "Antilopinae.hpp"

Organism& Antilopinae::clone()
{
	Organism* clonedAnimal = new Antilopinae(m_coordinates, m_world);
	return *clonedAnimal;
}

void Antilopinae::action(Direction direction)
{
	COORD newPosition = m_coordinates;
	for (int i = 0; i < 2; i++)
	{
		int direction = rand() % 4;
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
	}

	if (m_world.isInWorld(newPosition))
	{
		if (collision(newPosition)) // Returns true if the animal should move
		{
			move(newPosition);
		}
	}
}

bool Antilopinae::collision(COORD newCoordinates)
{
	COORD nearestFreeSpace = findClosestFreeSpace(1, newCoordinates);
	if (nearestFreeSpace.X != newCoordinates.X && nearestFreeSpace.Y != newCoordinates.Y)
	{
		if (!m_world.isEmpty(newCoordinates))
		{
			int didEscape = (rand() % 100 <= 50);
			if (didEscape == 0)
			{
				std::string message = "";
				message += m_species;
				message += " avoided fight with ";
				message += m_world.getOrganism(newCoordinates).getSpecies();
				message += " at (";
				message += std::to_string(newCoordinates.X);
				message += ", ";
				message += std::to_string(newCoordinates.Y);
				message += ")";
				m_world.m_renderer->addLog(message);
				move(nearestFreeSpace);
				return false;
			}
			else
			{
				return Animal::collision(newCoordinates);
			}
		}
	}
	else
	{
		return Animal::collision(newCoordinates);
	}
}
