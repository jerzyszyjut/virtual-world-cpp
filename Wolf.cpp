#include "Wolf.hpp"

Organism& Wolf::clone()
{
	Organism* clonedAnimal = new Wolf(*this);
	clonedAnimal->setAge(0);
	return *clonedAnimal;
}
