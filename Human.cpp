#include "Human.hpp"

Organism& Human::clone()
{
	Human* newHuman = new Human(m_coordinates, m_world);
	return *newHuman;
}
