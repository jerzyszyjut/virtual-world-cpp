#pragma once
#include "Plant.hpp"

class Guarana :
    public Plant
{
    public:
	using Plant::Plant;
	Guarana(COORD coordinates, World& world) : Plant(0, coordinates, world, Species::GUARANA) {};
	virtual Organism& clone() override;
	virtual FightResult attack(Organism& other, bool isAttacked) override;
};

