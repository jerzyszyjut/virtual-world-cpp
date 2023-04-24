#pragma once
#include "Animal.hpp"

class Human :
    public Animal
{
public:
    virtual Organism& clone() override;
	virtual void action(Direction direction) override;
	using Animal::Animal;
	Human(COORD coordinates, World& world) : Animal(5, 4, 0, coordinates, world, Species::HUMAN) {}
};
