#include "Organism.hpp"

Organism::Organism(int strength, int initiative, int age, COORD coordinates, World& world, Species species) : m_coordinates(coordinates), m_world(world)
{
	m_strength = strength;
	m_initiative = initiative;
	m_age = age;
	m_species = species;
	m_isAlive = true;
}

Organism::Organism(Organism& other) : m_coordinates(other.m_coordinates), m_world(other.m_world)
{
	m_strength = other.m_strength;
	m_initiative = other.m_initiative;
	m_age = other.m_age;
	m_species = other.m_species;
	m_isAlive = true;
}

Organism::Organism(Organism&& other) : m_coordinates(other.m_coordinates), m_world(other.m_world)
{
	m_strength = other.m_strength;
	m_initiative = other.m_initiative;
	m_age = other.m_age;
	m_species = other.m_species;
	m_isAlive = true;
}

Organism::Organism(Organism* other) : m_coordinates(other->m_coordinates), m_world(other->m_world)
{
	m_strength = other->m_strength;
	m_initiative = other->m_initiative;
	m_age = other->m_age;
	m_species = other->m_species;
	m_isAlive = true;
}

Organism::~Organism()
{
}

void Organism::draw()
{
	m_world.m_renderer->addMapElement(m_coordinates.X, m_coordinates.Y, m_species);
}

FightResult Organism::attack(Organism& other, bool isAttacked = false)
{
	if (!isAttacked)
	{
		if (other.attack(*this, true) == DRAW && m_strength > other.getStrength())
		{
			return DRAW;
		}
	}
	if (m_strength > other.getStrength()) {
		return VICTORY;
	}
	if (m_strength < other.getStrength())
	{
		return DEFEAT;
	}
}

int Organism::getStrength()
{
	return m_strength;
}

void Organism::setStrength(int strength)
{
	m_strength = strength;
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

void Organism::die()
{
	m_isAlive = false;
}

bool Organism::isAlive()
{
	return m_isAlive;
}

Species Organism::getSpecies()
{
	return m_species;
}

COORD Organism::getCoordinates()
{
	return m_coordinates;
}

COORD Organism::findClosestFreeSpace(int distance) 
{
	return findClosestFreeSpace(distance, m_coordinates);
}

COORD Organism::findClosestFreeSpace(int distance, COORD coordinates)
{
	COORD closestFreeSpace{ coordinates.X, coordinates.Y };
	bool found = false;
	if (distance == 1)
	{
		for (int i = coordinates.X - distance; i <= coordinates.X + distance; i++)
		{
			COORD checkedCoordinates{ i, coordinates.Y };
			if (m_world.isInWorld(checkedCoordinates))
			{
				if (m_world.isEmpty(checkedCoordinates))
				{
					return checkedCoordinates;
				}
			}
		}
		for (int j = coordinates.Y - distance; j <= coordinates.Y + distance; j++)
		{
			COORD checkedCoordinates{ coordinates.X, j};
			if (m_world.isInWorld(checkedCoordinates))
			{
				if (m_world.isEmpty(checkedCoordinates))
				{
					return checkedCoordinates;
				}
			}
		}
	}
	else
	{
		for (int i = coordinates.X - distance; i <= coordinates.X + distance; i++)
		{
			for (int j = coordinates.Y - distance; j <= coordinates.Y + distance; j++)
			{
				COORD checkedCoordinates{ i, j };
				if (m_world.isInWorld(checkedCoordinates))
				{
					if (m_world.isEmpty(checkedCoordinates))
					{
						return checkedCoordinates;
					}
				}
			}
		}
	}
	return coordinates;
}

void Organism::setCoordinates(COORD newCoordinates)
{
	m_coordinates.X = newCoordinates.X;
	m_coordinates.Y = newCoordinates.Y;
}

bool Organism::OrganismComparator::operator()(Organism* first, Organism* second) const
{
	if (first->getStrength() == second->getStrength())
	{
		return first->getAge() > second->getAge();
	}
	return first->getStrength() > second->getStrength();
}

bool Organism::InitiativeOrganismComparator::operator()(Organism* first, Organism* second) const
{
	if (first->getInitiative() == second->getInitiative())
	{
		return first->getAge() > second->getAge();
	}
	return first->getInitiative() > second->getInitiative();
}
