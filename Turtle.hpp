#pragma once
#include "Animal.hpp"

class Turtle :
    public Animal
{
public:
    virtual Organism& clone() override;
	virtual void action() override;
	bool collision(COORD coordinates) override;
	virtual FightResult attack(Organism& other, bool isAttacked) override;
	using Animal::Animal;
	Turtle(COORD coordinates, World& world) : Animal(2, 1, 0, coordinates, world, Species::TURTLE) {}
};

