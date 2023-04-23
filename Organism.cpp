#include "Organism.hpp"

Organism::Organism(int strength, int initiative, int age, COORD coordinates, World &world, Species species) : m_coordinates(coordinates), m_world(world)
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

Organism::Organism(Organism&& other): m_coordinates(other.m_coordinates), m_world(other.m_world)
{
	m_strength = other.m_strength;
	m_initiative = other.m_initiative;
	m_age = other.m_age;
	m_species = other.m_species;
}

Organism::Organism(Organism* other) : m_coordinates(other->m_coordinates), m_world(other->m_world)
{
	m_strength = other->m_strength;
	m_initiative = other->m_initiative;
	m_age = other->m_age;
	m_species = other->m_species;
}

Organism::~Organism()
{
}

void Organism::draw()
{
	m_world.m_renderer->addMapElement(m_coordinates.X, m_coordinates.Y, m_species);
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

COORD Organism::getCoordinates()
{
	return m_coordinates;
}

COORD Organism::findClosestFreeSpace()
{
	COORD closestFreeSpace = m_coordinates;
	int distance = 0;
	bool found = false;
	while (!found)
	{
		distance++;
		for (int i = m_coordinates.X - distance; i <= m_coordinates.X + distance; i++)
		{
			for (int j = m_coordinates.Y - distance; j <= m_coordinates.Y + distance; j++)
			{
				COORD coordinates{ i, j };
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

COORD Organism::findClosestFreeSpace(int distance)
{
	COORD closestFreeSpace = m_coordinates;
	bool found = false;
	for (int i = m_coordinates.X - distance; i <= m_coordinates.X + distance; i++)
	{
		for (int j = m_coordinates.Y - distance; j <= m_coordinates.Y + distance; j++)
		{
			COORD coordinates{ i, j };
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

void Organism::setCoordinates(COORD newCoordinates)
{
	m_coordinates.X = newCoordinates.X;
	m_coordinates.Y = newCoordinates.Y;
}

bool Organism::OrganismComparator::operator()(Organism *first, Organism *second) const
{
	if (first->getStrength() == second->getStrength())
	{
		return first->getAge() > second->getAge();
	}
	return first->getStrength() < second->getStrength();
}
