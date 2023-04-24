#pragma once
#include "Animal.hpp"
#define FOX_STRENGTH 3
#define FOX_INITIATIVE 7

class Fox :
    public Animal
{
public:
    using Animal::Animal;
    Fox(COORD coordinates, World& world) : Animal(FOX_STRENGTH, FOX_INITIATIVE, DEFAULT_AGE, coordinates, world, Species::FOX) {};
    virtual Organism& clone() override;
    virtual void action(Direction direction) override;
};

