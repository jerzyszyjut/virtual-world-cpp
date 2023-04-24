#pragma once
#include "Organism.hpp"
#include "World.hpp"

class Plant :
	public Organism
{
public:
	using Organism::Organism;
	Plant(int strength, COORD coordinates, World& world, Species species) : Organism(strength, 0, 0, coordinates, world, species) {};

	virtual void action(Direction direction) override;
	virtual bool collision(COORD newCoordinates) override;
	virtual FightResult attack(Organism& other, bool isAttacked) override;
};

