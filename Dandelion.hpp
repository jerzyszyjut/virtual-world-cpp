#pragma once
#include "Plant.hpp"
#define DANDELION_STRENGTH 0
#define DANDELION_SEED_TRIES 3

class Dandelion :
    public Plant
{
    public:
	using Plant::Plant;
	Dandelion(COORD coordinates, World& world) : Plant(DANDELION_STRENGTH, coordinates, world, Species::DANDELION) {};
	virtual Organism& clone() override;
	virtual void action(Direction direction) override;
};

