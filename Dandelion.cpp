#include "Dandelion.hpp"

Organism& Dandelion::clone()
{
	Organism* newDandelion = new Dandelion(*this);
	newDandelion->setAge(0);
	return *newDandelion;
}

void Dandelion::action()
{
	for (int i = 0; i < 3; i++)
	{
		Plant::action();
	}
}
