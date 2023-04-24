#pragma once
#include "Organism.hpp"
#include "World.hpp"
#define PLANT_INITIATIVE 0
#define PLANT_SEED_CHANCE_PERCENT 10

class Plant :
	public Organism
{
public:
	using Organism::Organism;
	Plant(int strength, COORD coordinates, World& world, Species species) : Organism(strength, PLANT_INITIATIVE, DEFAULT_AGE, coordinates, world, species) {};

	virtual void action(Direction direction) override;
	virtual bool collision(COORD newCoordinates) override;
	virtual FightResult attack(Organism& other, bool isAttacked) override;
};

