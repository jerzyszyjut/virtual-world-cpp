#pragma once
#include "Plant.hpp"

class Dandelion :
    public Plant
{
    public:
	using Plant::Plant;
	Dandelion(COORD coordinates, World& world) : Plant(0, coordinates, world, Species::DANDELION) {};
	virtual Organism& clone() override;
	virtual void action(Direction direction) override;
};

