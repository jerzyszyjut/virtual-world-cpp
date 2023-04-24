#pragma once
#include "Animal.hpp"
#define SHEEP_STRENGTH 4
#define SHEEP_INITIATIVE 4

class Sheep :
    public Animal
{
public:
    virtual Organism& clone() override;
    using Animal::Animal;
    Sheep(COORD coordinates, World& world) : Animal(SHEEP_STRENGTH, SHEEP_INITIATIVE, DEFAULT_AGE, coordinates, world, Species::SHEEP) {};
};

