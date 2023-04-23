#pragma once
#include "Animal.hpp"

class Sheep :
    public Animal
{
public:
    virtual Organism& clone() override;
    using Animal::Animal;
    Sheep(COORD coordinates, World& world) : Animal(4, 4, 0, coordinates, world, Species::SHEEP) {};
};

