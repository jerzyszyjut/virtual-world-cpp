#include "Organism.hpp"

Organism::Organism(int strength, int initiative, int age, Coordinates coordinates, World &world, Species species) : m_coordinates(&coordinates), m_world(world)
{
	m_strength = strength;
	m_initiative = initiative;
	m_age = age;
	m_species = species;
}

Organism::Organism(Organism &other) : m_coordinates(other.m_coordinates), m_world(other.m_world)
{
	m_strength = other.m_strength;
	m_initiative = other.m_initiative;
	m_age = other.m_age;
	m_species = other.m_species;
}

Organism::~Organism()
{
	delete m_coordinates;
}

void Organism::draw()
{
}

int Organism::getStrength()
{
	return m_strength;
}

int Organism::getInitiative()
{
	return m_initiative;
}

int Organism::getAge()
{
	return m_age;
}

void Organism::setAge(int age)
{
	m_age = age;
}

Species Organism::getSpecies()
{
	return m_species;
}

Coordinates &Organism::getCoordinates()
{
	return *m_coordinates;
}

Coordinates &Organism::findClosestFreeSpace()
{
	Coordinates &closestFreeSpace = *m_coordinates;
	int distance = 0;
	bool found = false;
	while (!found)
	{
		distance++;
		for (int i = m_coordinates->x - distance; i <= m_coordinates->x + distance; i++)
		{
			for (int j = m_coordinates->y - distance; j <= m_coordinates->y + distance; j++)
			{
				Coordinates coordinates(i, j);
				if (m_world.isInWorld(coordinates))
				{
					if (m_world.isEmpty(coordinates))
					{
						closestFreeSpace = coordinates;
						found = true;
						break;
					}
				}
			}
			if (found)
			{
				break;
			}
		}
	}
	return closestFreeSpace;
}

Coordinates &Organism::findClosestFreeSpace(int distance)
{
	Coordinates &closestFreeSpace = *m_coordinates;
	bool found = false;
	for (int i = m_coordinates->x - distance; i <= m_coordinates->x + distance; i++)
	{
		for (int j = m_coordinates->y - distance; j <= m_coordinates->y + distance; j++)
		{
			Coordinates coordinates(i, j);
			if (m_world.isInWorld(coordinates))
			{
				if (m_world.isEmpty(coordinates))
				{
					closestFreeSpace = coordinates;
					found = true;
					break;
				}
			}
		}
		if (found)
		{
			break;
		}
	}
	return closestFreeSpace;
}

void Organism::setCoordinates(Coordinates &newCoordinates)
{
	m_coordinates->x = newCoordinates.x;
	m_coordinates->y = newCoordinates.y;
}

bool Organism::OrganismComparator::operator()(Organism *first, Organism *second) const
{
	if (first->getStrength() == second->getStrength())
	{
		return first->getAge() > second->getAge();
	}
	return first->getStrength() < second->getStrength();
}
