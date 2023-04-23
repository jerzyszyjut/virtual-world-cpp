#include "Animal.hpp"
#include <cstdlib>
#include <typeinfo>

void Animal::action()
{
	int direction = rand() % 4;
	Coordinates newPosition = *m_coordinates;
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
		if (collision(newPosition)) // Returns true if the animal should move
		{
			move(newPosition);
		}
	}
}

bool Animal::collision(Coordinates& newCoordinates)
{
	if (!m_world.isEmpty(newCoordinates))
	{
		Organism& other = m_world.getOrganism(newCoordinates);
		if (other.getSpecies() == m_species)
		{
			reproduce(other);
			return false;
		}
		else
		{
			return attack(other);
		}
	}
	return true;
}

void Animal::reproduce(Organism& other)
{
	Coordinates closestFreeSpace = findClosestFreeSpace();
	if (closestFreeSpace.x != -1) {
		Organism& newOrganism = clone();
		newOrganism.setCoordinates(closestFreeSpace);
		m_world.addOrganism(closestFreeSpace, newOrganism);
	}
}

bool Animal::move(Coordinates& newPosition)
{
	if (m_world.isEmpty(newPosition))
	{
		m_world.moveOrganism(*this, newPosition);
		return true;
	}
	return false;
}

bool Animal::attack(Organism& other)
{
	if (m_strength > other.getStrength())
	{
		m_world.removeOrganism(other);
		return true;
	}
	else
	{
		m_world.removeOrganism(*this);
		return false;
	}
}
