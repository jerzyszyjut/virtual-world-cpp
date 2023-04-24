#pragma once
#include "Animal.hpp"
#define TURTLE_STRENGTH 2
#define TURTLE_INITIATIVE 1
#define TURTLE_MOVE_CHANGE_PERCENT 25
#define TURTLE_DEFENCE_STRENGTH 5

class Turtle :
    public Animal
{
public:
    virtual Organism& clone() override;
	virtual void action(Direction direction) override;
	bool collision(COORD coordinates) override;
	virtual FightResult attack(Organism& other, bool isAttacked) override;
	using Animal::Animal;
	Turtle(COORD coordinates, World& world) : Animal(TURTLE_STRENGTH, TURTLE_INITIATIVE, DEFAULT_AGE, coordinates, world, Species::TURTLE) {}
};

