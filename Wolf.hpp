#pragma once
#include "Animal.hpp"
#define WOLF_STRENGTH 9
#define WOLF_INITIATIVE 5

class Wolf :
	public Animal
{
public:
	virtual Organism& clone() override;
	using Animal::Animal;
	Wolf(COORD coordinates, World& world) : Animal(WOLF_STRENGTH, WOLF_INITIATIVE, DEFAULT_AGE, coordinates, world, Species::WOLF) {};
};

