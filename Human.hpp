#pragma once
#include "Animal.hpp"
#define HUMAN_STRENGTH 5
#define HUMAN_INITIATIVE 4
#define COOLDOWN 5
#define ABILITY_LENGTH 5
#define DEFAULT_HUMAN_X_COORD 0
#define DEFAULT_HUMAN_Y_COORD 0

class Human :
    public Animal
{
public:
    virtual Organism& clone() override;
	using Animal::Animal;
	Human(COORD coordinates, World& world) : Animal(HUMAN_STRENGTH, HUMAN_INITIATIVE, DEFAULT_AGE, coordinates, world, Species::HUMAN) { m_cooldown = 0; }
	virtual void action(Direction direction) override;
	virtual bool collision(COORD newCoordinates) override;
	int getCooldown();
	void setCooldown(int cooldown);
	void useAbility();

private:
	int m_cooldown;
};

