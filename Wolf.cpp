#include "Wolf.hpp"

Organism& Wolf::clone()
{
	return *new Wolf(9, 5, 0, Coordinates(0, 0), m_world, m_species);
}
