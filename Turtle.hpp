#pragma once
#include "Animal.hpp"

class Turtle :
    public Animal
{
public:
    virtual Organism& clone() override;
	virtual void action() override;
	bool collision(Coordinates& coordinates) override;
	bool attack(Organism& other, bool isAttacked = false);
	using Animal::Animal;
};

