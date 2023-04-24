#include "Wolf.hpp"

Organism& Wolf::clone()
{
	Organism* clonedAnimal = new Wolf(m_coordinates, m_world);
	return *clonedAnimal;
}
