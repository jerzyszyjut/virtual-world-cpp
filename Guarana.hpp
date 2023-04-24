#pragma once
#include "Plant.hpp"
#define GUARANA_STRENGTH 0
#define GUARANA_STRENGTH_BOOST 3

class Guarana :
    public Plant
{
    public:
	using Plant::Plant;
	Guarana(COORD coordinates, World& world) : Plant(GUARANA_STRENGTH, coordinates, world, Species::GUARANA) {};
	virtual Organism& clone() override;
	virtual FightResult attack(Organism& other, bool isAttacked) override;
};

