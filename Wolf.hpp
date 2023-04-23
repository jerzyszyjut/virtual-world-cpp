#pragma once
#include "Animal.hpp"

class Wolf :
	public Animal
{
public:
	virtual Organism& clone() override;
	using Animal::Animal;
	Wolf(COORD coordinates, World& world) : Animal(9, 5, 0, coordinates, world, Species::WOLF) {};
};

