#pragma once
#include "Animal.hpp"
#define ANTILOPINAE_STRENGTH 4
#define ANTILOPINAE_INITIATIVE 4
#define ANTILOPINAE_MOVES 2
#define ANTILOPINAE_DODGE_CHANCE_PERCENT 50

class Antilopinae :
    public Animal
{
public:
    using Animal::Animal;
    Antilopinae(COORD coordinates, World& world) : Animal(ANTILOPINAE_STRENGTH, ANTILOPINAE_STRENGTH, DEFAULT_AGE, coordinates, world, Species::ANTILOPINAE) {};
    virtual Organism& clone() override;
    virtual void action(Direction direction) override;
    virtual bool collision(COORD newCoordinates) override;
};

