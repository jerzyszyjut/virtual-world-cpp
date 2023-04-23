#include "Animal.hpp"
#include <cstdlib>
#include <typeinfo>

void Animal::action()
{
	int direction = rand() % 4;
	COORD newPosition = m_coordinates;
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
		if (collision(newPosition)) // Returns true if the animal should move
		{
			move(newPosition);
		}
	}
}

bool Animal::collision(COORD newCoordinates)
{
	if (!m_world.isEmpty(newCoordinates))
	{
		Organism& other = m_world.getOrganism(newCoordinates);
		if (&other == this)
		{
			return false;
		}

		if (other.getSpecies() == m_species)
		{
			reproduce(other);
			return false;
		}
		else
		{
			switch (attack(other, false))
			{
			case VICTORY:
			{
				std::string message = "";
				message += m_species;
				message += " killed ";
				message += other.getSpecies();
				message += " at (";
				message += std::to_string(other.getCoordinates().X);
				message += ", ";
				message += std::to_string(other.getCoordinates().Y);
				message += ")";
				m_world.m_renderer->addLog(message);
				other.die();
				return true;
			}
			case DEFEAT: {
				std::string message = "";
				message += m_species;
				message += " was killed by ";
				message += other.getSpecies();
				message += " at (";
				message += std::to_string(other.getCoordinates().X);
				message += ", ";
				message += std::to_string(other.getCoordinates().Y);
				message += ")";
				m_world.m_renderer->addLog(message);
				die();
				return false;

			}
			case DRAW:
				return true;
			default:
				break;
			}
		}
	}
	return true;
}

void Animal::reproduce(Organism& other)
{
	COORD closestFreeSpace = findClosestFreeSpace(1);
	if (closestFreeSpace.X != m_coordinates.X || closestFreeSpace.Y != m_coordinates.Y) {
		Organism& newOrganism = clone();
		newOrganism.setCoordinates(closestFreeSpace);
		m_world.addOrganism(newOrganism, closestFreeSpace);

		std::string message = "";
		message += m_species;
		message += " reproduced at (";
		message += std::to_string(closestFreeSpace.X);
		message += ", ";
		message += std::to_string(closestFreeSpace.Y);
		message += ")";
		m_world.m_renderer->addLog(message);
	}
}

bool Animal::move(COORD newPosition)
{
	if (m_world.isEmpty(newPosition))
	{
		m_world.moveOrganism(*this, newPosition);
		return true;
	}
	return false;
}
