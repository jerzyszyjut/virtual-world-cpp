#include "Grass.hpp"

Organism& Grass::clone()
{
	Organism* newGrass = new Grass(m_coordinates, m_world);
	return *newGrass;
}
