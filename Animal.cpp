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
				m_world.removeOrganism(other);
				return true;
			case DEFEAT:
				m_world.removeOrganism(*this);
				return false;
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
	if (closestFreeSpace.X != m_coordinates.X && closestFreeSpace.Y != m_coordinates.Y) {
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

FightResult Animal::attack(Organism& other, bool isAttacked = false)
{
	Animal* animal = dynamic_cast<Animal*>(&other);
	if (animal)
	{
		if (isAttacked)
		{
			if (m_strength > other.getStrength()) {
				return VICTORY;
			}
			else if (m_strength < other.getStrength())
			{
				return DEFEAT;
			}
		}
		else
		{
			if (m_strength > other.getStrength() && animal->attack(*this, true) == DRAW)
			{
				return DRAW;
			}
		}
	}
	if (m_strength > other.getStrength()) {
		return VICTORY;
	}
	else if (m_strength < other.getStrength())
	{
		return DEFEAT;
	}
}
