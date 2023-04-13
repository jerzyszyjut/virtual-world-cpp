#include "World.hpp"

World::World(): m_turn(0), m_organisms(nullptr), m_organisms_size(0), m_world_width(0), m_world_height(0)
{
}

World::~World()
{
	delete[] m_organisms;
}

void World::nextTurn()
{
}

void World::print()
{
}

int World::getTurn()
{
	return m_turn;
}

int World::getOrganismsSize()
{
	return m_organisms_size;
}

Organism* World::getOrganisms()
{
	return m_organisms;
}

int World::getWidth()
{
	return m_world_width;
}

int World::getHeight()
{
	return m_world_height;
}
