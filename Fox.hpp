#pragma once
#include "Animal.hpp"

class Fox :
    public Animal
{
public:
    using Animal::Animal;
    Fox(COORD coordinates, World& world) : Animal(3, 7, 0, coordinates, world, Species::FOX) {};
    virtual Organism& clone() override;
    virtual void action() override;
};

