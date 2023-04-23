#include "Grass.hpp"

Organism& Grass::clone()
{
	Organism* newGrass = new Grass(*this);
	newGrass->setAge(0);
	return *newGrass;
}
