#pragma once
#include "Animal.hpp"

class Human :
    public Animal
{
public:
    virtual Organism& clone() override;
	using Animal::Animal;
	Human(COORD coordinates, World& world) : Animal(5, 4, 0, coordinates, world, Species::HUMAN) { m_cooldown = 0; }
	virtual void action(Direction direction) override;
	virtual bool collision(COORD newCoordinates) override;
	int getCooldown();
	void setCooldown(int cooldown);
	void useAbility();

private:
	int m_cooldown;
};

