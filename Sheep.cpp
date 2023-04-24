#include "Sheep.hpp"

Organism& Sheep::clone()
{
	Organism* clonedAnimal = new Sheep(m_coordinates, m_world);
	return *clonedAnimal;
}
