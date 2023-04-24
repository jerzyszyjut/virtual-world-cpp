#include "Dandelion.hpp"

Organism& Dandelion::clone()
{
	Organism* newDandelion = new Dandelion(m_coordinates, m_world);
	return *newDandelion;
}

void Dandelion::action(Direction direction)
{
	for (int i = 0; i < 3; i++)
	{
		Plant::action(direction);
	}
}
