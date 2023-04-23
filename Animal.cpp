#include "Animal.hpp"
#include <cstdlib>
#include <typeinfo>

std::string Animal::action()
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
	return "Piwo";
}

bool Animal::collision(COORD newCoordinates)
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
			if (attack(other, false))
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
	}
	return true;
}

void Animal::reproduce(Organism& other)
{
	COORD closestFreeSpace = findClosestFreeSpace();
	if (closestFreeSpace.X != -1) {
		Organism& newOrganism = clone();
		newOrganism.setCoordinates(closestFreeSpace);
		m_world.addOrganism(newOrganism, closestFreeSpace);
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

bool Animal::attack(Organism& other, bool isAttacked=false)
{
	Animal* animal = dynamic_cast<Animal*>(&other);
	if (animal)
	{
		if (isAttacked)
		{
			return m_strength > other.getStrength();
		}
		else
		{
			return m_strength > other.getStrength() && !(animal->attack(*this, true));
		}
	}
	else {
		return m_strength > other.getStrength();
	}
}
