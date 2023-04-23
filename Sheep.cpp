#include "Sheep.hpp"

Organism& Sheep::clone()
{
	Organism* clonedAnimal = new Sheep(*this);
	clonedAnimal->setAge(0);
	return *clonedAnimal;
}
