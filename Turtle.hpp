#pragma once
#include "Animal.hpp"

class Turtle :
    public Animal
{
public:
    virtual Organism& clone() override;
	virtual std::string action() override;
	bool collision(COORD coordinates) override;
	bool attack(Organism& other, bool isAttacked = false);
	using Animal::Animal;
};

